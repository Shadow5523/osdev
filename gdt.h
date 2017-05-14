#ifndef _GDT_H_
#define _GDT_H_

#include <stdint.h>
#include "terminal.h"

#ifdef __cplusplus
extern "C" void load_gdtr(uint8_t, uint32_t);
#else
extern void load_gdtr(uint8_t, uint32_t);
#endif


struct gdt_desc{
  uint16_t limit_low, base_low;
  uint8_t base_mid, s_access, limit_high, base_high;


};

void gdt_init(void);
void set_segment_desc(struct gdt_desc *, uint32_t, uint32_t, uint8_t);


#endif _GDT_H_
