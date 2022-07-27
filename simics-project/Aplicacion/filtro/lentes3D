 .section .text
#---------------------------------------------------------------
  .globl  lentes3D
lentes3D:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movzbl	2(%rax), %edx
	movq	-8(%rbp), %rax
	movb	%dl, (%rax)
	movq	-8(%rbp), %rax
	addq	$1, %rax
	movzbl	(%rax), %ecx
	movq	-8(%rbp), %rax
	addq	$2, %rax
	movzbl	(%rax), %edx
	movq	-8(%rbp), %rax
	addq	$1, %rax
	subl	%edx, %ecx
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movq	-8(%rbp), %rax
	leaq	2(%rax), %rdx
	movq	-8(%rbp), %rax
	movzbl	1(%rax), %eax
	movb	%al, (%rdx)
	popq	%rbp
	ret
