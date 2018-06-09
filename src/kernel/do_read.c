#include "../include/do_read.h"

size_t do_read(int fd, void* buffer, size_t byte){
  if (!byte) { return 0;}
  if (fd < 0) { return -1; }
  if (buffer == NULL) { return -1; }

  sh_printf("sh_read() ok\n");
  #
  
  return byte;
}
