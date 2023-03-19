# Usefull commands when inspecting the C-programs memory layout


Compile the code for this demo using `make`:

```
student@os:~/so-demos/c-memory-layout$ make 
```

Show all available information regarding an ELF file using `readelf`, including:
  - ELF file header information
  - Section headers (.text, .data, .bss, .rodata) and how they are grouped into segments
  - Symbols (both functions and variables).

```
student@os:~/so-demos/c-memory-layout$ readelf -a demo_gestiunea_memoriei
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              DYN (Shared object file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x1080
...
Section Headers:
  [Nr] Name              Type             Address           Offset
  ...
  [16] .text             PROGBITS         0000000000001080  00001080
       0000000000000405  0000000000000000  AX       0     0     16
  [17] .fini             PROGBITS         0000000000001488  00001488
       000000000000000d  0000000000000000  AX       0     0     4
  [18] .rodata           PROGBITS         0000000000002000  00002000
       00000000000000c7  0000000000000000   A       0     0     4
  ...
  [24] .got              PROGBITS         0000000000003fb0  00002fb0
       0000000000000050  0000000000000008  WA       0     0     8
  [25] .data             PROGBITS         0000000000004000  00003000
       0000000000000028  0000000000000000  WA       0     0     8
  [26] .bss              NOBITS           0000000000004028  00003028
       0000000000000018  0000000000000000  WA       0     0     8
  ...
 Section to Segment mapping:
   Segment Sections...
    ...
    03     .init .plt .plt.got .plt.sec .text .fini 
    04     .rodata .eh_frame_hdr .eh_frame 
    05     .init_array .fini_array .dynamic .got .data .bss 
    ...
 Symbol table '.symtab' contains 80 entries:
    Num:    Value          Size Type    Bind   Vis      Ndx 
    ...
    37: 000000000000201c     1 OBJECT  LOCAL  DEFAULT   18 e
    38: 00000000000020be     4 OBJECT  LOCAL  DEFAULT   18 __func__.2841
    39: 0000000000004038     4 OBJECT  LOCAL  DEFAULT   26 i.2838
    40: 0000000000004014     4 OBJECT  LOCAL  DEFAULT   25 j.2839
    41: 00000000000020c2     5 OBJECT  LOCAL  DEFAULT   18 __func__.2852
    42: 0000000000004018     1 OBJECT  LOCAL  DEFAULT   25 f.2849
    ...
    71: 0000000000001080    47 FUNC    GLOBAL DEFAULT   16 _start
    72: 0000000000004020     8 OBJECT  GLOBAL DEFAULT   25 c
    73: 0000000000004010     1 OBJECT  GLOBAL DEFAULT   25 a
    ...

```

Use `man readelf` for more options (e.g., `-l`, `-h`, `-S`).


Show the symbol table using `objdump`:
```
student@os:~/so-demos/c-memory-layout$  objdump -t demo_gestiunea_memoriei
demo_gestiunea_memoriei:     file format elf64-x86-64

SYMBOL TABLE:
...
000000000000201c l     O .rodata	0000000000000001              e
00000000000020be l     O .rodata	0000000000000004              __func__.2841
0000000000004038 l     O .bss	0000000000000004              i.2838
0000000000004014 l     O .data	0000000000000004              j.2839
00000000000020c2 l     O .rodata	0000000000000005              __func__.2852
0000000000004018 l     O .data	0000000000000001              f.2849
...
0000000000004040 g       .bss	0000000000000000              _end
0000000000001080 g     F .text	000000000000002f              _start
0000000000004020 g     O .data	0000000000000008              c
0000000000004010 g     O .data	0000000000000001              a

```

Show the symbol table for a specific section using `objdump`:
```
objdump -t -j .rodata demo_gestiunea_memoriei

demo_gestiunea_memoriei:     file format elf64-x86-64

SYMBOL TABLE:
0000000000002000 l    d  .rodata	0000000000000000              .rodata
000000000000201c l     O .rodata	0000000000000001              e
00000000000020be l     O .rodata	0000000000000004              __func__.2841
00000000000020c2 l     O .rodata	0000000000000005              __func__.2852
000000000000201b g     O .rodata	0000000000000001              d
0000000000002000 g     O .rodata	0000000000000004              _IO_stdin_used

```

# Solution

Check [this file](location.md).
