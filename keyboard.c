#include "keyboard.h"
#include "inb_outb.h"

char getscode(void);
char getchar(void);
uint8_t getscodeset(void);
void changecodeset(uint8_t);

void key_init(void){
  if (ps2_kerbord_init() == 0) {

  } else if ( at_kerbord_init() == 0) {

  }
}


uint8_t ps2_kerbord_init(void){
  changecodeset(SCAN_CODE_SET2);
  uint8_t scodeset = getscodeset();
  if (scodeset == 0x43) {
    terminal_writestring("Scan code set 1\n");
  } else if (scodeset == 0x41) {
    terminal_writestring("Scan code set 2\n");
  } else if (scodeset == 0x3f) {
    terminal_writestring("Scan code set 3\n");
  } else {
    terminal_writestring("Unknown scan code set\n");
    return 1;
  }
  outb(0x60, 0xFA);
  return 0;
}


uint8_t at_kerbord_init(void){
  outb(0x60, 0xF2);
  if (getscode() == 0xAB) {
    terminal_writestring("at keybord test ok\n\n");
    return 0;
  }
  return 1;
}


void keyboard_input_int(int8_t scan_code){
  uint32_t old;
  int8_t us_keytable_set2[0x54] = {
    '0', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    '0', '-', '=', '\b', '\t', 'Q', 'W', 'E', 'R', 'T',
    'Y', 'U', 'I', 'O', 'P', '[', ']', '\n', '0', 'A',
    'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'',
    '`', '0', '\\', 'Z', 'X', 'C', 'V', 'B', 'N', 'M',
    ',', '.', '/', '0', '*', '0', ' ', '0', '0', '0',
    '0', '0', '0', '0', 'a', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0'};
  char psend[2] = {us_keytable_set2[scan_code], 0};

  if (i == 1) {
    if (j == 0) {
      terminal_writestring(psend);
      old = scan_code;
    } else if (j > 800000) {
      terminal_writestring(psend);
    }
  }

  if (old != scan_code) {
    i = 0;
    j = 0;
  } else if (old == scan_code) {
    ++j;
  }

  if (scan_code == 0xF0) {
    terminal_writestring("relese key\n\n");
  }

  if(i > 700000) i = 0;
  ++i;
}


uint8_t getscodeset(void){
  uint8_t code = 0;
  outb(0x60, 0xf0);//スキャンコードセットの状態を取得
  outb(0x60, 0x00);//スキャンコードセットの状態を取得
  code = getscode();
  outb(0x60, 0xf4);
  return code;
}


char getscode(void){
  char c = 0;
  do {
    if (inb(0x60) != c) {
      c = inb(0x60);
      if (c > 0) return c;
    }
  } while (1);
}


char getchar(void){
  return getscode();
}


void changecodeset(uint8_t set){
  outb(0x60, 0xf0);
  outb(0x60, set);

}
