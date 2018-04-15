#include "include/sysdep.h"

uint32_t system_call(uint32_t syscall_num, uint32_t arg1, uint32_t arg2, uint32_t arg3){
  uint32_t ret;
  asm volatile("\tint $0x80\n"
               :"=a"(ret)
               : "a"(syscall_num), "b"(arg1), "c"(arg2), "d"(arg3));
  return ret;
}
