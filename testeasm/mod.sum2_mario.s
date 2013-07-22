	.file	"sum2.c"
	.globl	a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	37
	.globl	b
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	30
	.text

#inicio da TAC_BEGINF para a funcao 'function()'
	.globl	function
	.type	function, @function
function:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5 #fim da TAC_BEGINF

    #inicio da soma a=3+b
	movl	b, %eax
	addl	$3, %eax
    #fim da soma

	movl	%eax, a #atribuicao de 'a' com o target da soma

	popl	%ebp #saida da funcao (inicio de TAC_ENDF)
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	function, .-function #fim da TAC_ENDF
	

    .globl	main #inicio da TAC_BEGINF da funcao main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5 #Fim da TAC_BEGINF da funcao main

	movl	$3, a #atribuicao a=1+2. Obs.: ele ja gera 3 de 1+2

    #atribuicao a=b+3
	movl	b, %eax #move valor de b para eax 
	addl	$3, %eax #soma 3 com eax 
	movl	%eax, a # move eax para a


	popl	%ebp #Inicio da TAC_ENDF da funcao main
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main #fim da TAC_END_F da funcao main
#	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
#	.section	.note.GNU-stack,"",@progbits    
