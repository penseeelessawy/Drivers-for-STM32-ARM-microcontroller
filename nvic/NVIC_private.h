/*
 * NVIC_private.h
 *
 *  Created on: Aug 8, 2022
 *      Author: Omar Gamal
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS	0xE000E100

#define NVIC_ISER0			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x000))
#define NVIC_ISER1			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x004))

#define NVIC_ICER0			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x080))
#define NVIC_ICER1			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x084))

#define NVIC_ISPR0			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x100))
#define NVIC_ISPR1			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x104))

#define NVIC_ICPR0			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x180))
#define NVIC_ICPR1			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x184))

#define NVIC_IABR0			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x200))
#define NVIC_IABR1			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x204))

#define NVIC_IPR			((volatile u8 *) (NVIC_BASE_ADDRESS+0x300))

#define NVIC_STIR			*((volatile u32 *) (NVIC_BASE_ADDRESS+0xE00))





#endif /* NVIC_PRIVATE_H_ */
