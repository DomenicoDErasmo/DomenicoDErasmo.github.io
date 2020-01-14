	.file	"lab1.cpp"
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.align 8
.LC0:
	.string	"Enter the initial Consumer Price Index value : "
	.align 8
.LC1:
	.string	"Enter the new Consumer Price Index value : "
.LC2:
	.string	"The inflation rate is "
.LC3:
	.string	"%.\n"
	.align 8
.LC4:
	.string	"The average inflation rate across the data is "
	.align 8
.LC5:
	.string	"The median inflation rate across the data is "
	.align 8
.LC6:
	.string	"Would you like to run the program again? (y/n) : "
.LC7:
	.string	"Have a nice day!\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1493:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$672, %rsp
	leaq	-224(%rbp), %rdx
	movl	$0, %eax
	movl	$25, %ecx
	movq	%rdx, %rdi
	rep stosq
	leaq	-432(%rbp), %rdx
	movl	$0, %eax
	movl	$25, %ecx
	movq	%rdx, %rdi
	rep stosq
	leaq	-640(%rbp), %rdx
	movl	$0, %eax
	movl	$25, %ecx
	movq	%rdx, %rdi
	rep stosq
	movl	$0, -4(%rbp)
.L4:
	movl	$.LC0, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt3cin, %edi
	call	_ZNSirsERf
	movl	$.LC1, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt3cin, %edi
	call	_ZNSirsERf
	movss	-24(%rbp), %xmm0
	movl	-20(%rbp), %eax
	movaps	%xmm0, %xmm1
	movl	%eax, -660(%rbp)
	movss	-660(%rbp), %xmm0
	call	_Z13inflationRateff
	cvtsd2ss	%xmm0, %xmm2
	movss	%xmm2, -8(%rbp)
	movss	-20(%rbp), %xmm0
	movl	-4(%rbp), %eax
	cltq
	movss	%xmm0, -224(%rbp,%rax,4)
	movss	-24(%rbp), %xmm0
	movl	-4(%rbp), %eax
	cltq
	movss	%xmm0, -432(%rbp,%rax,4)
	movl	-4(%rbp), %eax
	cltq
	movss	-8(%rbp), %xmm0
	movss	%xmm0, -640(%rbp,%rax,4)
	movl	-4(%rbp), %edx
	leaq	-640(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_Z25calculateAverageInflationPfi
	cvtsd2ss	%xmm0, %xmm3
	movss	%xmm3, -12(%rbp)
	movl	-4(%rbp), %edx
	leaq	-640(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_Z24calculateMedianInflationPfi
	cvtsd2ss	%xmm0, %xmm4
	movss	%xmm4, -16(%rbp)
	movl	$.LC2, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	movl	-8(%rbp), %eax
	movl	%eax, -660(%rbp)
	movss	-660(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEf
	movl	$.LC3, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$.LC4, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	movl	-12(%rbp), %eax
	movl	%eax, -660(%rbp)
	movss	-660(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEf
	movl	$.LC3, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$.LC5, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	movl	-16(%rbp), %eax
	movl	%eax, -660(%rbp)
	movss	-660(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEf
	movl	$.LC3, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$.LC6, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-641(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt3cin, %edi
	call	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_
	addl	$1, -4(%rbp)
	movzbl	-641(%rbp), %eax
	cmpb	$121, %al
	je	.L4
	movzbl	-641(%rbp), %eax
	cmpb	$89, %al
	jne	.L3
	jmp	.L4
.L3:
	movl	$.LC7, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1493:
	.size	main, .-main
	.globl	_Z13inflationRateff
	.type	_Z13inflationRateff, @function
_Z13inflationRateff:
.LFB1494:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movss	%xmm0, -20(%rbp)
	movss	%xmm1, -24(%rbp)
	movss	-20(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jbe	.L7
	movss	-24(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jbe	.L7
	movss	-24(%rbp), %xmm0
	subss	-20(%rbp), %xmm0
	divss	-20(%rbp), %xmm0
	movss	.LC9(%rip), %xmm1
	mulss	%xmm1, %xmm0
	cvtss2sd	%xmm0, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	jmp	.L10
.L7:
	movsd	.LC10(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
.L10:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1494:
	.size	_Z13inflationRateff, .-_Z13inflationRateff
	.globl	_Z25calculateAverageInflationPfi
	.type	_Z25calculateAverageInflationPfi, @function
_Z25calculateAverageInflationPfi:
.LFB1495:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -4(%rbp)
.L15:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jg	.L14
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm0
	movss	-8(%rbp), %xmm1
	addss	%xmm1, %xmm0
	movss	%xmm0, -8(%rbp)
	addl	$1, -4(%rbp)
	jmp	.L15
.L14:
	cvtsi2ss	-4(%rbp), %xmm0
	movss	-8(%rbp), %xmm1
	divss	%xmm0, %xmm1
	movaps	%xmm1, %xmm0
	movss	%xmm0, -12(%rbp)
	cvtss2sd	-12(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1495:
	.size	_Z25calculateAverageInflationPfi, .-_Z25calculateAverageInflationPfi
	.globl	_Z24calculateMedianInflationPfi
	.type	_Z24calculateMedianInflationPfi, @function
_Z24calculateMedianInflationPfi:
.LFB1496:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -4(%rbp)
.L23:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jge	.L18
	movl	$0, -8(%rbp)
.L22:
	movl	-8(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jge	.L19
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm0
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm1
	ucomiss	%xmm1, %xmm0
	jbe	.L20
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm0
	movss	%xmm0, -16(%rbp)
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movss	(%rdx), %xmm0
	movss	%xmm0, (%rax)
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movss	-16(%rbp), %xmm0
	movss	%xmm0, (%rax)
.L20:
	addl	$1, -8(%rbp)
	jmp	.L22
.L19:
	addl	$1, -4(%rbp)
	jmp	.L23
.L18:
	movl	-28(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L24
	movl	-28(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm0
	movss	%xmm0, -12(%rbp)
	jmp	.L25
.L24:
	movl	-28(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm1
	movl	-28(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm0
	addss	%xmm1, %xmm0
	movss	.LC11(%rip), %xmm1
	divss	%xmm1, %xmm0
	movss	%xmm0, -12(%rbp)
.L25:
	cvtss2sd	-12(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1496:
	.size	_Z24calculateMedianInflationPfi, .-_Z24calculateMedianInflationPfi
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1982:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L30
	cmpl	$65535, -8(%rbp)
	jne	.L30
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L30:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1982:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB1983:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1983:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.section	.rodata
	.align 4
.LC9:
	.long	1120403456
	.align 8
.LC10:
	.long	0
	.long	-1074790400
	.align 4
.LC11:
	.long	1073741824
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 7.2.1 20170915 (Red Hat 7.2.1-2)"
	.section	.note.GNU-stack,"",@progbits
