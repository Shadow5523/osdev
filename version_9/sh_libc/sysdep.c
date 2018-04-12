#include "include/sysdep.h"

uint32_t system_call(uint32_t syscall_num, void* arg1, void* arg2, void* arg3){
  uint32_t ret;
  asm volatile("int $0x80"
               :"=a"(ret)
               : "a"(syscall_num), "b"(1), "c"(2), "d"(3));
  return ret;
}
