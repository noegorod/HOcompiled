1. Escriban qué esperan de cada uno de los pasos

	Preprocesador: un llamado a funciones pre-definidas que incluyo al principio del codigo en C
	Compilacion I: traduccion del codigo en C al codigo en assembler
	Compilacion II: traduccion del codig en assembler al codigo en binario - acá ya no puedo entenderlo mas!
	Linkeo: busqueda de definicion de funciones en distintos codigos

2. ¿Qué agregó el preprocesador?

MUCHAS COSAS!
Definiciones de tipos, estructuras y funciones que se llaman en el include de calculator.c (calculator.h)

3. Identificar en la rutina de assembler las funciones

funcion main luce asi...
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$11, %esi
	movl	$31, %edi
	call	add_numbers
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc

funcion add_numbers luce asi...
add_numbers:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc

4. Explicar qué quieren decir los símbolos que se crean en el objeto

	T: la funcion es conocida - está definida en algun lado del codigo
	U: la funcion es desconocida - NO está definida en el codigo, necesita buscar en una librería

5. ¿En qué se diferencian los símbolos del objeto y del ejecutable?

En el objeto: printf
En el ejecutable: printf@@GLIBC_2.2.5	--> puede ir a buscar esta definicion a la libreria dinamica, cada vez que se ejecute el programa


