#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

#define MMIO32(addr) ((volatile uint32_t*)(addr))

#define _MMAP_REGION volatile uint32_t

#define _RESERVED_ uint32_t : 32

#endif
