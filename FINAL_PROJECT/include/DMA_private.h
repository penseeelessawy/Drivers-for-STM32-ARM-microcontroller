/*
 * DMA_private.h
 *
 *  Created on: Aug 23, 2022
 *      Author: ppppp
 */

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_
#include "STD_TYPES.h"


typedef struct{
	volatile u32 DMA_ISR;
	volatile u32 DMA_IFCR;
	volatile u32 DMA_CCR1;
	volatile u32 DMA_CNDTR1;
	volatile u32 DMA_CPAR1;
	volatile u32 DMA_CMAR1;
	volatile u32 ress;

	volatile u32 DMA_CCR2;
	volatile u32 DMA_CNDTR2;
	volatile u32 DMA_CPAR2;
	volatile u32 DMA_CMAR2;
	volatile u32 ress_2;

	volatile u32 DMA_CCR3 ;
	volatile u32 DMA_CNDTR3 ;
	volatile u32 DMA_CPAR3 ;
	volatile u32 DMA_CMAR3;

	volatile u32 ress_3;

	volatile u32 DMA_CCR4 ;
	volatile u32 DMA_CNDTR4 ;
	volatile u32 DMA_CPAR4 ;
	volatile u32 DMA_CMAR4 ;
	volatile u32 ress_4;

	volatile u32 DMA_CCR5 ;
	volatile u32 DMA_CNDTR5 ;
	volatile u32 DMA_CPAR5 ;
	volatile u32 DMA_CMAR5 ;
	volatile u32 DMA_CCR6;
		volatile u32 DMA_CNDTR6 ;
		volatile u32 DMA_CPAR6 ;
		volatile u32 DMA_CMAR6 ;
		volatile u32 DMA_CCR7 ;

		volatile u32 DMA_CNDTR7 ;
				volatile u32 DMA_CPAR7 ;
				volatile u32 DMA_CMAR7 ;
}DMA_Port_t;

#define REG_DMA_2			((volatile DMA_Port_t*) 0x40020400)
#define REG_DMA_1				((volatile DMA_Port_t*) 0x40020000)





#endif /* DMA_PRIVATE_H_ */
