	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14
	.globl	_remdiv                 ## -- Begin function remdiv
	.p2align	4, 0x90
_remdiv:                                ## @remdiv
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
	movq	%rcx, -32(%rbp)
	movq	-8(%rbp), %rax
	cqto
	idivq	-16(%rbp)
	movq	%rax, -40(%rbp)
	movq	-8(%rbp), %rax
	cqto
	idivq	-16(%rbp)
	movq	%rdx, -48(%rbp)
	movq	-40(%rbp), %rcx
	movq	-24(%rbp), %rdx
	movq	%rcx, (%rdx)
	movq	-48(%rbp), %rcx
	movq	-32(%rbp), %rdx
	movq	%rcx, (%rdx)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
