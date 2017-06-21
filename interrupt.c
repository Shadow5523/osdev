#include "interrupt.h"
#include "keyboard.h"

static volatile int timer_tick;

void enter_interrupt(void){
  asm volatile("pusha");

}




void interrupt_done(void){
  outb(MASTER_PIC_CMD_STAT, PIC_EOI);
  outb(SLAVE_PIC_CMD_STAT, PIC_EOI);

}




void exit_interrupt(void){
  asm volatile("popa");
  asm volatile("iret");

}




void timer_interrupt(void){
  enter_interrupt();
  timer_tick++;
  interrupt_done();
  exit_interrupt();
}




void keyboard_interrupt(void){
  terminal_writestring("The input key!\n");
  enter_interrupt();  
  keyboard_input_int(getchar());
  interrupt_done();                                                                                                
  exit_interrupt();
}

