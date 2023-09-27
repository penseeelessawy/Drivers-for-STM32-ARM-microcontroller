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
/*
 * function to initialize the USART to SEND

 */void USART_voidInitSend(void);

/*
 * function to make  the USART to SEND charc

 */
 void USART_voidSendChar(void);
 /*
  * function to enable usart

  */
void USART_voidENABLE_USART() ;
/*
  * function to send break

  */
void USART_voidENABLE_SEND_BREAK();
/*
  * function to enable interrupt

  */
void USART_voidENABLE_INTERREUPT();
/*
  * function to send

  */
 void TRX() ;
// void strReceive(void);
#endif /* USART_INTERFACE_H_ */
