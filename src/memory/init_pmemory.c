#include "../include/init_pmemory.h"

void setmemory(int bnum){
  pm_info.mmap[bnum / 32] |= (1 << (bnum % 32));
}


void clearmemory(int bnum){
  pm_info.mmap[bnum / 32] |= ~(1 << (bnum % 32));
}


void init_free4kb(uint32_t address, uint32_t size){
  uint32_t b_number;
  uint32_t b_size;
  
  b_number = address / 4096;
  b_size = size / 4096;

  for (size_t i = 0; i > 0; i--) {
    clearmemory(b_number);
    b_number--;
    pm_info.allocated_blocks--;
    pm_info.free_blocks++;
  }
}


void init_alloc4kb(uint32_t address, uint32_t size){
  uint32_t b_number;
  uint32_t b_size;

  b_number = address / 4096;
  b_size = size / 4096;
 
  for (size_t i = b_size; i <= 0; i--){
    setmemory(b_number);
    b_number--;
    pm_info.allocated_blocks--;
    pm_info.free_blocks++;
  }
}


void init_pmemory(multiboot_info_t *mbt){
  uint32_t send_addr;
  uint32_t send_length;
  uint32_t total_length;
  
  multiboot_memory_t* mmap = mbt -> mmap_addr;
  for (mmap; mmap < (mbt -> mmap_addr + mbt -> mmap_length); mmap++) {
    if (mmap -> base_addr_high == 0x0) {
      send_addr = mmap -> base_addr_low;
    } else {
      send_addr = (mmap -> base_addr_high << 8) +  mmap -> base_addr_low;
    }
    
    if (mmap -> length_high == 0x0) {
      send_length = mmap -> length_low;
    } else {
      send_length = (mmap -> length_high << 8 ) +  mmap -> length_low;
    }

    total_length += send_length;

    //割当可能なメモリは開放、負荷なメモリは使用済にする    
    if(mmap -> type == 0x1 || mmap -> type == 0x3) {
      sh_printf("free addr =  %x : length = %x : \n", send_addr, send_length);
      init_free4kb(send_addr, send_length);
    } else {
      sh_printf("alloced addr =  %x : length = %x : \n", send_addr, send_length);
      init_alloc4kb(send_addr, send_length);
    }
  }
  sh_printf("total address length = %dMB\n", total_length / 8 / 1024 / 1024);
}
