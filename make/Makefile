# Simple OS Makefile

CC = gcc
CFLAGS = -ffreestanding -nostdlib -g
LD = ld
LDFLAGS = -T linker.ld
KERNEL_BIN = simple_os.bin
KERNEL_SRC = kernel.c terminal.c window.c keyboard.c memory.c

# List of object files
OBJ = $(KERNEL_SRC:.c=.o)

# Default target
all: $(KERNEL_BIN)

# Build the kernel binary
$(KERNEL_BIN): $(OBJ)
    $(LD) $(LDFLAGS) -o $(KERNEL_BIN) $(OBJ)

# Compile the C source files to object files
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and binaries
clean:
    rm -f $(OBJ) $(KERNEL_BIN)
