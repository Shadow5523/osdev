#ifndef _GET_KSIZE_H_
#define _GET_KSIZE_H_

#include <stdint.h>

extern uint32_t __kernel_start;
extern uint32_t __kernel_end;

uint32_t get_ksize(void);

#endif _GET_KSIZE_H_
