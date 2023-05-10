CC = gcc
CPPFLAGS = -I../utils
CFLAGS = -Wall -Wextra -g -fno-stack-protector
LDLIBS = -lpthread

.PHONY: all clean

all: thread_m1 thread_m2 thread_nosync

thread_m1: thread_m1.o

thread_m1.o: thread_m1.c

thread_m2: thread_m2.o

thread_m2.o: thread_m2.c

thread_nosync: thread_nosync.o

thread_nosync.o: thread_nosync.c

clean:
	-rm -f *.o *~ thread_m1 thread_m2 thread_nosync
