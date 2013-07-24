.data 
.PoRcEnToD:
	.string "%d\12\0"
.PoRcEnToS:
	.string "%s\12\0"
___ScarryTeMpORaRy0:
	.value 0
_2:
	.value 2
_3:
	.value 3
__Hello_:
	.string"Hello!"

	.globl  a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	a

	.globl  b
	.data
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	b
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
	movl	$__Hello_, %eax
	movl	$.PoRcEnToS, (%esp)
	call	printf
	leave
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
