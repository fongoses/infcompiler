.data 
.PoRcEnToD:
	.string "%d"
.PoRcEnToS:
	.string "%s"
___ScarryTeMpORaRy0:
	.value 0
_9:
	.value 9
___label0:
	.value 0
__Digite_um_valor_maior_que_9___:
	.string "Digite um valor maior que 9:\n"
___ScarryTeMpORaRy3:
	.value 0
_10:
	.value 10
__Voce_ganhou_:
	.string "Voce ganhou!"
___label1:
	.value 0
___ScarryTeMpORaRy2:
	.value 0
__Voce_perdeu__Seu_valor_eh_menor_que__:
	.string "Voce perdeu! Seu valor eh menor que 9"
___ScarryTeMpORaRy1:
	.value 0

	.globl  _a
	.data
	.align 4
	.type	_a, @object
	.size	_a, 4
_a:
	.long	10

	.globl  _b
	.data
	.align 4
	.type	_b, @object
	.size	_b, 4
_b:
	.long	9
	.text
	.globl main
	.type  main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
 	.cfi_def_cfa_register 5
	andl    $-16, %esp
	subl    $16, %esp
	movl	$__Digite_um_valor_maior_que_9___, (%esp)
	call	printf
	andl	$-16, %esp
	subl	$16, %esp
	movl	$_a, 4(%esp)
	movl	$.PoRcEnToD, (%esp)
	call	scanf
	movl	_a, %edx
	movl	_9, %eax
	cmpl	%eax, %edx
	jle	___label0
	movl	$__Voce_ganhou_, (%esp)
	call	printf
	jmp	___label1
	movl	$__Voce_perdeu__Seu_valor_eh_menor_que__, (%esp)
	call	printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
