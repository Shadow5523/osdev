#include "../include/init_vmemory.h"

int init_paging(void){
  page_dir_entry page_directory[1024]  __attribute__((aligned(4096)));
  page_table_entry page_table[1024] __attribute__((aligned(4096)));
  uint32_t address;
  
  for(size_t i = 0, address = 0x0; i < 1024; i++, address += 0x1000){
    page_directory[i] = PAGE_ENTRY_RWFLAG;
    page_table[i] = address | 3;
  }
  
  page_directory[0] = (uint32_t)page_table | 3;
  
  enable_paging(page_directory);
 
 //cr0レジスタの値を確認
  uint32_t cr0_data;
  asm volatile(
      "pop %%eax \n"
      "mov %%cr0, %%eax \n"
      : "=a"(cr0_data) : : );
  sh_printf("cr0 registar=0x%x\n", cr0_data);
  
  return 0;
}


int init_vmemory(void){
  if(!init_paging()){
    sh_printf("Initialize paging init... OK!\n");
  }
}
