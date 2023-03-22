# How to run this demo

We compile the code using `make`:
```
student@os:~$ make
gcc    -c -o alloc.o alloc.c
gcc   alloc.o   -o alloc
gcc alloc.c -DMMAP -c -o alloc_mmap.o
gcc alloc_mmap.o -o alloc_mmap
```

We have obtained two executable files:
  - `alloc` - allocates memory using `malloc()`.
  - `alloc_mmap` - allocates memory using `mmap()`.

We will check how these two programs behave when dealing with on demand paging.

For the following tests, we need to use two terminals:
  - in the first one, we will run the executable. The executable has multiple `getchar()` calls so we can better inspect its memory in different running stages.
  - in the second one, we will check the process' mappings.

## Memory allocation using `mmap()`

We start the executable in the first terminal:

```
# First terminal
student@os:~$ ./alloc_mmap
```

In the second terminal, we run the following command. We must run this command after we have started the `alloc_mmap()`
```
# Second terminal
student@os:~$ watch -d pmap -x $(pidof alloc_mmap)
424242:   ./alloc_mmap
Address           Kbytes     RSS   Dirty Mode  Mapping
000056300f7fb000       4       4       0 r---- alloc_mmap
000056300f7fc000       4       4       0 r-x-- alloc_mmap
000056300f7fd000       4       0       0 r---- alloc_mmap
000056300f7fe000       4       4       4 r---- alloc_mmap
000056300f7ff000       4       4       4 rw--- alloc_mmap
00005630116c9000     132       4       4 rw---   [ anon ]
00007fdd5e084000     148     144       0 r---- libc-2.31.so
00007fdd5e0a9000    1504     656       0 r-x-- libc-2.31.so
00007fdd5e221000     296      64       0 r---- libc-2.31.so
00007fdd5e26b000       4       0       0 ----- libc-2.31.so
00007fdd5e26c000      12      12      12 r---- libc-2.31.so
00007fdd5e26f000      12      12      12 rw--- libc-2.31.so
00007fdd5e272000      24      24      24 rw---   [ anon ]
00007fdd5e28d000       4       4       0 r---- ld-2.31.so
00007fdd5e28e000     140     140       0 r-x-- ld-2.31.so
00007fdd5e2b1000      32      32       0 r---- ld-2.31.so
00007fdd5e2ba000       4       4       4 r---- ld-2.31.so
00007fdd5e2bb000       4       4       4 rw--- ld-2.31.so
00007fdd5e2bc000       4       4       4 rw---   [ anon ]
00007ffc1dfc4000     132      16      16 rw---   [ stack ]
00007ffc1dfe9000      12       0       0 r----   [ anon ]
00007ffc1dfec000       4       4       0 r-x--   [ anon ]
ffffffffff600000       4       0       0 --x--   [ anon ]
---------------- ------- ------- -------
total kB            2492    1140      88

```

We can see various mappings such as:
  - `.text` - check the `r-x` permissions from the `alloc_mmap` file mapping.
  - `.heap` - `rw--- [ anon ]` section seems to be the heap.
  - `.stack` - `rw---   [ stack ]`.
  - dynamic library mappings. 

We, then, press `Enter` in the first terminal. Our application will request a mapping for an area of `BYTES` bytes.

```
# First terminal
so@so-vm:~$ ./alloc_mmap\_mmap
        
Will allocate 20000 bytes
Will allocate 5 pages
arr = 0x7efe50d08000

```

And check the second terminal.

```
# Second terminal
Address           Kbytes     RSS   Dirty Mode  Mapping
0000558eae285000       4       4       0 r---- alloc_mmap
0000558eae286000       4       4       0 r-x-- alloc_mmap
0000558eae287000       4       4       0 r---- alloc_mmap
0000558eae288000       4       4       4 r---- alloc_mmap
0000558eae289000       4       4       4 rw--- alloc_mmap
0000558eaf5e3000     132       4       4 rw---   [ anon ]
00007efe50b04000     148     144       0 r---- libc-2.31.so
00007efe50b29000    1504     844       0 r-x-- libc-2.31.so
00007efe50ca1000     296      64       0 r---- libc-2.31.so
00007efe50ceb000       4       0       0 ----- libc-2.31.so
00007efe50cec000      12      12      12 r---- libc-2.31.so
00007efe50cef000      12      12      12 rw--- libc-2.31.so
00007efe50cf2000      24      24      24 rw---   [ anon ]
00007efe50d08000      20       0       0 rw---   [ anon ]
00007efe50d0d000       4       4       0 r---- ld-2.31.so
00007efe50d0e000     140     140       0 r-x-- ld-2.31.so
00007efe50d31000      32      32       0 r---- ld-2.31.so
00007efe50d3a000       4       4       4 r---- ld-2.31.so
00007efe50d3b000       4       4       4 rw--- ld-2.31.so
00007efe50d3c000       4       4       4 rw---   [ anon ]
00007ffffa99b000     132      12      12 rw---   [ stack ]
00007ffffa9d4000      12       0       0 r----   [ anon ]
00007ffffa9d7000       4       4       0 r-x--   [ anon ]
ffffffffff600000       4       0       0 --x--   [ anon ]
---------------- ------- ------- -------
total kB            2512    1328      84
```

