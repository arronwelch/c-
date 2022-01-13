	.file	"TicketMachine.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.text
	.align 2
	.globl	_ZN13TicketMachineC2Ev
	.type	_ZN13TicketMachineC2Ev, @function
_ZN13TicketMachineC2Ev:
.LFB1523:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	leaq	16+_ZTV13TicketMachine(%rip), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movl	$0, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1523:
	.size	_ZN13TicketMachineC2Ev, .-_ZN13TicketMachineC2Ev
	.globl	_ZN13TicketMachineC1Ev
	.set	_ZN13TicketMachineC1Ev,_ZN13TicketMachineC2Ev
	.align 2
	.globl	_ZN13TicketMachineD2Ev
	.type	_ZN13TicketMachineD2Ev, @function
_ZN13TicketMachineD2Ev:
.LFB1526:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	leaq	16+_ZTV13TicketMachine(%rip), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1526:
	.size	_ZN13TicketMachineD2Ev, .-_ZN13TicketMachineD2Ev
	.globl	_ZN13TicketMachineD1Ev
	.set	_ZN13TicketMachineD1Ev,_ZN13TicketMachineD2Ev
	.align 2
	.globl	_ZN13TicketMachineD0Ev
	.type	_ZN13TicketMachineD0Ev, @function
_ZN13TicketMachineD0Ev:
.LFB1528:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN13TicketMachineD1Ev
	movq	-8(%rbp), %rax
	movl	$24, %esi
	movq	%rax, %rdi
	call	_ZdlPvm@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1528:
	.size	_ZN13TicketMachineD0Ev, .-_ZN13TicketMachineD0Ev
	.section	.rodata
.LC0:
	.string	"something"
	.text
	.align 2
	.globl	_ZN13TicketMachine10showPromptEv
	.type	_ZN13TicketMachine10showPromptEv, @function
_ZN13TicketMachine10showPromptEv:
.LFB1529:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1529:
	.size	_ZN13TicketMachine10showPromptEv, .-_ZN13TicketMachine10showPromptEv
	.align 2
	.globl	_ZN13TicketMachine11insertMoneyEi
	.type	_ZN13TicketMachine11insertMoneyEi, @function
_ZN13TicketMachine11insertMoneyEi:
.LFB1530:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	12(%rax), %edx
	movl	-12(%rbp), %eax
	addl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, 12(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1530:
	.size	_ZN13TicketMachine11insertMoneyEi, .-_ZN13TicketMachine11insertMoneyEi
	.align 2
	.globl	_ZN13TicketMachine11showBalanceEv
	.type	_ZN13TicketMachine11showBalanceEv, @function
_ZN13TicketMachine11showBalanceEv:
.LFB1531:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEi@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1531:
	.size	_ZN13TicketMachine11showBalanceEv, .-_ZN13TicketMachine11showBalanceEv
	.weak	_ZTV13TicketMachine
	.section	.data.rel.ro.local._ZTV13TicketMachine,"awG",@progbits,_ZTV13TicketMachine,comdat
	.align 8
	.type	_ZTV13TicketMachine, @object
	.size	_ZTV13TicketMachine, 32
_ZTV13TicketMachine:
	.quad	0
	.quad	_ZTI13TicketMachine
	.quad	_ZN13TicketMachineD1Ev
	.quad	_ZN13TicketMachineD0Ev
	.weak	_ZTI13TicketMachine
	.section	.data.rel.ro._ZTI13TicketMachine,"awG",@progbits,_ZTI13TicketMachine,comdat
	.align 8
	.type	_ZTI13TicketMachine, @object
	.size	_ZTI13TicketMachine, 16
_ZTI13TicketMachine:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS13TicketMachine
	.weak	_ZTS13TicketMachine
	.section	.rodata._ZTS13TicketMachine,"aG",@progbits,_ZTS13TicketMachine,comdat
	.align 16
	.type	_ZTS13TicketMachine, @object
	.size	_ZTS13TicketMachine, 16
_ZTS13TicketMachine:
	.string	"13TicketMachine"
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2015:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L9
	cmpl	$65535, -8(%rbp)
	jne	.L9
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L9:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2015:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__ZN13TicketMachineC2Ev, @function
_GLOBAL__sub_I__ZN13TicketMachineC2Ev:
.LFB2016:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2016:
	.size	_GLOBAL__sub_I__ZN13TicketMachineC2Ev, .-_GLOBAL__sub_I__ZN13TicketMachineC2Ev
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__ZN13TicketMachineC2Ev
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
