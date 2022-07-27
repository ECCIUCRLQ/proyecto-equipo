 .section .text
#---------------------------------------------------------------
  .globl  negativo

negativo:
  pushq %rbp
  movq  %rsp, %rbp
  movq  %rdi, -8(%rbp)
  movq  -8(%rbp), %rax
  movzbl  (%rax), %eax
  notl  %eax
  movl  %eax, %edx
  movq  -8(%rbp), %rax
  movb  %dl, (%rax)
  movq  -8(%rbp), %rax
  addq  $1, %rax
  movzbl  (%rax), %edx
  movq  -8(%rbp), %rax
  addq  $1, %rax
  notl  %edx
  movb  %dl, (%rax)
  movq  -8(%rbp), %rax
  addq  $2, %rax
  movzbl  (%rax), %edx
  movq  -8(%rbp), %rax
  addq  $2, %rax
  notl  %edx
  movb  %dl, (%rax)
  popq  %rbp
  ret

