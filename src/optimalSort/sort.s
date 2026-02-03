	.file	"sort.c"
	.text
	.globl	quickSort
	.type	quickSort, @function
quickSort:
.LFB0:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	movq	%rdi, %rbp
	movl	%esi, %r10d
	movl	%edx, %r12d
	leal	(%rsi,%rdx), %edx
	movl	%edx, %eax
	shrl	$31, %eax
	addl	%edx, %eax
	sarl	%eax
	cltq
	movl	(%rdi,%rax,4), %esi
	movl	%r12d, %edx
	movl	%r10d, %ebx
	leaq	4(%rdi), %r9
	leaq	-4(%rdi), %r11
	jmp	.L6
.L13:
	movl	%edi, (%r8)
	movl	%ecx, 0(%r13)
	addl	$1, %ebx
	subl	$1, %edx
	jmp	.L6
.L7:
	cmpl	%r10d, %edx
	jg	.L20
.L10:
	cmpl	%r12d, %ebx
	jl	.L21
.L1:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L20:
	.cfi_restore_state
	movl	%r10d, %esi
	movq	%rbp, %rdi
	call	quickSort
	jmp	.L10
.L21:
	movl	%r12d, %edx
	movl	%ebx, %esi
	movq	%rbp, %rdi
	call	quickSort
	jmp	.L1
.L22:
	movslq	%edx, %rax
	leaq	0(%rbp,%rax,4), %r13
	movl	0(%r13), %edi
	cmpl	%edi, %esi
	jge	.L13
.L12:
	movslq	%edx, %rax
	leaq	(%r11,%rax,4), %rax
	.p2align 5
.L5:
	subl	$1, %edx
	movq	%rax, %r13
	subq	$4, %rax
	movl	4(%rax), %edi
	cmpl	%esi, %edi
	jg	.L5
.L4:
	cmpl	%ebx, %edx
	jge	.L13
.L6:
	cmpl	%edx, %ebx
	jg	.L7
	movslq	%ebx, %rax
	salq	$2, %rax
	leaq	0(%rbp,%rax), %r8
	movl	(%r8), %ecx
	addq	%r9, %rax
	cmpl	%ecx, %esi
	jle	.L22
	.p2align 5
.L3:
	addl	$1, %ebx
	movq	%rax, %r8
	addq	$4, %rax
	movl	-4(%rax), %ecx
	cmpl	%esi, %ecx
	jl	.L3
	movslq	%edx, %rax
	leaq	0(%rbp,%rax,4), %r13
	movl	0(%r13), %edi
	cmpl	%edi, %esi
	jl	.L12
	jmp	.L4
	.cfi_endproc
.LFE0:
	.size	quickSort, .-quickSort
	.ident	"GCC: (GNU) 15.2.1 20251112"
	.section	.note.GNU-stack,"",@progbits
