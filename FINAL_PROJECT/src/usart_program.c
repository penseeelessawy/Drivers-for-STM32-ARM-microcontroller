/*
 * usart_program.c
 *
 *  Created on: Aug 20, 2022
 *      Author: ppppp
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"
#include "GPIO_interface.h"
#include "array_shared.h"

#include "Experience.h"
#define MAX_BUFFER_LENGTH 1000
void USART_voidInitSend(void) {
	USART_voidENABLE_USART(); // enable the usart
	SET_BIT(reg_USART1->USART_CR1, 3); // enable the usart to send and recive
	SET_BIT(reg_USART1->USART_CR1, 2);
	SET_BIT(reg_USART1->USART_CR3, 7);
	SET_BIT(reg_USART1->USART_CR3, 6);  //DMA mode is enabled for reception
	reg_USART1->USART_BRR = 0x342;

}

void USART_voidENABLE_USART() {
	SET_BIT(reg_USART1->USART_CR1, 13);

}

void USART_voidENABLE_SEND_BREAK() {
	SET_BIT(reg_USART1->USART_CR1, 0);

}
void USART_voidENABLE_INTERREUPT() {
	SET_BIT(reg_USART1->USART_CR1, 4);
	SET_BIT(reg_USART1->USART_CR1, 5);
	SET_BIT(reg_USART1->USART_CR1, 6);
	SET_BIT(reg_USART1->USART_CR1, 7);

}
int INDEX = 0;
int Length = 0;
int check = 0;
void USART_voidSendChar(void) {
	reg_USART1->USART_DR = (u32) 0x00000000; // reset every time the DR
	while (!(GET_BIT(reg_USART1->USART_SR, 5)))
		; //waiting for sending a char
	CLR_BIT(reg_USART1->USART_SR, 5); // clear the flag

	DMA_voidEnable1(); //enable the DMA to recieve

}

