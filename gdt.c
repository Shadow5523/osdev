#include "gdt.h"

void gdt_init(void){
  struct gdt_desc *gdt = (struct gdt_desc *)0x00270000;
  terminal_writestring("init the gdt...");
  for(uint32_t i = 0; i < 8192; i++){
    set_segment_desc(gdt + i, 0, 0, 0);

  }
  set_segment_desc(gdt + 1, 0xffffffff, 0x00000000, 0x4092);
  set_segment_desc(gdt + 2, 0xffffffff, 0x00000000, 0x409A);
  
  load_gdtr(0xffff, 0x00270000);
  terminal_writestring("  ok\n");

}



void set_segment_desc(struct gdt_desc *sd, uint32_t limit, uint32_t base, uint8_t s_access){
  if(limit > 0xfffff){
    s_access |= 0x8000;
    limit /= 0x1000;
    
  }
  sd -> base_high = (base >> 24) & 0xff;
  sd -> base_low = base & 0xffff;
  sd -> base_mid = (base >> 16) & 0xff;
  sd -> s_access = s_access & 0xff;
  sd -> limit_low = limit & 0xffff;
  sd -> limit_high = ((limit >> 16) & 0x0f) | ((s_access >> 8) & 0xf0);
  
}
