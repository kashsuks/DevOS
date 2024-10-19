//This file is the entry point for the kernel

//Imports
#include "terminal.h"

void kernel_main() {
    // Set up terminal and print a message
    terminal_initialize();
    terminal_writestring("Welcome to DevOS!\n");

    // You can add more initialization code here later
    while (1) {
        // Infinite loop to keep the OS running
    }
}
