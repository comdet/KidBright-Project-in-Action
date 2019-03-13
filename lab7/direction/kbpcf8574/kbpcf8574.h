#ifndef __KBPCF8574_H__
#define __KBPCF8574_H__
#include "driver.h"
#include "device.h"
#include "driver/gpio.h"

#include "pcf8574.h"

class KBPCF8574 : public Device {
	private:		
	public:
		// constructor
		KBPCF8574(void);
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
		void write(uint8_t address,int pin,int value);
		int read(uint8_t address,int pin);
};
#endif
