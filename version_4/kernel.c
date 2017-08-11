#include "kernel.h"

void kernel_main(void){
  terminal_initialize();
  key_init();
  gdt_init();
  pic_init();     //追加
  idt_init();     //追加
  terminal_writestring("Hello, kernel World! \n");
  keyboard_input_int();
}


size_t strlen(const uint8_t* str){
  size_t len = 0;
  while (str[len]) ++len;
  return len;
}
