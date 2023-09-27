/*
 * DMA_program.c
 *
 *  Created on: Aug 23, 2022
 *      Author: ppppp
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_private.h"
#include "GPIO_interface.h"
#include "array_shared.h"

void DMA_voidInitUsartReceive(void) {
	REG_DMA_1->DMA_CMAR5 = (u32) Buffer_2; //the address of the memory send to it
	REG_DMA_1->DMA_CPAR5 = (u32) 0x40013804;//the address of the is the dr of the usart
	REG_DMA_1->DMA_CNDTR5 =(u32) 0x00000001; //Number of data to be transferd
	SET_BIT(REG_DMA_1->DMA_CCR5, 7);//Memory increment mode
	SET_BIT(REG_DMA_1->DMA_CCR5, 13); // set Channel priority level
	SET_BIT(REG_DMA_1->DMA_CCR5, 12);
	CLR_BIT(REG_DMA_1->DMA_CCR5, 4); // set the direction from peripheral to the memory
}
int check_1 = 0 ;
void DMA_voidEnable1(void) {
	SET_BIT(REG_DMA_1->DMA_CCR5, 0); //enable the dma to receive
	while (!GET_BIT(REG_DMA_1->DMA_ISR, 17));
	CLR_BIT(REG_DMA_1->DMA_CCR5, 0);
	if(Buffer_2[0]==' ') //transmission is complete when space is sent
       check_1=1;
	}
void  DMA_voidInit2(void)
{
	REG_DMA_1->DMA_CMAR3 = (u32) Buffer_2; // channel number 3 for spi
	REG_DMA_1->DMA_CPAR3 = (u32) 0x4001300C;
	REG_DMA_1->DMA_CNDTR3 =(u32) 0x00000001;
	SET_BIT(REG_DMA_1->DMA_CCR3, 7);
	SET_BIT(REG_DMA_1->DMA_CCR3, 13);
	SET_BIT(REG_DMA_1->DMA_CCR3, 12);
	SET_BIT(REG_DMA_1->DMA_CCR3, 4); // set the direction from memory to peripheral


}
void DMA_voidEnable2(void)
{

	SET_BIT(REG_DMA_1->DMA_CCR3, 0); //enable the dma channel of spi
	while (!GET_BIT(REG_DMA_1->DMA_ISR, 9));
	CLR_BIT(REG_DMA_1->DMA_CCR3, 0);
if(check_1 == 1) {
	GPIO_voidSetPinValue(GPIO_PORTA, 1, GPIO_HIGH);
	check_1 = 0 ;
}
else
	GPIO_voidSetPinValue(GPIO_PORTA, 1, GPIO_LOW);



}
