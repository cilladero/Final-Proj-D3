// Echo Client-Server Readme
// Semester Project Group 8
// Belkoura CS3376.502 
// Authors:	Andre Cordero
//		Blake Grabsky
//		Anthony Inga
//		Layton Lee
//		Brian Ta
//		Daren Wang
// Github Repository: https://github.com/cilladero/Final-Proj-D3

// 1. Compilation
// Command: make
// Description: Compiles the files so that they can be run properly
// Required Files: Makefile echo_c.c echo_c_functions.c echo_c_functions.h
//		   echo_s.c echo_s_functions.c echo_s_functions.h
//		   log_s.c

// 2. Running Server
// Command: echo_s <port1> [<port2> <port3>] [-logip <ip>] [-logport <port>]
// Description: Replies to any client with same message received 
//		Sends information to the log server (log_s)
// Options: up to 3 ports may be specified for server to listen on
//	    -logip specifies ip of log_s
//	    -logport specifies port of log_s

// 3. Running Client
// Command: echo_c <host_addr> [-t or -u] <port>
// Description: Connects to the server and sends a message either with
//		tcp or udp
// Options: -t specifies TCP connection
//	    -u specifies UDP connection

// 4. Running Log Server
// Command: log_s [-port <port>]
// Description: Takes information from echo_s and stores it in echo.log
// Options: -port specifies port number to connect to


// Contributions
//**************
// Andre Cordero - Modifications to echo_s to allow for specification of
//		   log_s IP
// Blake Grabsky - Modifications to echo_s to allow for specification of
//		   log_s port number
// Anthony Inga - Modifications to log_s to allow for specification of of
//		  log_s port number
// Layton Lee - Modifications to echo_s and log_s for echo_s to send
//		termination signal to log_s when echo_s is stopped with CTRL+C
// Brian Ta - Modifications to log_s to log termination message from echo_s
//	      Various assistance
// Daren Wang - Code finalization and Readme write-up
//		Various assistance
