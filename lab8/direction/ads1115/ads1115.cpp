#include "esp_system.h"
#include "kidbright32.h"
#include "ads1115.h"

#define SDA_GPIO 4
#define SCL_GPIO 5
#define ADDRESS ADS111X_ADDR_GND // connect ADDR pin to GND
#define GAIN ADS111X_GAIN_4V096  //!< +-4.096V

static i2c_dev_t dev;

ADS1115::ADS1115(void) {
	//
}
void ADS1115::begin(uint8_t address){
    i2cdev_init();
    ads111x_init_desc(&dev, address,(i2c_port_t) 1,(gpio_num_t) SDA_GPIO,(gpio_num_t) SCL_GPIO);

    ads111x_set_mode(&dev, ADS111X_MODE_CONTUNOUS);
    ads111x_set_data_rate(&dev, ADS111X_DATA_RATE_32);

    ads111x_set_input_mux(&dev, ADS111X_MUX_0_GND);
    ads111x_set_gain(&dev, GAIN);
}
float ADS1115::read(uint8_t address,int pin){
	float gain_val = ads111x_gain_values[GAIN];
    // wait for conversion end
    bool busy;
    do{
        ads111x_is_busy(&dev, &busy);
    }while (busy);
    // Read result
    int16_t raw = 0;
    float voltage = -1;
    if(pin == 0){
    	ads111x_set_input_mux(&dev, ADS111X_MUX_0_GND);
    }else if(pin == 1){
    	ads111x_set_input_mux(&dev, ADS111X_MUX_1_GND);
    }else if(pin == 2){
    	ads111x_set_input_mux(&dev, ADS111X_MUX_2_GND);
    }else if(pin == 3){
    	ads111x_set_input_mux(&dev, ADS111X_MUX_3_GND);
    }
    if (ads111x_get_value(&dev, &raw) == ESP_OK)
    {
    	voltage = gain_val / ADS111X_MAX_VALUE * raw;
        printf("Raw ADC value: %d, voltage: %.04f volts\n", raw, voltage);
    }else{
    	printf("Cannot read ADC value\n");
    }
    return voltage;
}
