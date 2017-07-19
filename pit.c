#include "pit.h"

uint32_t pit_init(void){
  set_pitcounter(100, PIT_COM_COUNTER0, PIT_COM_MODE_SQUAREWAVE);
}


uint32_t set_pitcounter(uint32_t freq, uint8_t counter, uint8_t mode){
  uint16_t count = (uint16_t)(PIT_CLOCK / freq);
  uint8_t command = mode | PIT_COM_RL_DATA | counter;
  outb(PIT_REG_CONTROL, command);

  outb(PIT_REG_COUNTER0, (uint8_t)(count & 0xff));
  outb(PIT_REG_COUNTER0, (uint8_t)((count >> 8) & 0xff));
}
