#include <gpio.h>
#include <systick.h>
#include <clock.h>

static uint32_t count = 0;
static uint8_t value = 0;

void SystemInit() {
    // Set PLL M=8, N=84, P=2
    SET_PLLM(8);
    SET_PLLN(84);
    SET_PLLP(2);

    // Set PLL clock input source to HSI
    // Turn on PLL and HSI clocks and turn off HSE for power consumption
    RCC->RCC_CR |= PLL_ON | HSI_ON;
    RCC->RCC_CR &= HSE_OFF;

    while (!PLL_IS_RDY());

    // Set the system clock to use the PLL clock
    RCC->RCC_CFGR |= SYS_CLOCK_PLL;

    while (((RCC->RCC_CFGR >> 2) & 0x3) != SYS_CLOCK_PLL);

    // Enable clock for GPIOA
    RCC->RCC_AHB1ENR |= 0x01;

    // setup gpio pin A5
    set_gpio_mode(GPIOA, GPIO_MODE_OUT, 5);
    set_gpio_otype(GPIOA, GPIO_OTYPE_PP, 5);
    set_gpio_ospeed(GPIOA, GPIO_SPEED_LOW, 5);
    set_gpio_pupdr(GPIOA, GPIO_PUPDR_PD, 5);
    set_gpio_output(GPIOA, GPIO_HIGH, 5);

    // setup systick
    SYSTICK->STK_LOAD = SYSTICK_RELOAD_RESET;
    SYSTICK->STK_VAL = SYSTICK_COUNTER_RESET;

    SYSTICK->STK_LOAD = 0x00000001;
    SYSTICK->STK_CTRL |= ENABLE_SYSTICK | ENABLE_TICKINT;
}

void SysTick_Handler() {
    count++;
 
    if (count == 1000) {
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
