#ifndef _INIT_PMEMORY_H_
#define _INIT_PMEMORY_H_

#include <stdint.h>
#include <stddef.h>

#include "multiboot.h"
#include "../sh_libc/include/stdio.h"

typedef struct{
  uint32_t system_msize;  //システムメモリサイズ
  uint32_t system_mbloks;  //システムメモリブロック数
  uint32_t allocated_blocks;  //割り当て済のブロック数
  uint32_t free_blocks;  //フリーブロック数
  uint32_t* mmap;  //ビットマップ
  uint32_t mmap_size;  //ビットマップのサイズ
}p_memory_info;

p_memory_info pm_info;

void setmemory(int);
void clearmemory(int);
void init_free4kb(uint32_t, uint32_t);
void init_alloc4kb(uint32_t, uint32_t);

#endif _INIT_PMEMORY_H_