We can see that we have another `[ anon ]` mapping, with the size of 20KB (how much we have requested using the `BYTES` macro) that starts from 0x7efe50d08000 and has 0 physical pages assigned (RSS). As we can see, the mapping only reserved the virtual memory pages, but did not allocate them.

We press `Enter` in the first terminal:
```
# First terminal
....
Will access arr[1500] = arr +  6000
```

... And check the changes from the second terminal:
```
# Second terminal
Address           Kbytes     RSS   Dirty Mode  Mapping
0000558eae285000       4       4       0 r---- alloc_mmap
0000558eae286000       4       4       0 r-x-- alloc_mmap
0000558eae287000       4       4       0 r---- alloc_mmap
0000558eae288000       4       4       4 r---- alloc_mmap
0000558eae289000       4       4       4 rw--- alloc_mmap
0000558eaf5e3000     132       4       4 rw---   [ anon ]
00007efe50b04000     148     144       0 r---- libc-2.31.so
00007efe50b29000    1504     844       0 r-x-- libc-2.31.so
00007efe50ca1000     296      64       0 r---- libc-2.31.so
00007efe50ceb000       4       0       0 ----- libc-2.31.so
00007efe50cec000      12      12      12 r---- libc-2.31.so
00007efe50cef000      12      12      12 rw--- libc-2.31.so
00007efe50cf2000      24      24      24 rw---   [ anon ]
00007efe50d08000      20       4       4 rw---   [ anon ]
00007efe50d0d000       4       4       0 r---- ld-2.31.so
00007efe50d0e000     140     140       0 r-x-- ld-2.31.so
00007efe50d31000      32      32       0 r---- ld-2.31.so
00007efe50d3a000       4       4       4 r---- ld-2.31.so
00007efe50d3b000       4       4       4 rw--- ld-2.31.so
00007efe50d3c000       4       4       4 rw---   [ anon ]
00007ffffa99b000     132      12      12 rw---   [ stack ]
00007ffffa9d4000      12       0       0 r----   [ anon ]
00007ffffa9d7000       4       4       0 r-x--   [ anon ]
ffffffffff600000       4       0       0 --x--   [ anon ]
---------------- ------- ------- -------
total kB            2512    1332      88

```

We can see that RSS increased to 4 (1 memory page). When we accessed `arr[1500]` (arr + 1500 * sizeof(int) = arr + 6000) a page fault was generated and our physical page was created.

Thus, we proceed with the application flow, by pressing `Enter` again in the first terminal. We will access `arr[1501]`. We can see that the memory layout does not change. This is because we have already accessed the page that contains the desired address and it is already allocated.


We press `Enter` again.
```
# First terminal
Will access arr[0]
```

```
# Second terminal
Address           Kbytes     RSS   Dirty Mode  Mapping
...
00007efe50d08000      20       8       8 rw---   [ anon ]
...
```

We can see that the RSS increased by 4 which means another page was allocated (arr[0] is the first page from the range we have reserved, whereas arr[1500] is the second page).


We press again `Enter` in the first terminal and check the `pmap`'s output. We can see that another page was allocated when we accessed arr[3000] (arr[3000] = arr + 3000 * sizeof(int) = arr + 12000, the third page from the range we have reserved).

## Memory allocation using `malloc()`

We run the same steps as above, using `alloc` as an executable.

We see that:
  - even though we allocate 20K of memory and malloc will use `mmap()` as a system call, it will allocate, in fact, (5 * 4 + 1) virtual pages.
  - the RSS is already 4 (one physical page is already allocated after calling `malloc()`).
  - the address that `malloc()` returns is not 4K aligned (i.e., it's not at the beginning of a page).
  - accessing `arr[1500]` will allocate a new physical page (RSS increases to 8).
  - accessing `arr[0]` will **not** allocate a new physical page (RSS stays the same).

This behaviour is related to how `malloc` uses its data: even though it calls `mmap()`, it needs additional space to save information about allocated data (such as the length). Moreover, `malloc()` allocates more data than required so that an eventual `realloc()` will be space efficient.

Additional Explainations for `malloc` are [here](https://stackoverflow.com/questions/66828363/why-does-malloc-cause-minor-page-fault).

## Out of bounds

We run `make alloc_out` which generates a new executable file named `alloc_out`.

Then, we run the executable and see that:
  - `arr[5001]` does not generates a segmentation fault error; this happens because `arr + 5001 * sizeof(int)` still points to a valid region.
  - `arr[5121]` generates a segmentation fault error; this happens because `arr + 5121 * sizeof(int)` lands in an unallocated page.


