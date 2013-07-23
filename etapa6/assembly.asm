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

   .globl main
   .type  main, @function
main:
.LFB0
   .cfi_startproc
   pushl   %ebp
   .cfi_def_cfa_offset 8
   .cfi_offset 5, -8
   movl    %esp, %ebp
   .cfi_def_cfa_register 5
  OUTPUT
  SOMA
  OUTPUT
  OUTPUT
   popl    %ebp
   .cfi_restore 5
   .cfi_def_cfa 4, 4
   ret
   .cfi_endproc
.LFE0:
   .size   main, .-main
