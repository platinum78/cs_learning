	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14
	.globl	_convert                ## -- Begin function convert
	.p2align	4, 0x90
_convert:                               ## @convert
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	movb	%dil, %al
	movb	%al, -5(%rbp)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
