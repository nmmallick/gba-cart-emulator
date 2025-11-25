#include <stdint.h>

#define MMIO32(addr) ((volatile uint32_t*)(addr))

#define _MMAP_REGION volatile uint32_t
