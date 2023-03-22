CC=gcc

all: alloc alloc_mmap

alloc: alloc.o

alloc_mmap: alloc_mmap.o
	gcc $^ -o $@

alloc.o: alloc.c

alloc_mmap.o: alloc.c
	gcc $^ -DMMAP -c -o $@

alloc_out: alloc_out.o

alloc_out.o: alloc.c
	gcc $^ -DMMAP -DOUT_OF_BOUNDS -c -o $@

clean:
	rm -f *.o alloc alloc_mmap alloc_out
