#include "../include/getmmap.h"

void getmmap(multiboot_info_t* mbt){
  multiboot_memory_t* mmap = mbt -> mmap_addr;
  for (mmap; mmap < (mbt -> mmap_addr + mbt -> mmap_length); mmap++) {
    sh_printf("base_addr = 0x%x%x : ", mmap -> base_addr_high, mmap -> base_addr_low);
    sh_printf("length = 0x%x%x : ", mmap -> length_high, mmap -> length_low);
    sh_printf("type = 0x%x\n", mmap -> type);
  }
}
