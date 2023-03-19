
| Variable					| Section 	| Reason	|
|:-----------------:|:---------:|:--------:|
| `char a`					| `.data`		| global initialized variable 	|
| `int b`				    | `.bss`		| global uninitialized variable |
| `char *c`				  | `.data`		| global variable, initialized to a string that is saved in .rodata |
| `"Memory Management Unit"`	| `.rodata`	| string |
| `static const char e`		| `.rodata`	| constant variable, initialized 	|
| `int count`			  | `.bss`		| global variable, initialized to 0 |
| `inc -> static int i`		| `.bss`		| local, but static variable, initialized to 0 |
| `inc -> static int j`		| `.data` 	| local, but static variable, initialized to 1 |
| `inc -> int k`		      | `.stack`	| local variable |
| `inc  -> const char h[]`| `.stack`	| local variable |
| `add -> int res`		    | `.stack`	| local variable |
| `main -> static char f`	| `.data`		| local, but static variable, initialized to 'F' |
| `main -> char g`		    | `.stack`	| local variable |
| `main -> int *buf`		  | `.stack`	| local varaible |
| `malloc(10 * sizeof(int)`	| `.heap`		| dynamic allocated variable |


How to check:
  - `objdump -t demo_gestiunea_memoriei`
  - Compile the code with debug symbols `-g`
```
student@os:~/so-demos/c-memory-layout$ gdb ./demo_gestiunea_memoriei
...
Reading symbols from ./demo_gestiunea_memoriei...
(gdb) b main
Breakpoint 1 at 0x126a: file demo_gestiunea_memoriei.c, line 48.
(gdb) run
...
Breakpoint 1, main () at demo_gestiunea_memoriei.c:48
48	int main() {
(gdb) info locals
f = 70 'F'
g = 0 '\000'
buf = 0x0
__func__ = "main"

```
   - hex-dump the content of `.rodata` section:
```
student@so:~/so-demos/c-memory-layout$ readelf -x .rodata demo_gestiunea_memoriei

Hex dump of section '.rodata':
  0x00002000 01000200 4d656d6f 7279204d 616e6167 ....Memory Manag
  0x00002010 656d656e 7420556e 69740044 4525733a ement Unit.DE%s:
  0x00002020 2043616c 6c206e75 6d626572 203d2025  Call number = %
  0x00002030 640a0025 733a2069 203d2025 640a0025 d..%s: i = %d..%
  0x00002040 733a206a 203d2025 640a0025 733a206b s: j = %d..%s: k
  0x00002050 203d2025 640a0025 733a2061 203d2025  = %d..%s: a = %
  0x00002060 630a0025 733a2062 203d2025 640a0025 c..%s: b = %d..%
  0x00002070 733a2063 203d2025 730a0025 733a2064 s: c = %s..%s: d
  0x00002080 203d2025 630a0025 733a2065 203d2025  = %c..%s: e = %
  0x00002090 630a0025 733a2066 203d2025 630a0025 c..%s: f = %c..%
  0x000020a0 733a2067 203d2025 630a0025 733a2062 s: g = %c..%s: b
  0x000020b0 75665b31 30305d20 3d202564 0a00696e uf[100] = %d..in
  0x000020c0 63006d61 696e00                     c.main.

```
