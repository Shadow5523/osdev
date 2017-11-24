#include "include/string.h"

size_t sh_strlen(const uint8_t* str){
  size_t len = 0;
  while (str[len]) { ++len; }
  return len;
}


void sh_strrev(unsigned char* str) {
  size_t i = 0, j = 0;
  unsigned char tmp;
  size_t len = sh_strlen(str);
  for(i = 0, j = len - 1; i < j; i++, j--) {
    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }
}
