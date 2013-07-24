	.file	"vec_dec_inicializado.c"
	.globl	v
	.data
	.align 32



### opcional, declarar o tipo do vetor antes
	.type	v, @object
	.size	v, 40

### Declaração de Vetor Inicializado: v[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
v:
	.long	1
	.long	2
	.long	3
	.long	4
	.long	5
	.long	6
	.long	7
	.long	8
	.long	9
	.long	10
### Fim Declaração de vetor inicializado



	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.7.3-1ubuntu1) 4.7.3"
	.section	.note.GNU-stack,"",@progbits
