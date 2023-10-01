/*
 * SERVOMOTOR_Program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Ahmed
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SERVOMOTOR_Interface.h"

void TIMER1_voidFPWM(void)
{
	/* SELECT FAST PWM */
	CLR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);

	/* CLEAR OC1A */
	CLR_BIT(TCCR1A, COM1A0);
	SET_BIT(TCCR1A, COM1A1);

	/* ICR1 */
	ICR1 = 19999;

	/* CLK/8 */
	CLR_BIT(TCCR1B, CS10);
	SET_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS12);
	DIO_voidSetPinDirection(3,5,1);

}

void SERVO_voidSetAngle(u8 copy_u8Angle)
{
	OCR1A = ((50* copy_u8Angle)+8991)/9;
}

