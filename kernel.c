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

           /* Hardware text mode color constants. */
void keyboard_input(void);
uint8_t ps2_kerbord_init(void);
uint8_t at_kerbord_init(void);
size_t strlen(const char*);
 
char getscode(void);
char getchar(void);
uint8_t getscodeset(void);
void changecodeset(uint8_t);
static inline uint8_t inb(uint16_t port);
static inline uint8_t outb(uint16_t port, uint8_t val);

char us_keytable_set2[0x54] = {
   '0', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
   '0', '-', '=', '\b', '\t', 'Q', 'W', 'E', 'R', 'T', 
   'Y', 'U', 'I', 'O', 'P', '[', ']', '\n', '0', 'A', 
   'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'',
   '`', '0', '\\', 'Z', 'X', 'C', 'V', 'B', 'N', 'M',
   ',', '.', '/', '0', '*', '0', ' ', '0', '0', '0',
   '0', '0', '0', '0', 'a', '0', '0', '0', '0', '0',
   '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
   '0', '0', '0', '0', '0'};
 
#if defined(__cplusplus)
us_keytableextern "C" /* Use C linkage for kernel_main. */
#endif
void kernel_main(void){
  terminal_initialize();
  gdt_init();
  idt_init();

  terminal_writestring("The homemade OS!\n\n");

  if(ps2_kerbord_init() == 0){
    keyboard_input();

  }else{
    at_kerbord_init();
    keyboard_input();
  }
  
}



#define SCAN_CODE_SET1 0x01
#define SCAN_CODE_SET2 0x02
#define SCAN_CODE_SET3 0x03

uint8_t ps2_kerbord_init(void){
  uint8_t scodeset;
  changecodeset(SCAN_CODE_SET2);
  scodeset = getscodeset();

  if(scodeset == 0x43){
    terminal_writestring("Scan code set 1\n\n");

  }else if(scodeset == 0x41){
    terminal_writestring("Scan code set 2\n\n");

  }else if(scodeset == 0x3f){
    terminal_writestring("Scan code set 3\n\n");

  }else{
    terminal_writestring("Unknown scan code set\n\n");
    return 1;

  }
  outb(0x60, 0xFA);
  return 0;

}



uint8_t at_kerbord_init(void){
  outb(0x60, 0xF2);
  if(getscode() == 0xAB){
    terminal_writestring("at keybord test ok\n\n");

  }

}



void keyboard_input(void){
  int str, old, j = 0, i = 0;
  char psend[2];
  while(1){
    str = getchar();
    psend[0] = us_keytable_set2[str];
    psend[1] = 0;

    if(i == 1){
      if(j == 0){
        terminal_writestring(psend);
        old = str;

      }else if(j > 800000){
        terminal_writestring(psend);

      }

    }

    if(old != str){
      i = 0;
      j = 0;

    }else if(old == str){
      ++j;

    }

    if(i > 700000) i = 0;

    if(str == 0xf0){
      terminal_writestring("relese key\n\n");

    }
    ++i;

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
 
 
 
char getscode(void){
  char c = 0;
  do{
    if(inb(0x60) != c) {
      c = inb(0x60);
      if(c > 0) return c;

    }

  }while(1);

}



char getchar(void){
  return getscode();

}



uint8_t getscodeset(void){
  uint8_t code = 0;
  outb(0x60, 0xf0);//スキャンコードセットの状態を取得
  outb(0x60, 0x00);//スキャンコードセットの状態を取得
  code = getscode();
  outb(0x60, 0xf4);
  return code;

}



void changecodeset(uint8_t set){
  outb(0x60, 0xf0);
  outb(0x60, set);

}



static inline uint8_t inb(uint16_t port){
  uint8_t ret;
  asm volatile("inb %1, %0"
               : "=a"(ret)
               : "Nd"(port));
  return ret;

}



static inline uint8_t outb(uint16_t port, uint8_t val){
  asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));

}
