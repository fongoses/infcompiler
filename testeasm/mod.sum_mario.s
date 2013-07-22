	.file	"sum.c"
	.globl	a #diz que 'a' eh global
	.data
	.align 4
	.type	a, @object #object indica que 'a' eh uma var
	.size	a, 4 #tamanho da var: 4 bytes.

#declaracao de var
a:
	.long	37  #inicializacao com valor 37
	.text       #volta para secao .text

   
#'pre-inicio da main'
	.globl	main #diz que main eh um simbolo global
	.type	main, @function #diz que simbolo 'main' eh uma funcao


#inicio da main
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5 #fim do setup da main
   
	movl	$3, a  #Soma. Obs.: ele ja transforma 1+2 em 3

	popl	%ebp  #saida/end da main
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc 
.LFE0:
	.size	main, .-main #end da main
