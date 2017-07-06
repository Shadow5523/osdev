#include "pit.h"

/* Port Address*/
#define PIT_REG_COUNTER0 0x0040
#define PIT_REG_COUNTER1 0x0041
#define PIT_REG_COUNTER2 0x0042
#define PIT_REG_CONTROL  0x0043

/* Input CLK0*/
#define DEF_PIT_CLOCK 1193181.67


#define DEF_PIT_COM_MASK_BINCOUNT 0x01
#define DEF_PIT_COM_MASK_MODE     0x0E
#define DEF_PIT_COM_MASK_RL       0x30
#define DEF_PIT_COM_MASK_COUNTER  0xC0

/* binary count */
#define DEF_PIT_COM_BINCOUNT_BIN 0x00
#define DEF_PIT_COM_BINCOUNT_BCD 0x01

/* counter mode */
#define DEF_PIT_COM_MODE_TERMINAL 0x00
#define DEF_PIT_COM_MODE_PROGONE 0x02
#define DEF_PIT_COM_MODE_RATEGEN 0x04
#define DEF_PIT_COM_MODE_SQUAREWAVE 0x06
#define DEF_PIT_COM_MODE_SOFTTRIG 0x08
#define DEF_PIT_COM_MODE_HARDTRIG 0x0A

/* data transfer */
#define DEF_PIT_COM_RL_LATCH 0x00
#define DEF_PIT_COM_RL_LSBONLY 0x10
#define DEF_PIT_COM_RL_MSBONLY 0x20
#define DEF_PIT_COM_RL_DATA 0x30

/* counter */
#define DEF_PIT_COM_COUNTER0 0x00
#define DEF_PIT_COM_COUNTER1 0x40
#define DEF_PIT_COM_COUNTER2 0x80

uint32_t setPitCounter(uint32_t freq, uint8_t counter, uint8_t mode){
  uint16_t count;
  uint8_t command;
  count = (uint16_t)(DEF_PIT_CLOCK / freq);

  /* make initial command */
  command = mode | DEF_PIT_COM_RL_DATA | counter;
  outb(PIT_REG_CONTROL, command);

  /* send counter value */
  outb(PIT_REG_COUNTER0, (uint8_t)(count & 0xff));
  outb(PIT_REG_COUNTER0, (uint8_t)((count >> 8) & 0xff));

}




uint32_t pit_init(void){
  setPitCounter(100, DEF_PIT_COM_COUNTER0, DEF_PIT_COM_MODE_SQUAREWAVE);
}
