# gba-cart-emulator

# Building Target
## Download the arm-none-eabi 32 bit toolchain
Look for the most recent 32-bit, bare-metal [arm toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads) (arm-none-eabi)

## Download the stlink tooling
[stlink installation](https://github.com/stlink-org/stlink?tab=readme-ov-file#installation)

### TODO
Add specific links for MacOS, Linux downloads

## Add the toolchain to your path
### Linux + MacOS
`export PATH=$PATH:/path/to/toolchain/install`

## Build
`$ make`

## [Optional] Build with debug symbols
`$ make DEBUG=1`

## Flash to the target
`$ make flash`

# Debugging With GDB
> **_NOTE:_** You must build the binary with debug symbols

While your stlink device is plugged in, run the `st-util` tool.

`$ st-util`

You must have the toolchain installed described in the [build step](#Build-Target). 
Assuming you've exported the toolcahin path to $PATH, run the `arm-none-eabi-gdb` application which ships with the toolchain in a separate window.

`$ arm-none-eab-gdb build/output.elf`

In your gdb instance, connect to the st-util instance running the gdb server.

`(gdb) target extend localhost:4242`

Optionally, set source directories

`(gdb) set directories src/`

Run the application

`(gdb) run`

## Helpful GDB commands
* Dump memory address
`(gdb) x 0x<address>`

* Set breakpoint
`(gdb) b main.c:22`
