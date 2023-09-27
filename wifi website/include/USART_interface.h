/*
 * USART_interface.h
 *
 *  Created on: Aug 20, 2022
 *      Author: ppppp
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_


#define USART_NUMBER		1
//#define USART2		2
/*
 * function to enable the usart
 */
void USART_voidENABLE_USART() ;
void USART_voidENABLE_SEND_BREAK();
void USART_voidENABLE_INTERREUPT();
 void TRX(const char * str, u8 size) ;
 void strReceive(void);
#endif /* USART_INTERFACE_H_ */
