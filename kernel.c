#include <stdint.h>

#define VIDEO_MEMORY 0xB8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

// VGA text mode video memory
static uint16_t* const videoMemory = (uint16_t*)VIDEO_MEMORY;

void clearScreen() {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        videoMemory[i] = (0x0F << 8) | ' ';  // Light grey on black background
    }
}

void printChar(char character, int x, int y) {
    videoMemory[y * SCREEN_WIDTH + x] = (0x0F << 8) | character;
}

void printString(const char* str, int x, int y) {
    int i = 0;
    while (str[i] != '\0') {
        printChar(str[i], x + i, y);
        i++;
    }
}

// Entry point for the kernel
void kernelMain() {
    clearScreen();
    printString("Welcome to DevOS!", 30, 10);
    printString("Type 'exit' to close the terminal.", 30, 12);

    // Simple terminal loop (reads input from the user and echoes it)
    char command[100];
    int commandIndex = 0;

    while (1) {
        printString(">", 0, 14);
        // For now, let's just handle very basic input (characters)
        char c;
        int i = 0;
        while (1) {
            // Get a character from the user (in real systems, this would interact with hardware or BIOS)
            c = getCharFromKeyboard();  // Implement this function in the next steps
            if (c == '\n') {
                command[i] = '\0'; // Null-terminate the string
                break;
            }
            command[i++] = c;
        }
        
        // Handle commands
        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "clear") == 0) {
            clearScreen();
        } else {
            printString(command, 0, 16);
        }
    }
}
