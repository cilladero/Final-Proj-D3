// Echo Client-Server Readme
// Semester Project Group 8
// Belkoura CS3376.502 
// Authors:	Andre Cordero
//			Blake Grabsky
//			Anthony Inga
//			Layton Lee
//			Briann Ta
//			Daren Wang

// 1. Compilation
// Commands: make
// Description: compiles the files so that they can be run properly

// 2. Running Server
// Commands: echo_s <port1> [<port2> <port3>]
// Description: replies to any client with same message received 
		sends information to the log server (log_s)

// 3. Running Client
// Commands: echo_c <host> <option> <port> (options are -t and -u for tcp/udp)
// Description: connects to the server and sends a message either with tcp or udp

// 4. Log Server
// Commands: log_s
// Description: takes information from echo_s and store it in echo.log

// Contributions
//**************
// Andre Cordero - Separated the server functions 
// Blake Grabsky - Worked on log_s and echo.log and their requirements
// Anthony Inga - Separated functions and finalized code
// Layton Lee - Created Makefile and organized
// Brian Ta - Worked on echo_s and echo_c and their requirements
// Daren Wang - Worked on log_s and echo.log and their requirements
