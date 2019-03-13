	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14
	.globl	_arith3                 ## -- Begin function arith3
	.p2align	4, 0x90
_arith3:                                ## @arith3
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movw	%dx, %ax
	movw	%si, %cx
	movw	%di, %r8w
	movw	%r8w, -2(%rbp)
	movw	%cx, -4(%rbp)
	movw	%ax, -6(%rbp)
	movswl	-4(%rbp), %edx
	movswl	-6(%rbp), %esi
	orl	%esi, %edx
	movw	%dx, %ax
	movw	%ax, -8(%rbp)
	movswl	-8(%rbp), %edx
	sarl	$9, %edx
	movw	%dx, %ax
	movw	%ax, -10(%rbp)
	cmpw	$0, -10(%rbp)
	setne	%r9b
	xorb	$-1, %r9b
	andb	$1, %r9b
	movzbl	%r9b, %edx
	movw	%dx, %ax
	movw	%ax, -12(%rbp)
	movswl	-12(%rbp), %edx
	movswl	-10(%rbp), %esi
	subl	%esi, %edx
	movw	%dx, %ax
	movw	%ax, -14(%rbp)
	movswl	-14(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
