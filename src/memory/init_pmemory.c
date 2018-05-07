#include "../include/init_pmemory.h"

void get_system_mblocks(uint32_t msize){
  pm_info.system_msize = msize;
  pm_info.system_mbloks = msize / 4096;
  pm_info.allocated_blocks = pm_info.system_mbloks;
  pm_info.free_blocks = 0;
  pm_info.mmap = (uint32_t *)&__kernel_start + get_ksize(); //ビットマップのアドレス
  pm_info.mmap_size = pm_info.system_mbloks / sizeof(uint32_t) * 8;
  sh_memset((void *)pm_info.mmap, 0xff, pm_info.mmap_size);
}


void setmemory(int bnum){
  pm_info.mmap[bnum / 32] |= (1 << (bnum % 32));
}


void clearmemory(int bnum){
  pm_info.mmap[bnum / 32] &= ~(1 << (bnum % 32));
}


void init_free4kb(uint32_t address, uint32_t size){
  uint32_t b_number;
  uint32_t b_size;
  int i;
  
  b_number = address / 4096;
  b_size = size / 4096;
  for(size_t i = b_number; i <= b_size; i++){
    setmemory(b_number);
    b_number++;
    pm_info.allocated_blocks--;
    pm_info.free_blocks++;
  }
}


void init_alloc4kb(uint32_t address, uint32_t size){
  uint32_t b_number;
  uint32_t b_size;

  b_number = address / 4096;
  b_size = size / 4096;
  for(size_t i = b_number; i <= b_size; i++){
    setmemory(b_number);
    b_number++;
    pm_info.allocated_blocks++;
    pm_info.free_blocks--;
  }
}


void init_pmemory(multiboot_info_t *mbt, uint32_t total_msize){
  uint32_t send_addr;
  uint32_t send_length;
  multiboot_memory_t* mmap = mbt -> mmap_addr;

  get_system_mblocks(total_msize * 1024 * 1024);
 
  for (mmap; mmap < (mbt -> mmap_addr + mbt -> mmap_length); mmap++) {
    send_addr = (mmap -> base_addr_high << 8) +  mmap -> base_addr_low;
    send_length = (mmap -> length_high << 8 ) +  mmap -> length_low;

    if(mmap -> type == 0x1 || mmap -> type == 0x3) {
      init_free4kb(send_addr, send_length);
    } else {
      init_alloc4kb(send_addr, send_length);
    }
  }
}
