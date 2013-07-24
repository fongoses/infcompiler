	.file	"multiplica.c"
	.globl	a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	5
	.globl	b
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	3
	.globl	c
	.bss
	.align 4
	.type	c, @object
	.size	c, 4
c:
	.zero	4
	.globl	x
	.data
	.type	x, @object
	.size	x, 1
x:
	.byte	2
	.globl	y
	.type	y, @object
	.size	y, 1
y:
	.byte	9
	.globl	z
	.bss
	.type	z, @object
	.size	z, 1
z:
	.zero	1
	.section	.rodata
	.align 4
.LC0:
	.string	"Subtrai:\na = %d, b = %d, c = %d\nx = %d, y = %d, z = %d\n"
	.align 4
.LC1:
	.string	"Multiplica:\na = %d, b = %d, c = %d\nx = %d, y = %d, z = %d\n"
	.align 4
.LC2:
	.string	"Divide:\na = %d, b = %d, c = %d\nx = %d, y = %d, z = %d\n"
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
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$48, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
.L2:
	movl	a, %edx
	movl	b, %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, c
.L3:
	movzbl	x, %eax
	movl	%eax, %edx
	movzbl	y, %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movb	%al, z
.L4:
	movzbl	z, %eax
	movsbl	%al, %edi
	movzbl	y, %eax
	movsbl	%al, %esi
	movzbl	x, %eax
	movsbl	%al, %ebx
	movl	c, %ecx
	movl	b, %edx
	movl	a, %eax
	movl	%edi, 24(%esp)
	movl	%esi, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
.L5:
	movl	a, %edx
	movl	b, %eax
	imull	%edx, %eax
	movl	%eax, c
.L6:
	movzbl	x, %eax
	movzbl	y, %edx
	imull	%edx, %eax
	movb	%al, z
.L7:
	movzbl	z, %eax
	movsbl	%al, %edi
	movzbl	y, %eax
	movsbl	%al, %esi
	movzbl	x, %eax
	movsbl	%al, %ebx
	movl	c, %ecx
	movl	b, %edx
	movl	a, %eax
	movl	%edi, 24(%esp)
	movl	%esi, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
.L8:
	movl	a, %eax
	movl	b, %edx
	movl	%edx, 44(%esp)
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	44(%esp)
	movl	%eax, c
.L9:
	movzbl	x, %eax
	movsbl	%al, %eax
	movzbl	y, %edx
	movsbl	%dl, %edx
	movl	%edx, 44(%esp)
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	44(%esp)
	movb	%al, z
.L10:
	movzbl	z, %eax
	movsbl	%al, %edi
	movzbl	y, %eax
	movsbl	%al, %esi
	movzbl	x, %eax
	movsbl	%al, %ebx
	movl	c, %ecx
	movl	b, %edx
	movl	a, %eax
	movl	%edi, 24(%esp)
	movl	%esi, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.7.3-1ubuntu1) 4.7.3"
	.section	.note.GNU-stack,"",@progbits
