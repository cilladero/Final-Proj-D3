//echo_c_functions.c
//Contains functions to communicate with server

#include "echo_c_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

using namespace std;

//Displays error message
void error(const char *msg)
{
	perror(msg);
	exit(0);
}

//Checks that program has passed an appropriate amount of arguments.
//Displays error with proper execution command and terminates program.
void argCheck(int args, char *argv0)
{
	if (args < 4)
	{
    fprintf(stderr,"usage %s hostname option port\n", argv0);
    exit(0);
  }
}

//Checks that socket file descriptor was successfully assigned.
void socketCheck(int sockfd, int sockfd2)
{
	if (sockfd < 0)
    error("ERROR opening socket");
	if (sockfd2 < 0)
		error("ERROR opening socket");
}

//Checks that server information was successfully obtained.
void serverCheck(struct hostent *server)
{
	if (server == NULL)
	{
    fprintf(stderr,"ERROR, no such host\n");
    exit(0);
  }
}

//Initializes server address structure.
void initServerAddr(struct sockaddr_in serv_addr, struct hostent *server, int portno)
{
	bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

}

//Checks that connection was made to server
void connectionCheck(int sockfd, struct sockaddr_in serv_addr)
{
	if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");
}

//Checks that write() executed successfully
void writeCheck(int n)
{
	if (n < 0)
         error("ERROR writing to socket");
}

//Checks that read() executed successfully
void readCheck(int n)
{
	if (n < 0)
         error("ERROR reading from socket");
}
