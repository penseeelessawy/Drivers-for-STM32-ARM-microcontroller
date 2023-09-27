/*
 * USART_private.h
 *
 *  Created on: Aug 20, 2022
 *      Author: ppppp
 */




#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_



typedef struct{
	volatile u32 USART_SR;
	volatile u32 USART_DR;
	volatile u32 USART_BRR ;
	volatile u32 USART_CR1 ;
	volatile u32 USART_CR2;
	volatile u32 USART_CR3;
	volatile u32 USART_GTPR;
}USART_Port_t;

#define reg_USART1				((volatile USART_Port_t*)0x40013800)
#define reg_USART2				((volatile USART_Port_t*) 0x40010C00)
#define USART3				((volatile USART_Port_t*) 0x40011000)




#endif /* USART_PRIVATE_H_ */
