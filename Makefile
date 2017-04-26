SHELL = /bin/sh
FLAGS = -Wall
CC = g++

all:	echo_s echo_c log_s

echo_s.o: echo_s.c
	$(CC) $(FLAGS) -c echo_s.c

echo_c.o: echo_c.c
	$(CC) $(FLAGS) -c echo_c.c
log_s.o: log_s.c
	$(CC) $(FLAGS) -c log_s.c
	
echo_s_functions.o: echo_s_functions.c echo_s_functions.h
	$(CC) $(FLAGS) -c echo_s_functions.c
	
echo_c_functions.o: echo_c_functions.c echo_c_functions.h
	$(CC) $(FLAGS) -c echo_c_functions.c

echo_s: echo_s.o echo_s_functions.o
	$(CC) -o echo_s echo_s.o echo_s_functions.o
	
echo_c: echo_c.o echo_c_functions.o
	$(CC) -o echo_c echo_c.o echo_c_functions.o
log_s: log_s.o
	$(CC) -o log_s log_s.o

clean:
	rm echo_s echo_c echo_s.o echo_c.o echo_s_functions.o echo_c_functions.o log_s.o log_s
