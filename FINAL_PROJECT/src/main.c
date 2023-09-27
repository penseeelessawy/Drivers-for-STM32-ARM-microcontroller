/*
 * main.c
 *
 *      Author: Pensee
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "SYSTICK_interface.h"
#include "USART_interface.h"
#include "SPI_interface.h"
#include "DMA_interface.h"



int main(void) {

	RCC_voidInit(); //enabling the RCC
	RCC_voidPeripheralClockEnable(RCC_APB2, GPIOA); //Enable the GPIO port pins
	RCC_voidPeripheralClockEnable(RCC_APB2, USART1);
	RCC_voidPeripheralClockEnable(RCC_AHB, DMA1);
	RCC_voidPeripheralClockEnable(RCC_AHB, DMA2);
	RCC_voidPeripheralClockEnable(RCC_APB2, SPI1);
	//enabling the config of usart terminal port
	GPIO_voidSetPinMode(GPIO_PORTA, 9, GPIO_PIN_MODE_AF_PP_10MHZ);
	GPIO_voidSetPinMode(GPIO_PORTA, 1, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinMode(GPIO_PORTA, 2, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinMode(GPIO_PORTA, 3, GPIO_PIN_MODE_GP_PP_10MHZ);
	//enabling the config of  spi dubgger

	GPIO_voidSetPinMode(GPIO_PORTA, 10, GPIO_PIN_MODE_FLOATING_INPUT);
	GPIO_voidSetPinMode(GPIO_PORTA, 7, GPIO_PIN_MODE_AF_PP_10MHZ);
	GPIO_voidSetPinMode(GPIO_PORTA, 6, GPIO_PIN_MODE_PULLING_INPUT);
	GPIO_voidSetPinMode(GPIO_PORTA, 5, GPIO_PIN_MODE_AF_PP_10MHZ);
	GPIO_voidSetPinMode(GPIO_PORTA, 4, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_voidSetPinValue(GPIO_PORTA, 4, GPIO_LOW); //enable the slave

	while (1) {
		DMA_voidInitUsartReceive(); // Init the DMA  to receive from usart
		USART_voidInitSend(); // Init the usart to send
		USART_voidSendChar(); // sending and waiting for it to complete
		DMA_voidInit2(); //  Init the DMA  to send to the spi
		SPI_voidMasterInit(); // config the MCU as a master
		DMA_voidEnable2(); // enable the dma to send
	}

	return 0;
}

