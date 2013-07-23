   .globl  a
   .data
   .align 4
   .type   a, @object
   .size   a, 4
a:
   .long   a

   .globl  x
   .data
   .align 4
   .type   x, @object
   .size   x, 1
x:
   .long   x

   .globl  i
   .data
   .align 4
   .type   i, @object
   .size   i, 4
i:
   .long   i

   .globl  a
   .data
   .align 4
   .type   a, @object
   .size   a, 4
a:
   .long   a

   .globl  b
   .data
   .align 4
   .type   b, @object
   .size   b, 4
b:
   .long   b

   .globl f
   .type  f, @function
f:
.LFB0
   .cfi_startproc
   pushl   %ebp
   .cfi_def_cfa_offset 8
   .cfi_offset 5, -8
   movl    %esp, %ebp
   .cfi_def_cfa_register 5
   popl    %ebp
   .cfi_restore 5
   .cfi_def_cfa 4, 4
   ret
   .cfi_endproc
.LFE0:
   .size   f, .-f
   .globl main
   .type  main, @function
main:
.LFB1
   .cfi_startproc
   pushl   %ebp
   .cfi_def_cfa_offset 8
   .cfi_offset 5, -8
   movl    %esp, %ebp
   .cfi_def_cfa_register 5
   .globl  a
   .data
   .align 4
   .type   a, @object
   .size   a, 4
a:
   .long   a

  OUTPUT
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  OUTPUT
  SOMA
   popl    %ebp
   .cfi_restore 5
   .cfi_def_cfa 4, 4
   ret
   .cfi_endproc
.LFE1:
   .size   main, .-main
