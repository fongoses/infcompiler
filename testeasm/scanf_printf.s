    .file   "input_simples.c"
    .globl  a
    .data
    .align 4
    .type   a, @object
    .size   a, 4
a:
    .long   10
    .section    .rodata
.LC0:
    .string "%d"

.LC1:
    .string "Variavel a = %d\n"

.LC1_enxerto:
    .string "Variavel a = %d de novo\n"

    .text
    .globl  main
    .type   main, @function
main:
.LFB0:
    .cfi_startproc
    pushl   %ebp
    .cfi_def_cfa_offset 8
    .cfi_offset 5, -8
    movl    %esp, %ebp
    .cfi_def_cfa_register 5

    andl    $-16, %esp
    subl    $16, %esp
    movl    $a, 4(%esp)
    movl    $.LC0, (%esp)
    call    scanf

    movl    a, %eax
    movl    %eax, 4(%esp)
    movl    $.LC1, (%esp)
    call    printf

### scanf(LC0, &a); o LC0 contém o "%d"
    andl    $-16, %esp
    subl    $16, %esp
    movl    $a, 4(%esp)
    movl    $.LC0, (%esp)
    call    scanf

### printf(LC1_enxerto, a);
    movl    a, %eax                     # Variável a ser impressa 'a' (que também é um label)
    movl    %eax, 4(%esp)               # Coloca %eax na pilha %esp, eax tem 32bits ou 4 bytes 
    movl    $.LC1_enxerto, (%esp)       # Pega o endereço da string (essa string tem %d) e coloca na pilha %esp
    call    printf                      # Chama printf

    leave
    .cfi_restore 5
    .cfi_def_cfa 4, 4
    ret
    .cfi_endproc
.LFE0:
    .size   main, .-main
    .ident  "GCC: (Ubuntu/Linaro 4.7.3-1ubuntu1) 4.7.3"
    .section    .note.GNU-stack,"",@progbits
