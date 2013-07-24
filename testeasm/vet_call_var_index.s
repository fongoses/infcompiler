	.file	"vet_call_var_index.c"
	.globl	v
	.data

### int v[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
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
### fim v

### int a = 0;
	.globl	a
	.bss
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.zero	4
### fim a

### int i = 5;
	.globl	i
	.data
	.align 4
	.type	i, @object
	.size	i, 4
i:
	.long	5
### fim i

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



### a = v[i]
	movl	i, %eax
	movl	v(,%eax,4), %eax
	movl	%eax, a
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
