#include "led_service.h"
#include "delay_service.h" 

int main() {
	led_init_gpio();
	color_t led_color = LED_BLUE_COLOR;
	while (1) {
		led_color = led_control(led_color);
		delay_program(0x0FFFFF); 
	}
}
