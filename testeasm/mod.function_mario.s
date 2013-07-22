	.file	"function.c"
	.globl	a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a: #declaracao da var global a
	.long	7
	.globl	b
	.align 4
	.type	b, @object
	.size	b, 4
b: #declaracao da var global b
	.long	13
	.text

#inicio da funcao 'funcao' (comeco da TAC_BEGINF)
	.globl	funcao
	.type	funcao, @function
funcao:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5 # TAC_BEGINF vai ateh aqui
    
    #aqui viriam comandos(etc.) da funcao, mas ela eh vazia.

	popl	%ebp #fim da funcao 'funcao' (aqui ja comeca o TAC_ENDF)
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	funcao, .-funcao #fim da funcao 'funcao' (TAC_ENDF vai ateh aqui)

#inicio da funcao 'main'. comeco da TAC_BEGINF
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5 #TAC_BEGINF vai ateh aqui.

	popl	%ebp #fim da funcao main. Aqui comeca a TAC_ENDF
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main #AQUI termina TAC_ENDF

#inicio da funcao 'outrafuncao'
	.globl	outrafuncao
	.type	outrafuncao, @function
outrafuncao:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5 #TAC_BEGINF vai ateh aqui

    # nao ha codigo nessa funcao.

	popl	%ebp #Inicio da TAC_ENDF
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	outrafuncao, .-outrafuncao #TAC_ENDF vai ateh aqui

#parte abaixo eh inutil
#	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
#	.section	.note.GNU-stack,"",@progbits
