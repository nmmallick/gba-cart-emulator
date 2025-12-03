#ifndef SYSTICK_H
#define SYSTICK_H

#include <common.h>

#define SYSTEM_TIMER_BASE_ADDR 0xe000e010

#define ENABLE_TICKINT 0x0002
#define DISABLE_TICKINT ~ENABLE_TICKINT

#define ENABLE_SYSTICK 0x0001
#define DISABLE_SYSTICK ~ENABLE_SYSTICK

#define SYSTICK_RELOAD_RESET 0x00000000
#define SYSTICK_COUNTER_RESET 0x00000000

typedef struct _SYSTICK {
    _MMAP_REGION STK_CTRL;
    _MMAP_REGION STK_LOAD;
    _MMAP_REGION STK_VAL;
    _MMAP_REGION STK_CALIB;
} _SYSTICK __attribute__((aligned(sizeof(_MMAP_REGION))));

static volatile struct _SYSTICK *SYSTICK __attribute__((unused)) = (struct _SYSTICK *) SYSTEM_TIMER_BASE_ADDR;

#endif
