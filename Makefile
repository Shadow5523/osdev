boot.o: boot.s
	i686-elf-as boot.s -o boot.o

terminal.o: terminal.h terminal.c vga.h
	i686-elf-gcc -c terminal.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra

inb_outb.o : inb_outb.h
	i686-elf-gcc -c inb_outb.h -std=gnu99 -ffreestanding -O2 -Wall -Wextra

gdts.o: gdt.s
	i686-elf-as gdt.s -o gdts.o

gdt.o: gdt.h gdt.c
	i686-elf-gcc -c gdt.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra

pic.o: pic.h pic.c
	i686-elf-gcc -c pic.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra

pit.o: pit.c pit.h
	i686-elf-gcc -c pit.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra

interrupt.o: interrupt.c interrupt.h
	i686-elf-gcc -c interrupt.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra

interruptas.o: interrupt.s
	i686-elf-as interrupt.s -o interruptas.o

keyboard.o: keyboard.c keyboard.h
	i686-elf-gcc -c keyboard.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra

idts.o: idt.s
	i686-elf-as idt.s -o idts.o

idt.o: idt.h idt.c
	i686-elf-gcc -c idt.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra

kernel.o: kernel.c
	i686-elf-gcc -c kernel.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra

create: kernel.o terminal.o boot.o gdt.o gdts.o idts.o idt.o inb_outb.o pic.o pit.o interrupt.o keyboard.o interruptas.o
	i686-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib *.o -lgcc
	grub2-file --is-x86-multiboot myos.bin
	\cp -f myos.bin isodir/boot/myos.bin
	grub2-mkrescue -o myos.iso isodir

clean: 
	rm -f *.o myos.bin
