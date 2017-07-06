.global as_keyboard_interrupt
.global as_timer_interrupt
	
.extern keyboard_interrupt
.extern timer_interrupt

as_keyboard_interrupt:
		push	%es
		push	%ds
		pushal
		mov	%esp, %eax
		push	%eax
		mov	%ss, %ax
		mov	%ax, %ds
		mov	%ax, %es
		call	keyboard_interrupt
		pop	%eax
		popal
		pop	%ds
		pop	%es
	        sti
		iretl


	
	
as_timer_interrupt:
		push    %es
		push    %ds
	        pushal
	        mov     %esp, %eax
	        push    %eax
	        mov     %ss, %ax
	        mov     %ax, %ds
	        mov     %ax, %es
	        call    timer_interrupt
	        pop     %eax
	        popal
	        pop     %ds
 	        pop     %es
	        sti
	        iretl


