/*
 * SPI_private.h
 *
 *  Created on: Aug 24, 2022
 *      Author: ppppp
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


typedef struct{
	volatile u32 SPI_CR1;
	volatile u32 SPI_CR2;
	volatile u32 SPI_SR;
	volatile u32 SPI_DR;
	volatile u32 SPI_CRCPR;
	volatile u32 SPI_RXCRCR;
	volatile u32 SPI_TXCRCR;
	volatile u32 SPI_I2SCFGR;
	volatile u32 SPI_I2SPR;


}SPI_Port_t;

// PORTA base address: 0x40010800
#define REG_SPI_1				((volatile SPI_Port_t*) 0x40013000)



#endif /* SPI_PRIVATE_H_ */
