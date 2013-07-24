.data 
__PoRcEnTo_D:
	.string "%d\12\0"
_0:
	.value 0
_1:
	.value 1
_2:
	.value 2
_5:
	.value 5
_6:
	.value 6
_9:
	.value 9
_10:
	.value 10
_20:
	.value 20
_30:
	.value 30
_40:
	.value 40
_"digite um numero":
	.string"digite um numero"
_50:
	.value 50
_60:
	.value 60
_70:
	.value 70
_80:
	.value 80
_90:
	.value 90
_'a':
	.byte 'a'
_"string 4":
	.string"string 4"
_"string 3":
	.string"string 3"
_"string 2":
	.string"string 2"
_"string 1":
	.string"string 1"

   .globl  a
   .data
   .align 4
   .type   a, @object
   .size   a, 4
a:
   .long   a
	.type	v, @object
	.size	v, 36
v:
	.long	10
	.long	20
	.long	30
	.long	40
	.long	50
	.long	60
	.long	70
	.long	80
	.long	90

   .globl  x
   .data
   .align 4
   .type   x, @object
   .size   x, 1
x:
   .long   1

   .globl  i
   .data
   .align 4
   .type   i, @object
   .size   i, 4
i:
   .long   i
   .globl f
   .type  f, @function
f:
.LFB0:
   .cfi_startproc
   pushl   %ebp
   .cfi_def_cfa_offset 8
   .cfi_offset 5, -8
   movl    %esp, %ebp
   .cfi_def_cfa_register 5
   popl    %ebp
   .cfi_restore 5
   .cfi_def_cfa 4, 4
   ret
   .cfi_endproc
.LFE0:
   .size   f, .-f
   .globl main
   .type  main, @function
main:
.LFB1:
   .cfi_startproc
   pushl   %ebp
   .cfi_def_cfa_offset 8
   .cfi_offset 5, -8
   movl    %esp, %ebp
   .cfi_def_cfa_register 5
  OUTPUT
  SOMA
  OUTPUT
  SOMA
  OUTPUT
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
  SOMA
   popl    %ebp
   .cfi_restore 5
   .cfi_def_cfa 4, 4
   ret
   .cfi_endproc
.LFE1:
   .size   main, .-main
