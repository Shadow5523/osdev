#include "include/stdio.h"

int sh_printf(const unsigned char* format, ...){
  va_list parameter;
  int count = 0, num = 0;
  size_t amount = 0;
  size_t len;

  va_start(parameter, format);

  while (*format != '\0') {
    size_t maxrem = INT_MAX - count;
    if (format[0] != '%' || format[1] == '%') {
      if (format[0] == '%') { ++format; }
      amount = 1;
      while (format[amount] && format[amount] != '%') { ++amount; }
      if (maxrem < amount) { return -1; }
      if (!print(format, amount)) { return -1; }
      format += amount;
      count += amount;
      continue;
    }

    const char* format_begun_at = format++;

    switch (*format) {
    case 's':
      ++format;
      const char* str3 = va_arg(parameter, const char*);
      if (!data_to_print(str3)) { return -1; }
      break;

    case 'c':
      ++format;
      unsigned char str4[2];
      str4[0] = (char)va_arg(parameter, int);
      str4[1] = '\0';
      if (!data_to_print(str4)) { return -1; }
      break;

    case 'i':
    case 'd':
      ++format;
      unsigned char str1[8];
      num = va_arg(parameter, int);
      sh_itoa(num, str1, 10);
      if (!data_to_print(str1)) { return -1; }
      break;

    case 'x':
      ++format;
      unsigned char str2[8];
      num = va_arg(parameter, int);
      sh_itoa(num, str2, 16);
      if (!data_to_print(str2)) { return -1; }
      break;

    default:
      format = format_begun_at;
      if ((len = sh_strlen(format) - 1) > maxrem) { return -1; }
      data_to_print(format);
      format += len;
      count += len;
    }
    num = 0;
  }
  va_end(parameter);
  return 0;
}


int data_to_print(const unsigned char* str) {
  size_t len;
  len = sh_strlen(str) + 1;
  if (!print(str, len)) {return -1; }
  return 0;
}


static bool print(const unsigned char* data, size_t length) {
  const unsigned char* bytes = (const unsigned char*) data;
  size_t i;
  for (i = 0; i < length; i++)
    if (sh_putchar(bytes[i]) == '\0') { return false; }
  return true;
}


int sh_putchar(int intchar) {
  char ch = (char) intchar;
  terminal_write(&ch, sizeof(ch));
  return intchar;
}
