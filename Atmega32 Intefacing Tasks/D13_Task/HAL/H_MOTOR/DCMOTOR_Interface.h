/*
 * DCMOTOR_Interface.h
 *
 *  Created on: Aug 19, 2023
 *      Author: User
 */

#ifndef HAL_H_MOTOR_DCMOTOR_INTERFACE_H_
#define HAL_H_MOTOR_DCMOTOR_INTERFACE_H_


#define DC_PORT 			DIO_PORTB
#define DC_CLOCKWISE		DIO_PIN_2
#define DC_COUNTERCLOCKWISE	DIO_PIN_3

void HDC_voidDCInit();

void HDC_voidDCWrite(u8 copy_u8Direction);
void HDC_voidDCStop();


#endif /* HAL_H_MOTOR_DCMOTOR_INTERFACE_H_ */
