	.file	"vet_call_var_index_byte.c"
	.globl	v
	.data
	.type	v, @object
	.size	v, 10
v:
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
	.globl	a
	.bss
	.type	a, @object
	.size	a, 1
a:
	.zero	1
	.globl	i
	.data
	.type	i, @object
	.size	i, 1
i:
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



### a = v[i] versão byte
	movzbl	i, %eax
	movsbl	%al, %eax
	movzbl	v(%eax), %eax
	movb	%al, a
### fim vet_call



	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
