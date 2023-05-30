/*
 * ECE 153B - Spring 2023
 *
 * Name(s):
 * Section:
 * Lab: 6A
 */

#include "SysTimer.h"

static uint32_t volatile step;
uint32_t volatile msTicks;

void SysTick_Init(void) {
	// SysTick Control & Status Register
	SysTick->CTRL = 0; // Disable SysTick IRQ and SysTick Counter
	
	// Enables SysTick exception request
	// 1 = counting down to zero asserts the SysTick exception request
	// 0 = counting down to zero does not assert the SysTick exception request
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
	
	// Select clock source
	// If CLKSOURCE = 0, the external clock is used. The frequency of SysTick clock is the frequency of the AHB clock divided by 8.
	// If CLKSOURCE = 1, the processor clock is used.
	// TODO
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
	
	// Configure and Enable SysTick interrupt in NVIC
	NVIC_EnableIRQ(SysTick_IRQn);
	NVIC_SetPriority(SysTick_IRQn, 1); // Set Priority to 1
}

void SysTick_Handler(void) {
	//TODO
	++msTicks;
}

void delay(uint32_t ms) {
	//TODO
	msTicks = 0;
	SysTick->VAL = 0;
	SysTick->LOAD = 79999;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	
	uint32_t currentTicks;
	for (uint32_t i = 0; i < ms; i++) {
		currentTicks = msTicks;
		while (currentTicks == msTicks);
	}
	SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk);
}

void startTimer(void) {
	//TODO
	msTicks = 0;
	SysTick->VAL = 0;
	SysTick->LOAD = 79999;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

uint32_t endTimer(void) {
	SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk);
	uint32_t steps = SysTick->VAL;
	
	
	return (msTicks*1000 + (79999-steps) * 0.0125);//TODO
}
