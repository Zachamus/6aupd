/*
 * ECE 153B - Spring 2023
 *
 * Name(s):
 * Section:
 * Lab: 6A
 */
 
#include "LED.h"

void LED_Init(void){
	//TODO
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; 
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
		GPIOA->MODER &= ~(3UL<<10);
		GPIOA->MODER |= 1UL<<10;
		GPIOA->PUPDR &= ~(3UL<<10);
		GPIOA->OTYPER &= ~(1UL<<5);
		GPIOA->ODR &= ~(1UL << 5);
}

void LED_On(void){
	//TODO
	GPIOA->ODR |= (1UL << 5);
}

void LED_Off(void){
	//TODO
	GPIOA->ODR &= ~(1UL << 5);
}

void LED_Toggle(void){
	//TODO
	GPIOA->ODR ^= (1UL << 5);
}
