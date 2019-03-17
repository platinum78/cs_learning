	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14
	.globl	_store_uprod            ## -- Begin function store_uprod
	.p2align	4, 0x90
_store_uprod:                           ## @store_uprod
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
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rdx
	mulq	%rdx
	movq	-8(%rbp), %rsi
	movq	%rdx, 8(%rsi)
	movq	%rax, (%rsi)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
