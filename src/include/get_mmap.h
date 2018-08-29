#ifndef _GETMMAP_H_
#define _GETMMAP_H_

#include "multiboot.h"

uint32_t getmmap(multiboot_info_t*);

#define VBASE 0xC0000000

#endif _GETMMAP_H_
