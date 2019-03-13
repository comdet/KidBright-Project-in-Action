#include "esp_system.h"
#include "kidbright32.h"
#include "Servo.h"

Servo::Servo(){
	
}
void Servo::attach(int pin, double minuS, double maxuS, int ledcChannel){
    _min = 0xFFFF *  minuS / 20.0;
	_max = 0xFFFF * maxuS / 20.0;        
	_ledcChannel = static_cast<ledc_channel_t>(ledcChannel);

	ledc_timer_config_t timer_conf;
	timer_conf.duty_resolution = LEDC_TIMER_16_BIT;
	timer_conf.freq_hz = 50;
	timer_conf.speed_mode = LEDC_HIGH_SPEED_MODE;
	timer_conf.timer_num = LEDC_TIMER_3;
	ledc_timer_config(&timer_conf);

    ledc_channel_config_t ledc_conf;
	ledc_conf.channel = _ledcChannel;
	ledc_conf.duty = 0xFFFF;
	ledc_conf.gpio_num   = pin;
	ledc_conf.intr_type  = LEDC_INTR_DISABLE;
	ledc_conf.speed_mode = LEDC_HIGH_SPEED_MODE;
	ledc_conf.timer_sel  = LEDC_TIMER_3;
	ledc_channel_config(&ledc_conf);
}
void Servo::detach(){
	ledc_stop(LEDC_HIGH_SPEED_MODE, _ledcChannel, 0);
}

void Servo::write(unsigned int angle) {
	// 0 = MinServoAngle ; 180 = Max ServoAngle;    
	int uS = angle * (_max - _min) / 180.0 + _min;    
    ledc_set_duty(LEDC_HIGH_SPEED_MODE, _ledcChannel, uS);
	ledc_update_duty(LEDC_HIGH_SPEED_MODE, _ledcChannel);
}