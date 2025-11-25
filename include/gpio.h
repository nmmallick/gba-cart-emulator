#include <common.h>

// GPIO
#define GPIOH_BASE_ADDR 0x40021C00
#define GPIOH MMIO32(GPIOH_BASE_ADDR)

#define GPIOE_BASE_ADDR 0x40021000
#define GPIOE MMIO32(GPIOE_BASE_ADDR)

// GPIO A
#define GPIOA_BASE_ADDR 0x40020000

#define GPIO_MODE_IN 0x00
#define GPIO_MODE_OUT 0x01
#define GPIO_MODE_AF 0x02
#define GPIO_MODE_ANALOG 0x03

#define GPIO_OTYPE_PP 0x00 // push pull
#define GPIO_OTYPE_OD 0x01 // open drain

#define GPIO_SPEED_LOW 0x00
#define GPIO_SPEED_MED 0x01
#define GPIO_SPEED_HIGH 0x02
#define GPIO_SPEED_VERY_HIGH 0x03

#define GPIO_PUPDR_NONE 0x00
#define GPIO_PUPDR_PU 0x01
#define GPIO_PUPDR_PD 0x02

#define GPIO_HIGH 0x01
#define GPIO_LOW 0x00

typedef struct _GPIO {
    _MMAP_REGION MODER;
    _MMAP_REGION OTYPE;
    _MMAP_REGION OSPEED;
    _MMAP_REGION PUPDR;
    _MMAP_REGION IN;
    _MMAP_REGION OUT;
} _GPIO __attribute__((aligned(sizeof(_MMAP_REGION))));

static struct _GPIO *GPIOA __attribute__((unused)) = (struct _GPIO *) GPIOA_BASE_ADDR;

inline void set_gpio_mode(_GPIO *GPIO, uint8_t MODE, uint8_t pin) {
    GPIO->MODER |= MODE << (pin*2);
}

inline void set_gpio_otype(_GPIO *GPIO, uint8_t OTYPE, uint8_t pin) {
    GPIO->OTYPE |= OTYPE << pin;
}

inline void set_gpio_ospeed(_GPIO *GPIO, uint8_t OSPEED, uint8_t pin) {
    GPIO->OSPEED |= OSPEED << (pin*2);
}

inline void set_gpio_pupdr(_GPIO *GPIO, uint8_t PUPD, uint8_t pin) {
    GPIO->PUPDR |= PUPD << (pin*2);
}

inline void set_gpio_output(_GPIO *GPIO, uint8_t OUT, uint8_t pin) {
    GPIO->OUT |= OUT << pin;
}
