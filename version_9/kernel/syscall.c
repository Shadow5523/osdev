#include "../include/syscall.h"
#include "../sh_libc/include/stdio.h"

uint32_t syscall_interrupt(uint32_t syscall_num, 
			   void* arg1,
			   void* arg2,
			   void* arg3) {
  switch (syscall_num) {
  case SYSCALL_WRITE:
    sh_printf("\nwrite() is ok!\n\n");
    break;

  case SYSCALL_READ:
    break;
  }
  return 0;
}
