	.file	"file.c"
	.comm	array,1000,32
	.comm	p1,8,8
	.text
	.globl	abc
	.type	abc, @function
abc:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	abc, .-abc
	.section	.rodata
	.align 8
.LC1:
	.string	"array = %p, &p1 = %p, p1 = %p, &a = %p, &b = %p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$10, -4(%rbp)
	movl	$10000, %edi
	call	malloc@PLT
	movq	%rax, p1(%rip)
	movq	p1(%rip), %rax
	movq	%rax, %rdi
	call	free@PLT
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, -16(%rbp)
	call	abc
	movq	p1(%rip), %rax
	leaq	-16(%rbp), %rcx
	leaq	-4(%rbp), %rdx
	movq	%rcx, %r9
	movq	%rdx, %r8
	movq	%rax, %rcx
	leaq	p1(%rip), %rdx
	leaq	array(%rip), %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	987388755
	.long	1074351192
	.ident	"GCC: (Debian 6.3.0-12) 6.3.0 20170406"
	.section	.note.GNU-stack,"",@progbits
