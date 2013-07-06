#Codigo comentado eh inutil

	.file	"ted.c"
	.globl	a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	9
	.section	.rodata
.LC0:
	.string	"%d\n"
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
	andl	$-16, %esp
	subl	$16, %esp
	movl	a, %eax
	addl	$2, %eax
	movl	%eax, a
	movl	a, %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
#.LFE0:
#	.size	main, .-main
#	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
#	.section	.note.GNU-stack,"",@progbits
