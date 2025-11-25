#include <gpio.h>

// RCC
#define RCC_BASE_ADDR 0x40023800
#define RCC MMIO32(RCC_BASE_ADDR)
#define RCC_AHB1ENR MMIO32(RCC_BASE_ADDR + 0x30)

void SystemInit() {
    // TODO: Clock initialization
    // Enable clock for GPIOA
    *RCC_AHB1ENR |= 0x01;

    set_gpio_mode(GPIOA, GPIO_MODE_OUT, 5);
    set_gpio_otype(GPIOA, GPIO_OTYPE_PP, 5);
    set_gpio_ospeed(GPIOA, GPIO_SPEED_LOW, 5);
    set_gpio_pupdr(GPIOA, GPIO_PUPDR_PD, 5);
    set_gpio_output(GPIOA, GPIO_HIGH, 5);
}

int main(void)
{
    return 0;
}
