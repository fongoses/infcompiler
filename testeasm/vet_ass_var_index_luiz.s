	.file	"vet_ass_var_index.c"
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
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	20
	.globl	i
	.align 4
	.type	i, @object
	.size	i, 4
i:
	.long	5
	.globl	w
	.type	w, @object
	.size	w, 10
w:
	.byte	1
	.byte	2
	.byte	3
	.byte	4
	.byte	5
	.byte	6
	.byte	7
	.byte	8
	.byte	9
	.byte	10
	.globl	b
	.type	b, @object
	.size	b, 1
b:
	.byte	20
	.globl	j
	.type	j, @object
	.size	j, 1
j:
	.byte	5
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



.L2:
### v[i] = a usando int
	movl	i, %eax
	movl	a, %edx
	movl	%edx, v(,%eax,4)



.L3:
### w[j] = b usando byte
	movzbl	j, %eax
	movsbl	%al, %eax
	movzbl	b, %edx
	movb	%dl, w(%eax)



.L4:
### v[j] = a vetor de int com indice byte
	movzbl	j, %eax
	movsbl	%al, %eax
	movl	a, %edx
	movl	%edx, v(,%eax,4)



.L5:
### w[i] = b vetor de byte com indice int
	movl	a, %eax
	movzbl	b, %edx
	movb	%dl, w(%eax)




	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
