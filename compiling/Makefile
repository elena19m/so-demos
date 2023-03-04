CC=gcc

build: test

test.i: test.c
	gcc -E test.c -o test.i

test.s: test.c
	gcc -S test.c -o test.s

test.o: test.c
	gcc -c test.c -o test.o

test: test.c
	gcc test.c -o test

main.i: main.c
	gcc -E main.c -o main.i

main.s: main.c
	gcc -S main.c -o main.s

main.o: main.c
	gcc -c main.c -o main.o

main: main.c
	gcc main.c -o main

main2: main2.c
	gcc main2.c -o main2

clean:
	rm -f test test.i test.o test.s add main main.i main.o main.s main2
