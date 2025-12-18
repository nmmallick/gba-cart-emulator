#ifndef FLASH_H
#define FLASH_H

#include <common.h>

#define FLASH_BASE_ADDR 0x40023c00

typedef struct _FLASH {
    _MMAP_REGION FLASH_ACR;
    _MMAP_REGION FLASH_KEYR;
    _MMAP_REGION FLASH_OPTKEYR;
    _MMAP_REGION FLASH_SR;
    _MMAP_REGION FLASH_CR;
    _MMAP_REGION FLASH_OPTCR;
} _FLASH __attribute__((aligned(sizeof(_MMAP_REGION))));

static struct _FLASH *FLASH __attribute__((unused)) = (struct _FLASH *) FLASH_BASE_ADDR;

#endif
