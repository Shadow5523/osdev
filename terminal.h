#ifndef _TERMINAL_H_
#define _TERMINAL_H_

#include <stdint.h>
#include <stddef.h>

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static size_t t_row;
static size_t t_column;
static uint8_t t_color;
static uint16_t* t_buffer;

void terminal_initialize(void);
void terminal_setcolor(uint8_t);
void terminal_putentryat(char, uint8_t, size_t, size_t);
void terminal_uponerow(void);
void terminal_putchar(char c);
void terminal_write(const char*, size_t);
void terminal_writestring(const char*);

#endif _TERMINAL_H_
