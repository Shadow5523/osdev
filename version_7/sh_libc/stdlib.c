#include "include/stdlib.h"

void sh_itoa(int data, unsigned char* str, int base){
  size_t i = 0;
  int data2 = data;
  int num;
  do {
    num = data2 % base;
    if (num < 0x0A) {
      str[i++] = '0' + num;
    } else {
      str[i++] = 'A' + num  - 0x0A;
    }
    data2 /= base;
  } while (data2);
  str[i] = '\0';
  sh_strrev(str);
}
