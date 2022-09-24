# bool extern bug

## compile:
> gcc *.c && ./a.out

## map:
> gcc *.c -Wl,-Map=gcc.map
> cat gcc.map | grep b_a -C 3
> objdump -S a.out | less

## before:
0000000000001192 <main>:
    1192:	f3 0f 1e fa          	endbr64 
    1196:	55                   	push   %rbp
    1197:	48 89 e5             	mov    %rsp,%rbp
    119a:	48 8d 3d 75 0e 00 00 	lea    0xe75(%rip),%rdi        # 2016 <_IO_stdin_used+0x16>
    11a1:	b8 00 00 00 00       	mov    $0x0,%eax
    11a6:	e8 a5 fe ff ff       	callq  1050 <printf@plt>
    11ab:	b8 00 00 00 00       	mov    $0x0,%eax
    11b0:	e8 94 ff ff ff       	callq  1149 <fun_print>
    11b5:	c7 05 51 2e 00 00 00 	movl   $0x0,0x2e51(%rip)        # 4010 <b_a>
    11bc:	00 00 00 
    11bf:	48 8d 3d 58 0e 00 00 	lea    0xe58(%rip),%rdi        # 201e <_IO_stdin_used+0x1e>
    11c6:	b8 00 00 00 00       	mov    $0x0,%eax
    11cb:	e8 80 fe ff ff       	callq  1050 <printf@plt>
    11d0:	b8 00 00 00 00       	mov    $0x0,%eax
    11d5:	e8 6f ff ff ff       	callq  1149 <fun_print>
    11da:	b8 00 00 00 00       	mov    $0x0,%eax
    11df:	5d                   	pop    %rbp
    11e0:	c3                   	retq   
    11e1:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    11e8:	00 00 00 
    11eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

## after
0000000000001192 <main>:
    1192:	f3 0f 1e fa          	endbr64 
    1196:	55                   	push   %rbp
    1197:	48 89 e5             	mov    %rsp,%rbp
    119a:	48 8d 3d 75 0e 00 00 	lea    0xe75(%rip),%rdi        # 2016 <_IO_stdin_used+0x16>
    11a1:	b8 00 00 00 00       	mov    $0x0,%eax
    11a6:	e8 a5 fe ff ff       	callq  1050 <printf@plt>
    11ab:	b8 00 00 00 00       	mov    $0x0,%eax
    11b0:	e8 94 ff ff ff       	callq  1149 <fun_print>
    11b5:	c6 05 54 2e 00 00 00 	movb   $0x0,0x2e54(%rip)        # 4010 <b_a>
    11bc:	48 8d 3d 5b 0e 00 00 	lea    0xe5b(%rip),%rdi        # 201e <_IO_stdin_used+0x1e>
    11c3:	b8 00 00 00 00       	mov    $0x0,%eax
    11c8:	e8 83 fe ff ff       	callq  1050 <printf@plt>
    11cd:	b8 00 00 00 00       	mov    $0x0,%eax
    11d2:	e8 72 ff ff ff       	callq  1149 <fun_print>
    11d7:	b8 00 00 00 00       	mov    $0x0,%eax
    11dc:	5d                   	pop    %rbp
    11dd:	c3                   	retq   
    11de:	66 90                	xchg   %ax,%ax

