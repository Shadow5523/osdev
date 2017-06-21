#ifndef _INETRRUPT_H_
#define _INETRRUPT_H_ 

#include "pic.h"

void enter_interrupt(void);
void interrupt_done(void);
void exit_interrupt(void);

//irq
void timer_interrupt(void);
void keyboard_interrupt(void);

#endif _INETRRUPT_H_
