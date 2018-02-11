#include "../include/kernel.h"

extern key_buf kb;
extern size_t pmstr_len;
size_t pmstr_len;

void kernel_main(multiboot_info_t* mbt, uint32_t magic){
  terminal_initialize();
  sh_printf("Initialize Terminal... OK\n");
  gdt_init();
  pic_init();
  idt_init();
  key_init();
  getmmap(mbt);
  sh_printf("Hello, kernel World! \n\n");
  prompt();
}


void prompt(void){
  char *prompt_name = "prompt";
  pmstr_len = sh_strlen(prompt_name);
  sh_printf("\n%s> ", prompt_name);

  kb.len = 0;
  kb.write = 0;
  kb.read = 0;

  for (;;) {
    asm volatile("cli");
    if (!kb.len) {
      asm volatile("sti");
    } else {
      char c = kb.pdata[kb.read];
      --kb.len;
      ++kb.read;
      if (kb.read == 128) { kb.read = 0; }
      asm volatile("sti");

      if (c == '\n') {
	sh_printf("\n%s> ", prompt_name);
      } else {
	sh_printf("%c", c);
      }
    }
  }
}
