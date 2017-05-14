#ifndef _TERMINAL_H_
#define _TERMINAL_H_

#include <stdint.h>
#include <stddef.h>

void terminal_initialize(void);
void terminal_setcolor(uint8_t);
void terminal_putentryat(char, uint8_t, size_t, size_t);
void terminal_uponerow(void);
void terminal_putchar(char c);
void terminal_write(const char*, size_t);
void terminal_writestring(const char*);

#endif _TERMINAL_H_
