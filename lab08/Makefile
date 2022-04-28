CC = gcc
CPPFLAGS = -I../utils
CFLAGS = -Wall -Wextra -g -fno-stack-protector
LDLIBS = -lpthread

.PHONY: all clean

all: thread

thread: thread.o

thread.o: thread.c

clean:
	-rm -f *.o *~ thread
