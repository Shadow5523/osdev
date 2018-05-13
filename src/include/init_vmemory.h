#ifndef _INIT_VMEMORY_H_
#define _INIT_VMEMORY_H_

#include <stdint.h>
#include <stddef.h>

#define PAGE_ENTRY_PFLAG 0x00000001
#define PAGE_ENTRY_RWFLAG 0x00000002

//pte & pdeの形を定義
typedef uint32_t page_table_entry;
typedef uint32_t page_dir_entry;

extern void enable_paging(page_dir_entry *);
int init_paging(void);
int init_vmemory(void);

#endif _INIT_PMEMORY_H_
