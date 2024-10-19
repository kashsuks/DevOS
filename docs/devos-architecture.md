# DevOS Architecture

## Bootloader
- Uses GRUB to load the kernel.
- `grub.cfg` configures GRUB to boot the `simple_os.bin` kernel binary.

## Kernel
- A simple, monolithic kernel.
- Initially supports a basic terminal, window management, and keyboard input.
- Memory management and multitasking will be added later.

## Future Plans
- Add process management and multitasking.
- Implement filesystem support.
- Develop GUI for a more interactive user experience.
