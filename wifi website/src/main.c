/*
 * main.c
 *
 *  Created on: Aug 8, 2022
 *      Author: Omar Gamal
 */

#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "SYSTICK_interface.h"
#include "USART_interface.h"

//#include "OS_interface.h"
#include "Experience.h"

void USART_PR(){

	//TRX(hello_world, sizeof(hello_world));
		ESP_voidInit();
		ESP_u8ConnectToWIFI();
		ESP_ConnectToSite();
		ESP_ESP_u8Send();
		ESP_ESP_u8SGET();

}

int main(void)
{

	RCC_voidInit();

	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA);
	RCC_voidPeripheralClockEnable(RCC_APB2, USART1);

	USART_init();

	//GPIOA->MODER &= ~(GPIO_MODER_MODER9 | GPIO_MODER_MODER10);
	  //GPIOA->MODER |= (GPIO_MODER_MODER9_1 | GPIO_MODER_MODER10_1);
		GPIO_voidSetPinMode(GPIO_PORTA, 9, GPIO_PIN_MODE_AF_PP_10MHZ);
		GPIO_voidSetPinMode(GPIO_PORTA, 1, GPIO_PIN_MODE_GP_PP_10MHZ);
		GPIO_voidSetPinMode(GPIO_PORTA, 2, GPIO_PIN_MODE_GP_PP_10MHZ);
		GPIO_voidSetPinMode(GPIO_PORTA, 3, GPIO_PIN_MODE_GP_PP_10MHZ);
		GPIO_voidSetPinMode(GPIO_PORTA, 4, GPIO_PIN_MODE_GP_PP_10MHZ);
		GPIO_voidSetPinMode(GPIO_PORTA, 5, GPIO_PIN_MODE_GP_PP_10MHZ);

		GPIO_voidSetPinMode(GPIO_PORTA, 10, GPIO_PIN_MODE_FLOATING_INPUT);

		USART_PR();


	while(1);

	return 0;
}

