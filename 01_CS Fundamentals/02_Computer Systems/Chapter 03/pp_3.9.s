	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14
	.globl	_shift_left4_rightn     ## -- Begin function shift_left4_rightn
	.p2align	4, 0x90
_shift_left4_rightn:                    ## @shift_left4_rightn
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	shlq	$4, %rsi
	movq	%rsi, -8(%rbp)
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rsi
                                        ## kill: def %cl killed %rcx
	sarq	%cl, %rsi
	movq	%rsi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
