.global load_gdtr

load_gdtr:
	mov	4(%esp), %ax
	mov	%ax, 6(%esp)
	lgdt	6(%esp)
	
/*
	mov 	$0x10,	%ax
	mov	%ax,  	%ds
	mov	%ax,	%es
	mov	%ax,	%fs
	mov	%ax,	%gs
	mov	%ax,	%ss

	ljmp	$0x80, $flush

flush:	
	ret
*/
