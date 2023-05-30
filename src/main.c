/*
 * ECE 153B - Spring 2023
 *
 * Name(s):
 * Section:
 * Lab: 6A
 */

#include "stm32l476xx.h"
#include "SysClock.h"
#include "SysTimer.h"
#include "LED.h"
#include "CRC.h"
#include "UART.h"
#include <stdio.h>

/* Expected CRC Value */
#define uwExpectedCRCValue 0x5A60861E

static volatile uint32_t Software_ComputedCRC;
uint32_t microseconds;
int main(void) {
	
	// Switch System Clock = 80 MHz
	System_Clock_Init(); 
	SysTick_Init();
	LED_Init();
	UART2_GPIO_Init();
	UART2_Init();
	// TODO initialize modules
	
	while(1) {
		LED_Toggle();
		uint32_t currentCRC = INITIAL_CRC_VALUE;
		startTimer();

		
		for (int i = 0; i < BUFFER_SIZE; i++) {
			
			currentCRC = CrcSoftwareFunc(currentCRC, DataBuffer[i], POLYNOME);
			
		}
		microseconds = endTimer();
		if (currentCRC != uwExpectedCRCValue){
			
			LED_Off();
			break;
		}

		else {
			printf("%d", microseconds);
		}
		
		
		delay(1000);
		// initialize CRC
		// start timer
		// compute CRC
		// end timer
		// check CRC
		// print time
		// delay
	}
}
