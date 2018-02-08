#ifndef _STRING_H_
#define _STRING_H_

#include <stddef.h>
#include <stdint.h>

size_t sh_strlen(const uint8_t*);
void sh_strrev(unsigned char*);
char* sh_strcpy(char*, const char*);
char* sh_strcat(char*, const char*);
void* sh_memcpy(void* restrict, const void* restrict, size_t);

#endif _STDIO_H_
