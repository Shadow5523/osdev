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


char* sh_strcpy(char *s1, const char *s2) {
  char* temp = s1;
  while ((*temp++ = *s2++) != 0);
  return s1;
}


char* sh_strcat(char *s1, const char *s2){
  size_t i,j;
  for (i = 0; s1[i] != '\0'; i++);
  for (j = 0; s2[j] != '\0'; j++)
    s1[i + j] = s2[j];
  s1[i + j] = '\0';
  return s1;
}


void* sh_memcpy(void* restrict dst_ptr, const void* restrict src_ptr, size_t size){
  unsigned char* dst = (unsigned char*)dst_ptr;
  const unsigned char* src = (const unsigned char*)src_ptr;
  for (size_t i = 0; i < size; i++) { dst[i] = src[i]; }
  return dst_ptr;
}
