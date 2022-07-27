 .section .text
#---------------------------------------------------------------
  .globl  black
black:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movzbl	2(%rax), %edx
	movq	-8(%rbp), %rax
	movb	%dl, (%rax)
	movq	-8(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	movq	-8(%rbp), %rax
	leaq	2(%rax), %rdx
	movq	-8(%rbp), %rax
	movzbl	1(%rax), %eax
	movb	%al, (%rdx)
	popq	%rbp
	ret
