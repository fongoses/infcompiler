	.file	"vet_call.c"
	.globl	v
	.data
	.align 32
	.type	v, @object
	.size	v, 40
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
	.globl	a
	.bss
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.zero	4
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



### VETCALL a = v[5]; 
### Aparece como v+20 pois cada posição do vetor tem 4 bytes: 4 * 5 = 20
	movl	v+20, %eax
	movl	%eax, a
### Fim do VETCALL



	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.7.3-1ubuntu1) 4.7.3"
	.section	.note.GNU-stack,"",@progbits
