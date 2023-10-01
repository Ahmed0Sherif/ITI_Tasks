#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/io.h>
#include "HSEVEN_Interface.h"
#include "../../MCAL/M_DIO/MDIO_Interface.h"

char NUM_ARR [] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

void HSEVEN_voidSevenInitDisplay (u8 copy_u8Port)
{
	MDIO_voidDioSetPortDirection(copy_u8Port,0xff);
}

void HSEVEN_voidSevenShowNum(u8 copy_u8Port, u8 number)
{
	number = number % 10;
	MDIO_voidDioSetPortValue(copy_u8Port,NUM_ARR[number]);
}
