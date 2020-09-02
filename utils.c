#include "utils.h"
#include "MKL25Z4.h" 

void utils_debug_output() {
	// enable clock on port
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
	
	// set pin to gpio
	PORTD->PCR[UTILS_DEBUG_OUPUT_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[UTILS_DEBUG_OUPUT_PIN] |= PORT_PCR_MUX(1);
	
	// set direction of pin
	PTD->PDDR |= MASK(UTILS_DEBUG_OUPUT_PIN);
	
	// set voltage to high
	PTD->PDOR = MASK(UTILS_DEBUG_OUPUT_PIN);
}
