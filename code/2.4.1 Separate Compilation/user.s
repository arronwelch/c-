	.file	"user.cpp"
	.text
	.globl	_Z8sqrt_sumR6Vector
	.type	_Z8sqrt_sumR6Vector, @function
_Z8sqrt_sumR6Vector:
.LFB246:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -8(%rbp)
	movl	$0, -12(%rbp)
.L3:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN6Vector4sizeEv@PLT
	cmpl	%eax, -12(%rbp)
	setne	%al
	testb	%al, %al
	je	.L2
	movl	-12(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN6VectorixEi@PLT
	movq	(%rax), %rax
	movq	%rax, %xmm0
	call	sqrt@PLT
	movsd	-8(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	addl	$1, -12(%rbp)
	jmp	.L3
.L2:
	movsd	-8(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE246:
	.size	_Z8sqrt_sumR6Vector, .-_Z8sqrt_sumR6Vector
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
