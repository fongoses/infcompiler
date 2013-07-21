	.file	"teste1.c"
	.globl	x
	.data
	.align 4
	.type	x, @object
	.size	x, 4
x:
	.long	10
	.globl	i
	.bss
	.align 4
	.type	i, @object
	.size	i, 4
i:
	.zero	4
	.comm	v,40,32
	.globl	ch
	.data
	.type	ch, @object
	.size	ch, 1
ch:
	.byte	90
	.comm	ptr,4,4
	.section	.rodata
	.align 4
.LC0:
	.string	"Valores I = %d, V[%d] = %d, X = %d\n"
.LC1:
	.string	"PTR = %p, *PTR = %d, X = %d\n"
	.align 4
.LC2:
	.string	"PTR = %p, *PTR = %d, V[0] = %d\n"
	.align 4
.LC3:
	.string	"PTR = %p, *PTR = %d, V[3] = %d\n"
.LC4:
	.string	"Fim, ch = %c\n"
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
	pushl	%ebx
	andl	$-16, %esp
	subl	$32, %esp
	.cfi_offset 3, -12
	movl	$0, i
	jmp	.L2
.L3:
	movl	i, %eax
	movl	x, %ecx
	movl	i, %edx
	imull	%ecx, %edx
	movl	%edx, v(,%eax,4)
	movl	x, %ebx
	movl	i, %eax
	movl	v(,%eax,4), %ecx
	movl	i, %edx
	movl	i, %eax
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	x, %eax
	addl	$5, %eax
	movl	%eax, x
	movl	i, %eax
	addl	$1, %eax
	movl	%eax, i
.L2:
	movl	i, %eax
	cmpl	$9, %eax
	jle	.L3
	movl	$x, ptr
	movl	x, %ecx
	movl	ptr, %eax
	movl	(%eax), %edx
	movl	ptr, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	movl	ptr, %eax
	movl	$42, (%eax)
	movl	x, %ecx
	movl	ptr, %eax
	movl	(%eax), %edx
	movl	ptr, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	movl	$v, ptr
	movl	v, %ecx
	movl	ptr, %eax
	movl	(%eax), %edx
	movl	ptr, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	ptr, %eax
	addl	$12, %eax
	movl	%eax, ptr
	movl	v+12, %ecx
	movl	ptr, %eax
	movl	(%eax), %edx
	movl	ptr, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	movzbl	ch, %eax
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.7.3-1ubuntu1) 4.7.3"
	.section	.note.GNU-stack,"",@progbits
