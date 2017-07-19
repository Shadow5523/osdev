#ifndef _INETRRUPT_H_
#define _INETRRUPT_H_ 

#include "pic.h"
//#include "keyboard.h"

#include <stdint.h>
#include <stddef.h>

void interrupt_done(void);

//irq
void timer_interrupt(void);
void keyboard_interrupt(void);

#define irq0 0x60
#define irq1 0x61

#endif _INETRRUPT_H_
