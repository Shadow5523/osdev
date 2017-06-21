#include "terminal.h"
#include "vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminal_initialize(void){
  terminal_row = 0;
  terminal_column = 0;
  terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK);
  terminal_buffer = (uint16_t*) 0xB8000;   //テキストバッファはこのアドレスから始まる
  for(size_t y = 0; y < VGA_HEIGHT; y++) {
    for(size_t x = 0; x < VGA_WIDTH; x++) {
      const size_t index = y * VGA_WIDTH + x;
      terminal_buffer[index] = vga_entry(' ', terminal_color);

    }

  }

}



void terminal_setcolor(uint8_t color){
  terminal_color = color;

}



void terminal_putentryat(char c, uint8_t color, size_t x, size_t y){
  const size_t index = y * VGA_WIDTH + x;
  terminal_buffer[index] = vga_entry(c, color);

}



void terminal_uponerow(void){
  for(size_t y = 1; y < VGA_HEIGHT; y++){
    for(size_t x = 0; x < VGA_WIDTH; x++){
      const size_t index = y * VGA_WIDTH + x;
      terminal_buffer[(y - 1) * VGA_WIDTH + x] = terminal_buffer[index];
      if(y == (VGA_HEIGHT - 1)){
        terminal_buffer[index] = vga_entry(' ', terminal_color);

      }

    }

  }

}



void terminal_putchar(char c){
  if(c == '\n'){
    c = 0;
    if(++terminal_row >= VGA_HEIGHT){
      terminal_uponerow();
      terminal_row--;
      terminal_column = -1;

    }else{
      terminal_column = -1;

    }

  }else if(c == '\t'){
    c = 0;
    terminal_column += 4;

  }else if(c == '\b'){
    c = 0;
    terminal_buffer[(terminal_row * VGA_WIDTH + terminal_column) - 1] = vga_entry(' ', terminal_color);
    if(--terminal_column <= 0){
      terminal_column = VGA_WIDTH;
      if(--terminal_row < 2){
        terminal_row = 2;
        terminal_column = 0;

      }

    }
    return;

  }

  terminal_putentryat(c, terminal_color, terminal_column, terminal_row);

  if(++terminal_column >= VGA_WIDTH){
    terminal_column = 0;
    if(++terminal_row >= VGA_HEIGHT){
      terminal_uponerow();
      terminal_row--;

    }

  }

}



void terminal_write(const char* data, size_t size){
  for(size_t i = 0; i < size; i++)
    terminal_putchar(data[i]);

}



void terminal_writestring(const char* data){
  terminal_write(data, strlen(data));

}
