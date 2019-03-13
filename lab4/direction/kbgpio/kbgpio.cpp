#include "esp_system.h"
#include "kidbright32.h"
#include "kbgpio.h"
KBGPIO::KBGPIO(void) {
	//
}
void KBGPIO::setOutput(int pin) {
	gpio_config_t io_conf;
	// outputs init
	io_conf.intr_type = GPIO_INTR_DISABLE;          // disable interrupt
	io_conf.mode = GPIO_MODE_OUTPUT;                // set as output mode
	io_conf.pin_bit_mask = (1ULL << pin);           // pin bit mask
	io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;   // disable pull-down mode
	io_conf.pull_up_en = GPIO_PULLUP_DISABLE;       // disable pull-up mode
	gpio_config(&io_conf);
    gpio_set_level((gpio_num_t)pin, 1);      // active low
}

void KBGPIO::digitalWrite(int pin,int value)
{
    gpio_set_level((gpio_num_t)pin, value);
}
