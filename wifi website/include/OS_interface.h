/*
 * OS_interface.h
 *
 *  Created on: Aug 14, 2022
 *      Author: Omar Gamal
 */

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

#define OS_TASK_DELETED			2
#define OS_TASK_READY			1
#define OS_TASK_SUSPENDED		0



/*
 * OS_voidCreateTask
 */
void OS_voidCreateTask(u8 Copy_u8ID, u8 Copy_u8Periodicity, u8 Copy_u8InitialDelay, void (*ptr)(void));

/*
 * OS_voidDeleteTask
 */
void OS_voidDeleteTask(u8 Copy_u8ID);

/*
 * OS_voidSuspendTask
 */
void OS_voidSuspendTask(u8 Copy_u8ID, u8 Copy_u8SuspendTime);

/*
 * OS_voidStartScheduler
 */
void OS_voidStartScheduler(void);

/*
 * OS_voidResumeTask
 */
void OS_voidResumeTask(u8 Copy_u8ID);

/*
 * OS_u8GetTaskState
 */
u8 OS_u8GetTaskState(u8 Copy_u8ID);



#endif /* OS_INTERFACE_H_ */
