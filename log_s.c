//log_s.c
/*Creates a datagram server.  The port
number is passed as an argument.  This
server runs forever.*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <arpa/inet.h>

//Method to print error message
void error(const char *msg)
{
	perror(msg);
	exit(0);
}

void SIGINT_handler(int);

int main(int argc, char *argv[])
{
	//Declare/initialize variables and pointer
	int sock, length, n;
	socklen_t fromlen;
	struct sockaddr_in server;
	struct sockaddr_in from;
	char buf[1024];
	FILE *fp;
	
	pid_t pid = getpid();
        key_t MyKey;
        int   ShmID;
        pid_t *ShmPTR;
        MyKey   = ftok(".", 's');     /* create a shared memory segment*/
        ShmID   = shmget(MyKey, sizeof(pid_t), IPC_CREAT | 0666);
        ShmPTR  = (pid_t *) shmat(ShmID, NULL, 0);
        *ShmPTR = pid;
   
        if (signal(SIGINT, SIGINT_handler) == SIG_ERR) {
          printf("SIGINT install error\n");
          exit(1);
        }


	//Error if no arguments
	if(argc < 1)
	{
		fprintf(stderr, "ERROR: argc < 1\n");
		exit(0);
	}

	sock=socket(AF_INET, SOCK_DGRAM, 0);

	//Error opening socket
	if(sock < 0)
		error("Opening socket");
	bzero((char *) &server, sizeof(server));
	length = sizeof(server);
	bzero(&server,length);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;

	//Algorithm used to see if a port number was given as an argument
	//if it was then it would be assigned if not the port number would
	//be set to 9999 as default
	//for the communication between echo_s and log_s
	int i;
	server.sin_port=htons(9999);
	for(i=1; i<argc;i++){
                         if(strcmp(argv[i], "-port") == 0){
                                         server.sin_port=htons(atoi(argv[i+1]));
                         }
         }


	//Binding error
	if(bind(sock,(struct sockaddr *)&server,length)<0)
		error("binding");

	fromlen = sizeof(struct sockaddr_in);

	//Loop forever
	while(1)
	{
		//Open file (create child process)
		fp = fopen("echo.log", "a");
		bzero(buf, 1024);
		n = recvfrom(sock,buf,1024,0,(struct sockaddr *)&from,&fromlen);

		//Receiving error
		if (n < 0)
			error("recvfrom");
		time_t timer;
		char buffer[26];
		struct tm* tm_info;
		time(&timer);
		tm_info = localtime(&timer);


		//Write to file (next 4 lines)
		strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
		fprintf(fp,buffer);
		fprintf(fp,"\t");
		fputs(buf, fp);

		//Close file (end child process)
		fclose(fp);
		n=sendto(sock,buf,strlen(buf),0,(const struct sockaddr *)&from,fromlen);
	}
	return 0;
 }

void  SIGINT_handler(int sig){
     signal(sig, SIG_IGN);
     printf("echo_s is stopping\n");
      FILE *fp1;
      fp1 = fopen("echo.log", "a");
      fprintf(fp1, "echo_s is stopping");
      fprintf(fp1,"\n");
      exit(3);
}

