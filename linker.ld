/* linker.ld - A simple linker script for a bare-metal OS kernel */

/* Define where the kernel will be loaded in memory */
OUTPUT_ARCH(i386)               /* Change to x86_64 if you're targeting 64-bit */
ENTRY(start)                    /* The entry point function name, e.g., 'start' */
SECTIONS
{
    /* Place the kernel at memory address 0x00100000 (1MB) */
    . = 0x00100000;

    /* The text section (code) */
    .text : {
        *(.multiboot)           /* Multiboot header (if using one) */
        *(.text)                /* Kernel code */
        *(.rodata)              /* Read-only data (like strings) */
    }

    /* The data section (initialized data) */
    .data : {
        *(.data)
    }

    /* The bss section (uninitialized data) */
    .bss : {
        *(.bss)
        *(COMMON)
    }

    /* Set the final memory address for the end of the kernel */
    _end = .;
}
