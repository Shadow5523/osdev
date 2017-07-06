#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <stdint.h>
#include "terminal.h"

#define SCAN_CODE_SET1 0x01
#define SCAN_CODE_SET2 0x02
#define SCAN_CODE_SET3 0x03

uint8_t ps2_kerbord_init(void);
uint8_t at_kerbord_init(void);
void keyboard_input(void);
//char getscode(void);
//char getchar(void);
//uint8_t getscodeset(void);
//void changecodeset(uint8_t);
void keyboard_input_int(int8_t);

#endif _KEYBOARD_H_
