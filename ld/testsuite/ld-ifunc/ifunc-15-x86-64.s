	.text
        .type foo, @function
	.global
foo:
        movl ifunc@GOTPCREL(%rip), %eax
        ret
        .type ifunc, @gnu_indirect_function
	.globl ifunc
ifunc:
        ret
