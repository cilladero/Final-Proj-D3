//  prototypes for the functions in client_functions.c

#ifndef echo_c_functions_h
#define echo_c_functions_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg);
void argCheck(int args, char *argv0);
void socketCheck(int sockfd, int sockfd2);
void serverCheck(struct hostent *server);
void initServerAddr(struct sockaddr_in serv_addr, struct hostent *server, int portno);
void connectionCheck(int sockfd, struct sockaddr_in serv_addr);
void writeCheck(int n);
void readCheck(int n);

#endif
