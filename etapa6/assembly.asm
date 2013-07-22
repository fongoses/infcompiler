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
  OUTPUT
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
