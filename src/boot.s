.set ALIGN,    1<<0
.set MEMINFO,  1<<1
.set FLAGS,    ALIGN | MEMINFO
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.set KERNEL_VBASE, 0xC0000000
.set KERNEL_PNUM, (KERNEL_VBASE >> 22)

//初期のカーネルスタックサイズを確保する(16KB)
.set STACKSIZE, 0x4000

.section .data
.balign 0x1000

//ページディレクトリ作成
_boot_pd:
  .long 0x00000083
  .fill (KERNEL_PNUM - 1), 4, 0x00000000

  .long 0x00000083 
  .fill (1024 - KERNEL_PNUM - 1), 4, 0x00000000

.section .multiboot
.balign 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .text
.global _loader

_loader:
  movl  $(_boot_pd - KERNEL_VBASE), %ecx
  movl %ecx, %cr3

  // pse bit set
  movl %cr4, %ecx
  orl $0x00000010, %ecx
  movl %ecx, %cr4

  // enable paging
  movl %cr0, %ecx
  orl $0x80000000, %ecx
  movl %ecx, %cr0

  leal (_start), %ecx
  jmp *%ecx

.type _start, @function
_start:
  movl $0, (_boot_pd)
  
  // TLB Flush
  invlpg (0) 
  
  movl $stack_top, %esp
  addl $KERNEL_VBASE, %ebx
  pushl %eax
  pushl %ebx
  
  call kernel_main
  cli

1: hlt
  jmp 1b

.size _start, . - _start

.section .bss
.balign 32
stack_bottom:
.skip STACKSIZE
stack_top:
