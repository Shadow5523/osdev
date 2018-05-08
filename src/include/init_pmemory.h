#ifndef _INIT_PMEMORY_H_
#define _INIT_PMEMORY_H_

#include <stdint.h>
#include <stddef.h>

#include "multiboot.h"
#include "get_ksize.h"
#include "../sh_libc/include/stdio.h"
#include "../sh_libc/include/string.h"

typedef struct{
  uint32_t system_msize;  //システムメモリサイズ
  uint32_t system_mbloks;  //システムメモリブロック数
  uint32_t allocated_blocks;  //割り当て済のブロック数
  uint32_t free_blocks;  //フリーブロック数
  uint32_t* mmap;  //ビットマップ
  uint32_t mmap_size;  //ビットマップのサイズ
}p_memory_info;

p_memory_info pm_info;

void get_system_mblocks(uint32_t);
void setmemory(int);
void clearmemory(int);
void pbitmap_free(uint32_t, uint32_t);
void pbitmap_alloc(uint32_t, uint32_t);

#endif _INIT_PMEMORY_H_
