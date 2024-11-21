CC=gcc
CFLAGS=-g
LDLIBS=-lpthread

all: fork fork_time fork_memory threads threads_time orphan zombie while

threads: threads.o

threads.o: threads.c

threads_time: threads_time.o

threads_time.o: threads_time.c

fork: fork.o

fork.o: fork.c

fork_time: fork_time.o

fork_time.o: fork_time.c

fork_memory: fork_memory.o

fork_memory.o: fork_memory.c

orphan: orphan.o

orphan.o: orphan.c

while: while.o

while.o: while.c

zombie: zombie.o

zombie.o: zombie.c

clean_o:
	rm -rf *.o

clean:
	rm -f fork fork_time fork_memory threads threads_time orphan zombie while  *.o
