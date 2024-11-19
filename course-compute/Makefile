CC=gcc
CFLAGS=-g
LDLIBS=-lpthread

all: fork threads threads_time fork_time

fork: fork.o

fork.o: fork.c

threads: threads.o

threads.o: threads.c

threads_time: threads_time.o

threads_time.o: threads_time.c

fork_time: fork_time.o

fork_time.o: fork_time.c

clean:
	rm -f fork fork_time threads threads_time *.o
