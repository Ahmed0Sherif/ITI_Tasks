#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/io.h>
#include "MDIO_Interface.h"

/*
PORTS A, B, C, D ->>>>>>>>>>>>>> 0, 1, 2, 3
*/


void MDIO_voidDioSetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction)
{
	if (copy_u8Direction == 1)
	{
		switch (copy_u8Port)
		{
			case 0:SET_BIT(DDRA, copy_u8Pin); break;
			case 1:SET_BIT(DDRB, copy_u8Pin); break;
			case 2:SET_BIT(DDRC, copy_u8Pin); break;
			case 3:SET_BIT(DDRD, copy_u8Pin); break;
		}
	}
	else if(copy_u8Direction == 0)
	{
		switch (copy_u8Port)
		{
			case 0:CLR_BIT(DDRA, copy_u8Pin); break;
			case 1:CLR_BIT(DDRB, copy_u8Pin); break;
			case 2:CLR_BIT(DDRC, copy_u8Pin); break;
			case 3:CLR_BIT(DDRD, copy_u8Pin); break;
		}
	}
}

void MDIO_voidDioSetPinValue (u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value)
{
	if (copy_u8Value == 1)
	{
		switch(copy_u8Port)
		{
			case 0: SET_BIT(PORTA, copy_u8Pin); break;
			case 1: SET_BIT(PORTB, copy_u8Pin); break;
			case 2: SET_BIT(PORTC, copy_u8Pin); break;
			case 3: SET_BIT(PORTD, copy_u8Pin); break;
		}
	}
	else if (copy_u8Value == 0)
	{
		switch(copy_u8Port)
		{
			case 0: CLR_BIT(PORTA, copy_u8Pin); break;
			case 1: CLR_BIT(PORTB, copy_u8Pin); break;
			case 2: CLR_BIT(PORTC, copy_u8Pin); break;
			case 3: CLR_BIT(PORTD, copy_u8Pin); break;
		}
	}
}

u8 MDIO_u8DioGetPinValue (u8 copy_u8Port, u8 copy_u8Pin)
{
	u8 L_u8Value;
	switch(copy_u8Port)
		{
			case 0: L_u8Value = GET_BIT(PINA, copy_u8Pin); break;
			case 1: L_u8Value = GET_BIT(PINB, copy_u8Pin); break;
			case 2: L_u8Value = GET_BIT(PINC, copy_u8Pin); break;
			case 3: L_u8Value = GET_BIT(PIND, copy_u8Pin); break;
		}
	return L_u8Value;
}

void MDIO_voidDioTogglePin (u8 copy_u8Port, u8 copy_u8Pin)
{
	switch(copy_u8Port)
		{
			case 0: TOG_BIT(PORTA, copy_u8Pin); break;
			case 1: TOG_BIT(PORTB, copy_u8Pin); break;
			case 2: TOG_BIT(PORTC, copy_u8Pin); break;
			case 3: TOG_BIT(PORTD, copy_u8Pin); break;
		}
}

void MDIO_voidDioSetPortDirection (u8 copy_u8Port, u8 copy_u8Direction)
{
	switch(copy_u8Port)
		{
			case 0: DDRA = copy_u8Direction; break;
			case 1: DDRB = copy_u8Direction; break;
			case 2: DDRC = copy_u8Direction; break;
			case 3: DDRD = copy_u8Direction; break;
		}
}

void MDIO_voidDioSetPortValue (u8 copy_u8Port, u8 copy_u8Value)
{
	switch(copy_u8Port)
		{
			case 0: PORTA = copy_u8Value;  break;
			case 1: PORTB = copy_u8Value;  break;
			case 2: PORTC = copy_u8Value;  break;
			case 3: PORTD = copy_u8Value;  break;
		}
}
