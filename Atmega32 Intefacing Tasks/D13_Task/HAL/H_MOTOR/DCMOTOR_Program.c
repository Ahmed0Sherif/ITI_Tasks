/*
 * DCMOTOR_Program.c
 *
 *  Created on: Aug 19, 2023
 *      Author: User
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/io.h>
#include "../../MCAL/M_DIO/MDIO_Interface.h"
#include "DCMOTOR_Interface.h"

void HDC_voidDCInit()
{
	MDIO_voidDioSetPinDirection(DC_PORT, DC_CLOCKWISE, DIO_OUT);
	MDIO_voidDioSetPinDirection(DC_PORT, DC_COUNTERCLOCKWISE, DIO_OUT);
}

void HDC_voidDCWrite(u8 copy_u8Direction)
{
	switch(copy_u8Direction)
	{
	case (DC_CLOCKWISE):
			MDIO_voidDioSetPinValue(DC_PORT, DC_COUNTERCLOCKWISE, LOW);
			MDIO_voidDioSetPinValue(DC_PORT, DC_CLOCKWISE, HIGH);
			break;

	case (DC_COUNTERCLOCKWISE):
			MDIO_voidDioSetPinValue(DC_PORT, DC_CLOCKWISE, LOW);
			MDIO_voidDioSetPinValue(DC_PORT, DC_COUNTERCLOCKWISE, HIGH);
			break;
	}
}

void HDC_voidDCStop()
{
	MDIO_voidDioSetPinValue(DC_PORT, DC_CLOCKWISE, LOW);
	MDIO_voidDioSetPinValue(DC_PORT, DC_COUNTERCLOCKWISE, LOW);
}
