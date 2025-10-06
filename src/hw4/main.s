.file	"main.c"
	.text
	.globl	bsort
	.type	bsort, @function
bsort:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -8(%rbp)
	nop
	movl	-28(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -8(%rbp)
	jge	.L7
	movl	$0, -16(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L3
.L5:
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-12(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jle	.L4
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movl	-12(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	-24(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	movl	-12(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	movl	%eax, (%rdx)
	movl	$1, -16(%rbp)
.L4:
	addl	$1, -12(%rbp)
.L3:
	movl	-28(%rbp), %eax
	subl	-8(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -12(%rbp)
	jl	.L5
	cmpl	$0, -16(%rbp)
	je	.L10
	movl	-16(%rbp), %eax
	jmp	.L1
.L10:
	nop
.L7:
.L1:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	bsort, .-bsort
	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$448, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -428(%rbp)
	jmp	.L12
.L15:
	movl	-428(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -428(%rbp)
	movl	-432(%rbp), %edx
	cltq
	movl	%edx, -416(%rbp,%rax,4)
	call	getchar@PLT
	movb	%al, -433(%rbp)
	cmpb	$10, -433(%rbp)
	je	.L21
	movq	stdin(%rip), %rdx
	movsbl	-433(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	ungetc@PLT
.L12:
	cmpl	$99, -428(%rbp)
	jg	.L14
	leaq	-432(%rbp), %rax
	leaq	.LC0(%rip), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	__isoc23_scanf@PLT
	cmpl	$1, %eax
	je	.L15
	jmp	.L14
.L21:
	nop
.L14:
	movl	-428(%rbp), %edx
	leaq	-416(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	bsort
	movl	%eax, -420(%rbp)
	movl	$0, -424(%rbp)
	jmp	.L16
.L18:
	cmpl	$0, -424(%rbp)
	jle	.L17
	movl	$32, %edi
	call	putchar@PLT
.L17:
	movl	-424(%rbp), %eax
	cltq
	movl	-416(%rbp,%rax,4), %eax
	leaq	.LC0(%rip), %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -424(%rbp)
.L16:
	movl	-424(%rbp), %eax
	cmpl	-428(%rbp), %eax
	jl	.L18
	movl	$10, %edi
	call	putchar@PLT
	movl	-420(%rbp), %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L20
	call	__stack_chk_fail@PLT
.L20:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 15.2.1 20250813"
	.section	.note.GNU-stack,"",@progbits