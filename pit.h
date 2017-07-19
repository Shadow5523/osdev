#ifndef _PIT_H_
#define _PIT_H_

#include <stddef.h>
#include <stdint.h>
#include "inb_outb.h"

//ポートアドレス
#define PIT_REG_COUNTER0        0x0040
#define PIT_REG_COUNTER1        0x0041
#define PIT_REG_COUNTER2        0x0042
#define PIT_REG_CONTROL         0x0043

/* Input CLK0*/
#define PIT_CLOCK           1193181.67

#define PIT_COM_MASK_BINCOUNT   0x01
#define PIT_COM_MASK_MODE       0x0E
#define PIT_COM_MASK_RL         0x30
#define PIT_COM_MASK_COUNTER    0xC0

//バイナリカウント
#define PIT_COM_BINCOUNT_BIN    0x00
#define PIT_COM_BINCOUNT_BCD    0x01

/* counter mode */
#define PIT_COM_MODE_TERMINAL   0x00
#define PIT_COM_MODE_PROGONE    0x02
#define PIT_COM_MODE_RATEGEN    0x04
#define PIT_COM_MODE_SQUAREWAVE 0x06
#define PIT_COM_MODE_SOFTTRIG   0x08
#define PIT_COM_MODE_HARDTRIG   0x0A

/* data transfer */
#define PIT_COM_RL_LATCH        0x00
#define PIT_COM_RL_LSBONLY      0x10
#define PIT_COM_RL_MSBONLY      0x20
#define PIT_COM_RL_DATA         0x30

//カウンタ
#define PIT_COM_COUNTER0        0x00
#define PIT_COM_COUNTER1        0x40
#define PIT_COM_COUNTER2        0x80

uint32_t pit_init(void);
uint32_t set_pitcounter(uint32_t, uint8_t, uint8_t);

#endif _PIT_H_
