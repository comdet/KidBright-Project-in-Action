#ifndef __SERVO_H__
#define __SERVO_H__
#include "driver.h"
#include "device.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include <freertos/FreeRTOS.h>
#include "esp_timer.h"
#include "freertos/task.h"
class Servo : public Device {
	private:
		ledc_channel_t _ledcChannel;
		double _min;
		double _max;
	public:
		// constructor
		Servo();
		// override
		void inline init(void){ return; };
		void inline process(Driver *drv){ error = false; initialized = true; }
		int inline prop_count(void){ return 0; }
		bool inline prop_name(int index, char *name){ return false; }
		bool inline prop_unit(int index, char *unit){ return false; }
		bool inline prop_attr(int index, char *attr){ return false; }
		bool inline prop_read(int index, char *value){ return false; }
		bool inline prop_write(int index, char *value){ return false; }
		// method	
		void attach(int pin, double minuS = 0.5, double maxuS = 2.5, int ledcChannel = 0);
		void detach();
		void write(unsigned int value);
};
#endif
