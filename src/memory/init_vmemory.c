
#include "../include/init_vmemory.h"

int init_paging(void){
  page_dir_entry* page_directory = (page_dir_entry*)malloc4kb();
  page_table_entry* page_table = (page_table_entry*)malloc4kb();

  for (size_t i = 0, address = 0x0; i < 1024; i++, address += 0x1000) {
    page_directory[i] = PE_RWFLAG;    
    page_table[i] = address | (PE_RWFLAG | PE_PFLAG);
  }
  
  page_directory[0] = (page_dir_entry)page_table | (PE_RWFLAG | PE_PFLAG);
  enable_paging(page_directory);
  
  return 0;
}


int init_vmemory(void){
  if (!init_paging()) {
    sh_printf("Initialize paging init... OK!\n");
  }
}
