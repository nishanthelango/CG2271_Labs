#include "utils.h"
#include "switch_service.h"
#include "led_service.h"

#include "MKL25Z4.h" 
void PORTD_IRQHandler() {
	// Clear Pending IRQ
	NVIC_ClearPendingIRQ(PORTD_IRQn);
	
	if (PORTD->ISFR & MASK(SWITCH_BUTTON_PIN)) {
			led_color = led_control(led_color);
	}
	
	// Clear INT Flag
	PORTD->ISFR |= MASK(SWITCH_BUTTON_PIN);
}
