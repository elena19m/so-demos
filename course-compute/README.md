Demos for the Computing chapter:
- `ps aux` - check the STAT column (`man ps`).
- `fork.c` - basic example of the fork call.
- `threads.c` - basic example threads. Check process address space (with `pmap` to see new stacks being created for each new thread).
- `fork_time.c` and `threads_time.c` - check process vs thread creation time.
- `orphan.c` - create an orphan process using `fork()`.
- `zombie.c` - create a zombie process using `fork()`. Check the state of the zombie process using `ps` (search for `<defunct>` processes).
- `while.c` - CPU-intensive task. Check context switches (voluntary vs involuntary) using `/usr/bin/time -v`.
-  `cat -` - IO-intensive task. Check context switches (voluntary vs involuntary) using `/usr/bin/time -v`.
-  threads & synchronization demos using MUTEX and SPINLOCK - the demo code can be found in the [threads](threads) directory.
