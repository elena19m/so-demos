CC = gcc
CPPFLAGS = -I../utils
CFLAGS = -Wall -Wextra -g
LDLIBS = -lpthread

.PHONY: all clean

all: thread_m1 thread_m2 thread_nosync thread_spinlock1 thread_spinlock2 thread_vars

thread_m1: thread_m1.o

thread_m1.o: thread_m1.c

thread_m2: thread_m2.o

thread_m2.o: thread_m2.c

thread_nosync: thread_nosync.o

thread_nosync.o: thread_nosync.c

thread_vars: thread_vars.o

thread_vars.o: thread_vars.c

thread_spinlock1: thread_spinlock1.o

thread_spinlock1.o: thread_spinlock1.c

thread_spinlock2: thread_spinlock2.o

thread_spinlock2.o: thread_spinlock2.c

clean:
	-rm -f *.o *~ thread_nosync thread_vars thread_*1 thread_*2
