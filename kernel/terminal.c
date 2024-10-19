//This is a file for handling terminal inputs and terminal output

//Imports
#include "terminal.h"
#include "vga.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

uint16_t* const VGA_BUFFER = (uint16_t*) 0xB8000;
uint8_t terminal_row = 0;
uint8_t terminal_column = 0;

void terminal_initialize() {
    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            terminal_putchar_at(' ', x, y);
        }
    }
    terminal_row = 0;
    terminal_column = 0;
}

void terminal_putchar_at(char c, uint8_t x, uint8_t y) {
    const uint16_t color = VGA_COLOR_WHITE | (VGA_COLOR_BLACK << 4);
    VGA_BUFFER[y * VGA_WIDTH + x] = (uint16_t) c | (color << 8);
}

void terminal_writestring(const char* str) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        terminal_putchar_at(str[i], terminal_column, terminal_row);
        terminal_column++;
        if (terminal_column >= VGA_WIDTH) {
            terminal_column = 0;
            terminal_row++;
            if (terminal_row >= VGA_HEIGHT) {
                terminal_row = 0;
            }
        }
    }
}
