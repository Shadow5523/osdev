#ifndef _INETRRUPT_H_
#define _INETRRUPT_H_ 

#include "pic.h"
#include "keyboard.h"

void interrupt_done(void);

//irq
void timer_interrupt(void);
void keyboard_interrupt(void);

#endif _INETRRUPT_H_

#define irq0 0x60
#define irq1 0x61
