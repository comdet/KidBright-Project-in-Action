#include "esp_system.h"
#include "kidbright32.h"
#include "kbpcf8574.h"

#define SDA_GPIO 4
#define SCL_GPIO 5

static i2c_dev_t i2c_driver;

KBPCF8574::KBPCF8574(void) {
	//
}
void KBPCF8574::begin(uint8_t address){
	i2cdev_init();
	pcf8574_init_desc(&i2c_driver, (i2c_port_t)1, address,(gpio_num_t) SDA_GPIO,(gpio_num_t) SCL_GPIO);

}
void KBPCF8574::write(uint8_t address,int pin,int value){
	uint8_t data = value << pin;
	pcf8574_port_write(&i2c_driver, data);
}
int KBPCF8574::read(uint8_t address,int pin){
	uint8_t data = 0;
	pcf8574_port_read(&i2c_driver, &data);
	return (1 << pin) & data;
}
