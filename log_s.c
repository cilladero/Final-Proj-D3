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
#include <time.h>

//Method to print error message
void error(const char *msg)
{
	perror(msg);
	exit(0);
}

int main(int argc, char *argv[])
{
	//Declare/initialize variables and pointer
	int sock, length, n;
	socklen_t fromlen;
	struct sockaddr_in server;
	struct sockaddr_in from;
	char buf[1024];
	FILE *fp;

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

	//The number in the parentheses is the port number used
	//for the communication between echo_s.c and log_s.c
	server.sin_port=htons(9999);

	//Binding error
	if(bind(sock,(struct sockaddr *)&server,length)<0)
		error("binding");

	fromlen = sizeof(struct sockaddr_in);

	//Loop forever
	while(1)
	{
		//Open file (create child process)
		fp = fopen("echo.log", "a");
		bzero(buf, 256);
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
