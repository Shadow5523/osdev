.global _loader
.extern kernel_main
  
.set ALIGN,    1<<0
.set MEMINFO,  1<<1
.set FLAGS,    ALIGN | MEMINFO
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.set KERNEL_VBASE, 0xC0000000
.set KERNEL_PNUM, (KERNEL_VBASE >> 22)

.section .data
.align 0x1000

//ページディレクトリ作成
.global boot_pd
boot_pd:
  .long 0x00000083
  .fill (KERNEL_PNUM - 1), 4, 0x00000000
  
  .long 0x00000083
  .fill (1024 - KERNEL_PNUM - 1), 4, 0x00000000

.section .multiboot
.align 4   
.long MAGIC
.long FLAGS
.long CHECKSUM

//初期のカーネルスタックサイズを確保する(16KB)
.set STACKSIZE, 0x4000
.set loader, _loader
  
.global loader  
.global _loader  
_loader:
  movl  $(boot_pd - KERNEL_VBASE), %ecx
  movl %ecx, %cr3

  // pse bit set
  movl %cr4, %ecx
  orl $0x00000010, %ecx
  movl %ecx, %cr4

  // enable paging
  movl %cr0, %ecx
  orl $0x80000000, %ecx
  movl %ecx, %cr0

  lea (_start), %ecx
  jmp %ecx

.section .text
.global _start
.type _start, @function

_start:
  movl $0, (boot_pd)
  // TLB Flush
  invlpg (0) 
  
  movl $stack_top + STACKSIZE, %esp
  
	push %eax
  addl  $KERNEL_VBASE, %ebx
	push %ebx
  
  call kernel_main
  cli

1: hlt
  jmp 1b

.size _start, . - _start

.section .bss
.align 32
stack_bottom:
.skip STACKSIZE
stack_top:
  
