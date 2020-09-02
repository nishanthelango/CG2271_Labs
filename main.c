#include "led_service.h"
#include "delay_service.h"
#include "utils.h"

#include "MKL25Z4.h" 

#define SW_POS 6

#define MASK(x) (1 << (x))

void initSwitch(void) {
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
	
	PORTD->PCR[SW_POS] |= (PORT_PCR_MUX(1) |
	PORT_PCR_PS_MASK |
	PORT_PCR_PE_MASK |
	PORT_PCR_IRQC(0x0a));
	
	PTD->PDDR &= ~MASK(SW_POS);
	
	NVIC_SetPriority(PORTD_IRQn, 2);
	NVIC_ClearPendingIRQ(PORTD_IRQn);
	NVIC_EnableIRQ(PORTD_IRQn);
}

color_t  led_color = LED_BLUE_COLOR;

void PORTD_IRQHandler() {
	NVIC_ClearPendingIRQ(PORTD_IRQn);
	
	led_color = led_control(led_color);
	
	PORTD->ISFR |= MASK(SW_POS);
}



void test_output() {
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
	PORTD->PCR[SW_POS] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[SW_POS] |= PORT_PCR_MUX(1);
	PTD->PDDR |= MASK(SW_POS);
	PTD->PDOR = MASK(SW_POS);
}

int main() {
 initSwitch();
	led_init_gpio();
	while(1);
}