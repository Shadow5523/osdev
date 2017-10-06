#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SCAN_CODE_SET1       0x01
#define SCAN_CODE_SET2       0x02
#define SCAN_CODE_SET3       0x03

#define TYPEMATICDELAY_SET01 0x01
#define TYPEMATICDELAY_SET02 0x02
#define TYPEMATICDELEY_SET11 0x0B

#define PORTMAP_KEYBOARD1    0x60
#define PORTMAP_KEYBOARD2    0x61

//追加
#define L_SHIFT              0x2A
#define R_SHIFT              0x36
#define CAPS_LOCK            0x3A

typedef struct{
  uint8_t pdata[128];
  size_t write;
  size_t read;
  size_t len;
}key_buf;

//以下の構造体を追加する
typedef struct{
  bool shift_enable;
  bool relese_enable;
  bool caps_lock;
}key_stat;
key_stat ks;     //追加

void key_init(void);
uint8_t ps2_kerboard_init(void);
void keyboard_input_int(uint8_t);
uint8_t getscode(void);
uint8_t getchar(void);
uint8_t getscodeset(void);
void change_codeset(uint8_t);
void change_trate_delay(uint8_t);

#endif _KEYBOARD_H_
