CC = gcc
CFLAGS = -ffreestanding -nostdlib -g
LD = ld
LDFLAGS = -T linker.ld
KERNEL_BIN = simple_os.bin
KERNEL_SRC = kernel/kernel.c kernel/terminal.c kernel/window.c kernel/keyboard.c kernel/memory.c

# Object directory
OBJ_DIR = build
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(KERNEL_SRC:.c=.o)))

# Default target
all: $(KERNEL_BIN)

# Ensure the build directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Build the kernel binary
$(KERNEL_BIN): $(OBJ)
	$(LD) $(LDFLAGS) -o $(KERNEL_BIN) $(OBJ)

# Compile the C source files to object files
$(OBJ_DIR)/%.o: kernel/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and binaries
clean:
	rm -rf $(OBJ_DIR) $(KERNEL_BIN)
