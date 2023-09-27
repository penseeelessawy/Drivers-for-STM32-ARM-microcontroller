/*
 * usart_program.c
 *
 *  Created on: Aug 20, 2022
 *      Author: ppppp
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STDIO.h"
#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"
#include "GPIO_interface.h"

#include "Experience.h"
#define MAX_BUFFER_LENGTH 1000
void USART_init(void) {
	USART_voidENABLE_USART();
	SET_BIT(reg_USART1->USART_CR1, 12);
	SET_BIT(reg_USART1->USART_CR1, 3);
	SET_BIT(reg_USART1->USART_CR1, 2);
	//SET_BIT(reg_USART1->USART_CR1, 11);

	//SET_BIT(reg_USART1->USART_CR2, 11);
	reg_USART1->USART_BRR = 0x30D;

	//USART_voidENABLE_INTERREUPT();

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
void TRX(const char * str, u8 size) {

		for (int idx = 0; idx < size; idx++) {
			for (int i = 300 * 1500; i >= 0; i--)
				;
			//	GPIO_voidSetPinValue(GPIO_PORTA, 1, GPIO_HIGH);
			reg_USART1->USART_DR = str[idx];

			while (!( GET_BIT(reg_USART1->USART_SR, 6)
					& GET_BIT(reg_USART1->USART_SR, 7))) {
				GPIO_voidSetPinValue(GPIO_PORTA, 1, GPIO_HIGH);

			}
			for (int i = 300 * 10500; i >= 0; i--)
				;
		//	GPIO_voidSetPinValue(GPIO_PORTA, 1, GPIO_LOW);

		}


}

int INDEX= 0 ;
int Length = 0;
char Buffer[1000];
void strReceive(void) {
		while (!(GET_BIT(reg_USART1->USART_SR, 5))) ;
			Buffer[INDEX] = reg_USART1->USART_DR;
			INDEX++; }

ESP_voidInit(void)
{

	TRX(ECHO, sizeof(ECHO));
	strReceive();
	while(!(Buffer[INDEX-1]=='K'));
	TRX(TEST, sizeof(TEST));
	strReceive();
	while(!(Buffer[INDEX-1]=='K'));
	TRX(CONFIG, sizeof(CONFIG));
	strReceive();
		while(!(Buffer[INDEX-1]=='K'));



}
void ESP_u8ConnectToWIFI()
{ 	TRX(CONNECT_WIFI, sizeof(CONNECT_WIFI));
strReceive();
		while(!(Buffer[INDEX-1]=='K'));
}
void ESP_ConnectToSite()
{ 	TRX(CONNECT_SITE, sizeof(CONNECT_SITE));
strReceive();
		while(!(Buffer[INDEX-1]=='K')){
			strReceive();
		}
}
void ESP_ESP_u8Send()
{ 	TRX(SEND, sizeof(SEND));
strReceive();
		while(!(Buffer[INDEX-1]=='K')){
			strReceive();
		}

}
void ESP_ESP_u8SGET()
{ 	TRX(GET ,sizeof(GET));
strReceive();
		while(!(Buffer[INDEX-1]=='K')){
			strReceive();
		}

}
