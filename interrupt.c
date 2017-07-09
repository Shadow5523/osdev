#include "interrupt.h"

static volatile int timer_tick;

void interrupt_done(void){
  outb(MASTER_PIC_CMD_STAT, PIC_EOI);
  outb(SLAVE_PIC_CMD_STAT, PIC_EOI);
}


void timer_interrupt(void){
  outb(MASTER_PIC_CMD_STAT, irq0);
  ++timer_tick;
  interrupt_done();
}


void keyboard_interrupt(void){
  outb(MASTER_PIC_CMD_STAT, irq1);
  keyboard_input_int(getchar());
}

