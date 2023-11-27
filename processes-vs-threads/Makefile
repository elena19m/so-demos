CC=gcc
CFLAGS=-g
LDLIBS=-lpthread

all: fork threads

fork: fork.o

fork.o: fork.c

threads: threads.o

threads.o: threads.c 

clean:
	rm -f fork threads *.o 
