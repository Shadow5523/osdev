#include "../include/pmalloc.h"

int findfreememory(unsigned int *bnum){
  for (size_t b_index = 0; b_index < pm_info.mmap_size; b_index++) {
    if (pm_info.mmap[b_index] != 0xFFFFFFFF) {
      for (size_t b_count = 0; b_count < 32; b_count++) {
        if (!(pm_info.mmap[b_index] & (1 << (b_count % 32)))) {
          *bnum = b_index * sizeof(unsigned int) * 8 + b_count;
          return 0;
        }
      }
    }
  }
  return -1;
}


void* malloc4kb(void){
  unsigned int b_number;
  void* p_address;
  int status;
  if (pm_info.free_blocks <= 0) { return NULL; }
  if (findfreememory(&b_number)) { return NULL; }
  setmemory(b_number);
  
  p_address = (void *)(b_number * 4096);

  pm_info.allocated_blocks++;
  pm_info.free_blocks--;

  return p_address;
}


void free4kb(void* p_address){
  unsigned int b_number;
  b_number = (unsigned int)p_address / 4096;
  
  clearmemory(b_number);

  pm_info.allocated_blocks--;
  pm_info.free_blocks++;
}
