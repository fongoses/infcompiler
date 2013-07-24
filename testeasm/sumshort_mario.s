	.file	"sumshort.c"
	.globl	a
	.data
	.align 2
	.type	a, @object
	.size	a, 2
a:
	.value	5
	#.globl	vetor
	#.type	vetor, @object
	#.size	vetor, 12
vetor:
	.string	"Hello world\12"
	#.globl	ce
	#.type	ce, @object
	#.size	ce, 1
ce:
	.byte	19
	


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
	movw	$3, a
	movl	$vetor, (%esp)
	call	printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
