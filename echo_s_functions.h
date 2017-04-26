//  prototypes for the functions in server_functions.c

#ifndef echo_s_functions_h
#define echo_s_functions_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg);
void chkArgument(int argc, char *argv0);
void chkSock(int sockfd, int sockfd2);
void chkBind(int sockfd, struct sockaddr_in serv_addr, int sockfd2, int length);
void chkBind1(int sockfd, struct sockaddr_in serv_addr);
void chkBind2(int sockfd, struct sockaddr_in serv_addr, int length);
//void dostuff (int sock, struct sockaddr_in cli_addr, socklen_t clilen, int sock2, int sock3, struct sockaddr_in log_addr);
void dostuffudp(struct sockaddr_in cli_addr, socklen_t clilen, int sock2, int sock3, struct sockaddr_in log_addr);
void dostufftcp(int sock, int sock3, struct sockaddr_in log_addr, struct sockaddr_in cli_addr);


#endif
