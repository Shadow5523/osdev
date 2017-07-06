#ifndef _PIT_H_
#define _PIT_H_

#include "pic.h"
#include "inb_outb.h"

uint32_t setPitCounter(uint32_t, uint8_t, uint8_t);
uint32_t pit_init(void);

#endif _PIT_H_
