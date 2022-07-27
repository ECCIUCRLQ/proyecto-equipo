 .section .text
#---------------------------------------------------------------
  .globl  serpia
serpia:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	shrb	$2, %al
	movl	%eax, %esi
	movq	-24(%rbp), %rax
	addq	$2, %rax
	movzbl	(%rax), %ecx
	movzbl	%cl, %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	shrw	$8, %ax
	subl	%eax, %ecx
	movl	%ecx, %edx
	shrb	%dl
	addl	%edx, %eax
	shrb	$2, %al
	leal	(%rsi,%rax), %edx
	movq	-24(%rbp), %rax
	addq	$1, %rax
	movzbl	(%rax), %eax
	shrb	%al
	addl	%edx, %eax
	movb	%al, -3(%rbp)
	movq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	movzbl	%al, %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	0(,%rax,8), %edx
	addl	%edx, %eax
	shrw	$8, %ax
	movl	%eax, %ecx
	shrb	%cl
	movq	-24(%rbp), %rax
	addq	$2, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	0(,%rax,8), %edx
	addl	%edx, %eax
	shrw	$8, %ax
	shrb	$2, %al
	leal	(%rcx,%rax), %edx
	movq	-24(%rbp), %rax
	addq	$1, %rax
	movzbl	(%rax), %eax
	shrb	%al
	addl	%edx, %eax
	movb	%al, -2(%rbp)
	movq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	shrb	%al
	movl	%eax, %ecx
	movq	-24(%rbp), %rax
	addq	$2, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	leal	0(,%rax,4), %edx
	addl	%edx, %eax
	shrw	$8, %ax
	shrb	$2, %al
	addl	%eax, %ecx
	movq	-24(%rbp), %rax
	addq	$1, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	leal	0(,%rax,4), %edx
	addl	%edx, %eax
	shrw	$8, %ax
	shrb	$3, %al
	addl	%ecx, %eax
	movb	%al, -1(%rbp)
	movq	-24(%rbp), %rax
	movzbl	-3(%rbp), %edx
	movb	%dl, (%rax)
	movq	-24(%rbp), %rax
	leaq	1(%rax), %rdx
	movzbl	-2(%rbp), %eax
	movb	%al, (%rdx)
	movq	-24(%rbp), %rax
	leaq	2(%rax), %rdx
	movzbl	-1(%rbp), %eax
	movb	%al, (%rdx)
	popq	%rbp
	ret
