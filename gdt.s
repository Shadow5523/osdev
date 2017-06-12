.global load_gdtr

load_gdtr:
	mov	4(%esp), %ax
	mov	%ax, 6(%esp)
	lgdt	6(%esp)
	ret
