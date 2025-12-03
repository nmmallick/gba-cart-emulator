# gba-cart-emulator

# Building Target
## Download the arm-none-eabi 32 bit toolchain
Look for the most recent 32-bit, bare-metal [arm toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads) (arm-none-eabi)

### TODO
Add specific links for MacOS, Linux downloads

## Add the toolchain to your path
### Linux + MacOS
export PATH=$PATH:/path/to/toolchain/install

### Build
`$ make`

### [Optional] Build with debug symbols
`$ make DEBUG=1`
