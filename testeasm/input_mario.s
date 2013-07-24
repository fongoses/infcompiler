	.file	"input.c"
	.globl	a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	83
	.globl	b
	.type	b, @object
	.size	b, 1
b:
	.byte	54
	.globl	c
	.align 4
	.type	c, @object
	.size	c, 4
c:
	.long	23
	.globl	d
	.align 4
	.type	d, @object
	.size	d, 4
d:
	.long	25
	.section	.rodata
.LC0:
	.string	"%d"
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
	movl	$a, 4(%esp)
	movl	$.LC0, (%esp)
	call	scanf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
.LC1:
	.string	"%c"
	.text
	.globl	funcao
	.type	funcao, @function
funcao:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$b, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	movl	$c, 4(%esp)
	movl	$.LC0, (%esp)
	call	scanf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	funcao, .-funcao
	.globl	outrafuncao
	.type	outrafuncao, @function
outrafuncao:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$d, 4(%esp)
	movl	$.LC0, (%esp)
	call	scanf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	outrafuncao, .-outrafuncao
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
