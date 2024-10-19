#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdint.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

// VGA color codes for text and background
#define VGA_COLOR_BLACK 0
#define VGA_COLOR_WHITE 15

// Declare the terminal functions
void terminal_initialize();
void terminal_putchar_at(char c, uint8_t x, uint8_t y);
void terminal_writestring(const char* str);

#endif // TERMINAL_H
