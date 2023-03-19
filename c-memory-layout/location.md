| Variable					| Section 	| Reason	|
--------------------------------------------------------------------------------
| `char a`					| .data		| global initialized variable 	|
| `int b`					| .bss		| global uninitialized variable |
| `char *c`				| .data		| global variable, initialized to a string that is saved in .rodata |
| `"Memory Management Unit"`	| .rodata	| string |
| `static const char e`		| .rodata	| constant variable, initialized 	|
| `int count`					| .bss		| global variable, initialized to 0 |
| `inc -> static int i`		| .bss		| local, but static variable, initialized to 0 |
| `inc -> static int j`		| .data 	| local, but static variable, initialized to 1 |
| `inc -> int k`		| .stack	| local variable |
| `inc  -> const char h[]`	| .stack	| local variable |
| `add -> int res`		| .stack	| local variable |
| `main -> static char f`	| .data		| local, but static variable, initialized to 'F' |
| `main -> char g`		| .stack	| local variable |
| `main -> int *buf`		| .stack	| local varaible |
| `malloc(10 * sizeof(int)`	| .heap		| dynamic allocated variable |
