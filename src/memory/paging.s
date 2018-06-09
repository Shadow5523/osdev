.text
.global enable_paging 

enable_paging:
  push %ebp
  mov %esp, %ebp

  //writing cr3
  mov 8(%esp), %eax
  mov %eax, %cr3

  //writing cr0
  mov %cr0, %eax
  or $0x80000000, %eax
  mov %eax, %cr0
  
  mov %ebp, %esp
  pop %ebp
  ret
