#include "pit.h"

uint32_t setPitCounter(uint32_t freq, uint8_t counter, uint8_t mode){
  uint16_t count = (uint16_t)(DEF_PIT_CLOCK / freq);
  uint8_t command = mode | DEF_PIT_COM_RL_DATA | counter;
  outb(PIT_REG_CONTROL, command);

  /* send counter value */
  outb(PIT_REG_COUNTER0, (uint8_t)(count & 0xff));
  outb(PIT_REG_COUNTER0, (uint8_t)((count >> 8) & 0xff));
}




uint32_t pit_init(void){
  setPitCounter(100, DEF_PIT_COM_COUNTER0, DEF_PIT_COM_MODE_SQUAREWAVE);
}
