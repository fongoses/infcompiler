.data 
.PoRcEnToD:
	.string "%d"
.PoRcEnToS:
	.string "%s"
___ScarryTeMpORaRy0:
	.value 0
_0:
	.long 0
_1:
	.long 1
_9:
	.long 9
___ScarryTeMpORaRy3:
	.value 0
__Inicio_____:
	.string "Inicio...\n"
___ScarryTeMpORaRy2:
	.value 0
___ScarryTeMpORaRy1:
	.value 0
____:
	.string "\n"

	.globl  _a
	.data
	.align 4
	.type	_a, @object
	.size	_a, 4
_a:
	.long	0
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
	movl	$__Inicio_____, (%esp)
	call	printf
___label0:
	movl	_a, %edx
	movl	_9, %eax
	cmpl	%eax, %edx
	jge	___label1
	movl	_a, %eax
	movl	%eax, 4(%esp)
	movl	$.PoRcEnToD, (%esp)
	call	printf
	movl	$____, (%esp)
	call	printf
	movl	_a, %edx
	movl	_1, %eax
	addl	%edx, %eax
	movl	%eax, ___ScarryTeMpORaRy3
	movl	___ScarryTeMpORaRy3, %eax
	movl	%eax, _a
	jmp	___label0
___label1:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
