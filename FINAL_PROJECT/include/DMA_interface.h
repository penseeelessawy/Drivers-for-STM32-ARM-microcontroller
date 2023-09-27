/*
 * DMA_interface.h
 *
 *  Created on: Aug 23, 2022
 *      Author: ppppp
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_


/*
 * function to initialize the DMA to receive from usart

 */
void DMA_voidInitUsartReceive(void);

 /*
  * function to enable the DMA to receive from usart

  */

 void DMA_voidEnable1(void) ;
 /*
   * function to initalize the DMA to send to  spi

   */

 void  DMA_voidInit2(void);

 /*
    * function to initalize the DMA to send to  spi

    */

  void DMA_voidEnable2(void);
#endif /* DMA_INTERFACE_H_ */
