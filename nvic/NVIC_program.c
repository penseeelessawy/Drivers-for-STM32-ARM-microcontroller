/*
 * NVIC_program.c
 *
 *  Created on: Aug 8, 2022
 *      Author: Pensee Elessawy
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


/*
 * NVIC_voidEnableInterrupt
 * parameters:
 * description: Sets the NVIC enable pin for a specific interrupt
 */
void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptPotiotion){

	if(Copy_u8InterruptPotiotion < 32){
		NVIC_ISER0 = 1 << Copy_u8InterruptPotiotion;
	}else if(Copy_u8InterruptPotiotion < 60){
		NVIC_ISER1 = 1 << (Copy_u8InterruptPotiotion - 32);
	}
}


/*
 * NVIC_voidDisableInterrupt
 * parameters:
 * description: Sets the NVIC disable pin for a specific interrupt
 */
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptPotiotion){


}

/*
 * NVIC_voidSetPendingFlag
 * parameters:
 * description: Sets the NVIC enable pin for a specific interrupt
 */
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptPotiotion){


}


/*
 * NVIC_voidClearPendingFlag
 * parameters:
 * description: Sets the NVIC disable pin for a specific interrupt
 */
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptPotiotion){


}

/*
 * NVIC_u8GetActiveFlag
 * parameters:
 * return value:
 * description: Sets the NVIC disable pin for a specific interrupt
 */
u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptPotiotion){


	return 0;
}
