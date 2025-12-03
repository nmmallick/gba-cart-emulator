#include <gpio.h>
#include <systick.h>
#include <clock.h>

// RCC
#define RCC_BASE_ADDR 0x40023800
#define RCC MMIO32(RCC_BASE_ADDR)
#define RCC_AHB1ENR MMIO32(RCC_BASE_ADDR + 0x30)

static uint32_t count = 0;
static uint8_t value = 0;

void SystemInit() {
    // TODO: Clock initialization
    // Enable clock for GPIOA
    *RCC_AHB1ENR |= 0x01;

    // setup gpio pin A5
    set_gpio_mode(GPIOA, GPIO_MODE_OUT, 5);
    set_gpio_otype(GPIOA, GPIO_OTYPE_PP, 5);
    set_gpio_ospeed(GPIOA, GPIO_SPEED_LOW, 5);
    set_gpio_pupdr(GPIOA, GPIO_PUPDR_PD, 5);
    set_gpio_output(GPIOA, GPIO_LOW, 5);

    // setup systick
    SYSTICK->STK_LOAD = SYSTICK_RELOAD_RESET;
    SYSTICK->STK_VAL = SYSTICK_COUNTER_RESET;

    SYSTICK->STK_LOAD = 0x00000001;
    SYSTICK->STK_CTRL |= ENABLE_SYSTICK | ENABLE_TICKINT;
}

void SysTick_Handler() {
    count++;

    if (count == 100000) {
	if (value) {
	    set_gpio_output(GPIOA, GPIO_LOW, 5);
	    value = 0;
	} else {
	    set_gpio_output(GPIOA, GPIO_HIGH, 5);
	    value = 1;
	}

	count = 0;
    }
}

int main(void)
{
    while (1);

    return 0;
}
