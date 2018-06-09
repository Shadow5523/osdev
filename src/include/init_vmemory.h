#ifndef _INIT_VMEMORY_H_ 
#define _INIT_VMEMORY_H_ 

#include <stdint.h> 
#include <stddef.h>

#include "init_pmemory.h"
#include "pmalloc.h"

#define PE_PFLAG  0x00000001 
#define PE_RWFLAG 0x00000002 

//pte & pdeの形を定義 
typedef uint32_t page_table_entry; 
typedef uint32_t page_dir_entry; 
extern p_memory_info pm_info;

extern void enable_paging(page_dir_entry *); 
int init_paging(void); 
int init_vmemory(void); 

#endif _INIT_PMEMORY_H_ 
