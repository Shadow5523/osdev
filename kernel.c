#include "kernel.h"

void kernel_main(void){
  terminal_initialize();
  key_init();
  gdt_init();
  pic_init();
  pit_init();
  idt_init();
  terminal_writestring("The homemade OS!\n\n");
  for(;;){

  } 
}



static inline uint16_t vga_entry(unsigned char uc, uint8_t color){
  return (uint16_t)uc | (uint16_t)color << 8; 
}
 
 
size_t strlen(const char* str){
  size_t len = 0;
  while (str[len]) {++len;}
  return len;
}
 
