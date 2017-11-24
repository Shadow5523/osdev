#ifndef _STDIO_H_
#define _STDIO_H_

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>
#include <limits.h>

#include "../../include/terminal.h"

int sh_printf(const unsigned char*, ...);
int data_to_print(const unsigned char*);
static bool print(const unsigned char*, size_t);

#endif _STDIO_H_
