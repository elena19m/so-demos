# Demo for Lab02

## File operations
  * create
  * read/write
  * open/close
  * truncate
  * lseek
  * redirect (dup/dup2)

## File descriptors (fd.c)

## Common mistakes (fileop_sol.c)
  * we forgot to add O_CREAT
  * we forgot to add file permissions for O_CREAT
  * we forgot to add O_TRUNC (if we want to rewrite the file)

## (Bonus) lseek after end of file
