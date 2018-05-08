#ifndef _PMALLOC_H_
#define _PMALLOC_H_

#include <stdint.h>
#include <stddef.h>

#include "init_pmemory.h"
#include "../sh_libc/include/stdio.h"

extern p_memory_info pm_info;

int checkmemory(int);
int findfreememory(unsigned int*);
void* malloc4kb(void);
void free4kb(void*);

#endif _PMALLOC_H_
