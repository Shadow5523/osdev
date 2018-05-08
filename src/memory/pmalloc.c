#include "../include/pmalloc.h"

int checkmemory(int bnum){
  return pm_info.mmap[bnum / 32] & (1 << (bnum % 32));
}


int findfreememory(unsigned int *bnum){
  unsigned int found;
  size_t b_count;

  for (size_t b_index = 0; b_index < pm_info.mmap_size; b_index++) {
    if (pm_info.mmap[b_count] != 0xFFFFFFFF) {
      for (b_count = 0; b_count < 32; b_count++) {
        if (!checkmemory(b_count)) {
          *bnum = b_index * sizeof(unsigned int) * 8 + b_count;
          return 1;
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
  if (findfreememory(&b_number) != 1) { return NULL; }
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
