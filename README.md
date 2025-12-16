# Gameboy Flash Cart
A flash cartridge for the Gameboy Advance SP (GBA SP) using the STM32F401 which can emulate digital ROMs on the original hardware.

## Install Dependencies
### Install the Arm Toolchain

Download the most recent 32-bit, bare-metal [arm toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads) (arm-none-eabi) for your operating system.

Add the toolchain to your path.

**Linux + MacOS**
```
export PATH=$PATH:/path/to/toolchain/install
```


### Install STLINK Tools

Install STLINK Tools as specified in the [stlink](https://github.com/stlink-org/stlink) repository.

**MacOS**
```
brew install stlink
```

## Building Target

Getting the code to run on the microncontroller consists of Clean -> Build -> Flash.

### [Optional] Clean

Optionally clean the intermediate files for a fresh build.

```
make clean
```

### Build
Build with or without debug symbols.

```
make
```

or

```
make DEBUG=1
```

### Flash
Flash the build files to the microcontroller.

```
make flash
```


## Debugging With GDB
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

## Acknowledgments
- [Gekkio](https://github.com/Gekkio) for their work chronicling gameboy hardware and software.