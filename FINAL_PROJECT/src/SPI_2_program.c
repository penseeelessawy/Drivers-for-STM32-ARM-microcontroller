/*
 * SPI_2_program.c
 *
 *  Created on: Sep 3, 2022
 *      Author: ppppp
 */

/*
 * SPI_program.c
 *
 *  Created on: Aug 24, 2022
 *      Author: ppppp
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "GPIO_interface.h"

void SPI_voidMasterInit(void) {

	SET_BIT(REG_SPI_1->SPI_CR2, 1); //enbale the spi to read through DMA
	SET_BIT(REG_SPI_1->SPI_CR2, 0);
	SET_BIT(REG_SPI_1->SPI_CR1, 0); //The second clock transition is the first data capture edge
	SET_BIT(REG_SPI_1->SPI_CR1, 1); // CK to 1 when idle
	SET_BIT(REG_SPI_1->SPI_CR1, 9);// config it in software mode
	SET_BIT(REG_SPI_1->SPI_CR1, 8);
	SET_BIT(REG_SPI_1->SPI_CR1, 2); // master mode selection
	SET_BIT(REG_SPI_1->SPI_CR1, 6); // enable the spi
	SET_BIT(REG_SPI_1->SPI_CR2, 1);
	SET_BIT(REG_SPI_1->SPI_CR2, 0);
	while ((GET_BIT(REG_SPI_1->SPI_SR, 7))) ; // waiting for transmisson
}

