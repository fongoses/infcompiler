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
