#if !defined(__cplusplus)
#include <stdbool.h>
#endif
#include <stddef.h>
#include <stdint.h>

/* コンパイラが正しいターゲットを認識しているかの確認 */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* 32-bit x86ターゲット以外のコンパイラを使用するとエラーになる */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

#include "terminal.h"
#include "gdt.h"
#include "pic.h"
#include "pit.h"
#include "idt.h"
#include "keyboard.h"
#include "inb_outb.h"

size_t strlen(const char*);

#if defined(__cplusplus)
us_keytableextern "C"
#endif
