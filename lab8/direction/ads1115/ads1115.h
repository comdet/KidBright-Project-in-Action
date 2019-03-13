#ifndef __ADS1115_H__
#define __ADS1115_H__
#include "driver.h"
#include "device.h"
#include "driver/gpio.h"

#include "ads111x.h"

class ADS1115 : public Device {
	private:		
	public:
		// constructor
		ADS1115(void);
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
		void begin(uint8_t address);		
		float read(uint8_t address,int pin);
};
#endif
