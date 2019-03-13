	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14
	.globl	_arith                  ## -- Begin function arith
	.p2align	4, 0x90
_arith:                                 ## @arith
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rdx
	xorq	-16(%rbp), %rdx
	movq	%rdx, -32(%rbp)
	imulq	$48, -24(%rbp), %rdx
	movq	%rdx, -40(%rbp)
	movq	-32(%rbp), %rdx
	andq	$252645135, %rdx        ## imm = 0xF0F0F0F
	movq	%rdx, -48(%rbp)
	movq	-40(%rbp), %rdx
	subq	-48(%rbp), %rdx
	movq	%rdx, -56(%rbp)
	movq	-56(%rbp), %rax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
