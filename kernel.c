#if !defined(__cplusplus)
#include <stdbool.h> /*C言語でboolean型を使えるように宣言する*/
#endif
#include <stddef.h>
#include <stdint.h>
 
           /* コンパイラが正しいターゲットを認識しているかの確認 */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
 
           /* 32-bit x86ターゲット以外のコンパイラを使用するとエラーになる */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

#include "terminal.h"
#include "gdt.h"
#include "idt.h"
#include "keyboard.h"
#include "inb_outb.h"

/* Hardware text mode color constants. */
size_t strlen(const char*);
 
#if defined(__cplusplus)
us_keytableextern "C" /* Use C linkage for kernel_main. */
#endif
void kernel_main(void){
  terminal_initialize();
  gdt_init();
  idt_init();

  terminal_writestring("The homemade OS!\n\n");

  if(ps2_kerbord_init() == 0){
    //keyboard_input();
    while(1){

    }

  }else{
    at_kerbord_init();
    //keyboard_input();
    while(1){

    }

  }
  
}



static inline uint16_t vga_entry(unsigned char uc, uint8_t color){
  return (uint16_t)uc | (uint16_t)color << 8;
 
}
 
 
 
size_t strlen(const char* str){
  size_t len = 0;
  while (str[len])
    len++;
 
  return len;
}
 
