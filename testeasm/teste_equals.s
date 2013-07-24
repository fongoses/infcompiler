	.file	"teste_equals.c"
	.globl	a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	10
	.globl	b
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	5
	.globl	x
	.type	x, @object
	.size	x, 1
x:
	.byte	1
	.globl	y
	.type	y, @object
	.size	y, 1
y:
	.byte	20
	.section	.rodata
.LC0:
	.string	"a, b igual"
.LC1:
	.string	"a, b diferente"
.LC2:
	.string	"x, y igual"
.LC3:
	.string	"x, y diferente"
.LC4:
	.string	"a < b ok"
.LC5:
	.string	"a < b falso"
.LC6:
	.string	"x < y ok"
.LC7:
	.string	"x < y falso"
.LC8:
	.string	"a > b ok"
.LC9:
	.string	"a > b falso"
.LC10:
	.string	"x > y ok"
.LC11:
	.string	"x > y falso"
.LC12:
	.string	"a <= b ok"
.LC13:
	.string	"a <= b falso"
.LC14:
	.string	"x <= y ok"
.LC15:
	.string	"x <= y falso"
.LC16:
	.string	"a => b ok"
.LC17:
	.string	"a => b falso"
.LC18:
	.string	"x => y ok"
.LC19:
	.string	"x => y falso"
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
.L2:
	movl	a, %edx
	movl	b, %eax
	cmpl	%eax, %edx
	jne	.L3
	movl	$.LC0, (%esp)
	call	puts
	jmp	.L4
.L3:
	movl	$.LC1, (%esp)
	call	puts
.L4:
	movzbl	x, %edx
	movzbl	y, %eax
	cmpb	%al, %dl
	jne	.L5
	movl	$.LC2, (%esp)
	call	puts
	jmp	.L6
.L5:
	movl	$.LC3, (%esp)
	call	puts
.L6:
	movl	a, %edx
	movl	b, %eax
	cmpl	%eax, %edx
	jge	.L7
	movl	$.LC4, (%esp)
	call	puts
	jmp	.L8
.L7:
	movl	$.LC5, (%esp)
	call	puts
.L8:
	movzbl	x, %edx
	movzbl	y, %eax
	cmpb	%al, %dl
	jge	.L9
	movl	$.LC6, (%esp)
	call	puts
	jmp	.L10
.L9:
	movl	$.LC7, (%esp)
	call	puts
.L10:
	movl	a, %edx
	movl	b, %eax
	cmpl	%eax, %edx
	jle	.L11
	movl	$.LC8, (%esp)
	call	puts
	jmp	.L12
.L11:
	movl	$.LC9, (%esp)
	call	puts
.L12:
	movzbl	x, %edx
	movzbl	y, %eax
	cmpb	%al, %dl
	jle	.L13
	movl	$.LC10, (%esp)
	call	puts
	jmp	.L14
.L13:
	movl	$.LC11, (%esp)
	call	puts
.L14:
	movl	a, %edx
	movl	b, %eax
	cmpl	%eax, %edx
	jg	.L15
	movl	$.LC12, (%esp)
	call	puts
	jmp	.L16
.L15:
	movl	$.LC13, (%esp)
	call	puts
.L16:
	movzbl	x, %edx
	movzbl	y, %eax
	cmpb	%al, %dl
	jg	.L17
	movl	$.LC14, (%esp)
	call	puts
	jmp	.L18
.L17:
	movl	$.LC15, (%esp)
	call	puts
.L18:
	movl	a, %edx
	movl	b, %eax
	cmpl	%eax, %edx
	jl	.L19
	movl	$.LC16, (%esp)
	call	puts
	jmp	.L20
.L19:
	movl	$.LC17, (%esp)
	call	puts
.L20:
	movzbl	x, %edx
	movzbl	y, %eax
	cmpb	%al, %dl
	jl	.L21
	movl	$.LC18, (%esp)
	call	puts
	jmp	.L1
.L21:
	movl	$.LC19, (%esp)
	call	puts
.L1:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
