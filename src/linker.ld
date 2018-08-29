ENTRY(_loader)
OUTPUT_FORMAT(elf32-i386)

SECTIONS{
  . = 0xC0100000;

  .text ALIGN(4K) : AT(ADDR(.text) - 0xC0000000) {
        __kernel_start = .;
        *(.multiboot)
        *(.text)
  }

  .rodata ALIGN(4K) : AT(ADDR(.rodata) - 0xC0000000) {
        *(.rodata*)
  }

  .data ALIGN(4K) : AT(ADDR(.data) - 0xC0000000) {
        *(.data)
  }

  .bss ALIGN(4K) : AT(ADDR(.bss) - 0xC0000000) {
        *(COMMON)
        *(.bss)
        __kernel_end = .;        
  }
}


