#include "../include/do_write.h"

size_t do_write(int fd, const void* buffer, size_t byte){
  if (!byte) { return 0;}
  if (fd < 0) { return -1; }
  if (buffer == NULL) { return -1; }

  #
  
  return byte;
}
