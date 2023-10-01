#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/io.h>
#include "MDIO_Interface.h"

/*
PORTS A, B, C, D ->>>>>>>>>>>>>> 0, 1, 2, 3
*/




void MDIO_voidDioSetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction)
{
	if (copy_u8Direction == DIO_OUT)
	{
		switch (copy_u8Port)
		{
			case DIO_PORTA:SET_BIT(DDRA, copy_u8Pin); break;
			case DIO_PORTB:SET_BIT(DDRB, copy_u8Pin); break;
			case DIO_PORTC:SET_BIT(DDRC, copy_u8Pin); break;
			case DIO_PORTD:SET_BIT(DDRD, copy_u8Pin); break;
		}
	}
	else if(copy_u8Direction == DIO_IN)
	{
		switch (copy_u8Port)
		{
			case DIO_PORTA:CLR_BIT(DDRA, copy_u8Pin); break;
			case DIO_PORTB:CLR_BIT(DDRB, copy_u8Pin); break;
			case DIO_PORTC:CLR_BIT(DDRC, copy_u8Pin); break;
			case DIO_PORTD:CLR_BIT(DDRD, copy_u8Pin); break;
		}
	}
}

void MDIO_voidDioSetPinValue (u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value)
{
	if (copy_u8Value == HIGH)
	{
		switch(copy_u8Port)
		{
			case DIO_PORTA: SET_BIT(PORTA, copy_u8Pin); break;
			case DIO_PORTB: SET_BIT(PORTB, copy_u8Pin); break;
			case DIO_PORTC: SET_BIT(PORTC, copy_u8Pin); break;
			case DIO_PORTD: SET_BIT(PORTD, copy_u8Pin); break;
		}
	}
	else if (copy_u8Value == LOW)
	{
		switch(copy_u8Port)
		{
			case DIO_PORTA: CLR_BIT(PORTA, copy_u8Pin); break;
			case DIO_PORTB: CLR_BIT(PORTB, copy_u8Pin); break;
			case DIO_PORTC: CLR_BIT(PORTC, copy_u8Pin); break;
			case DIO_PORTD: CLR_BIT(PORTD, copy_u8Pin); break;
		}
	}
}

u8 MDIO_u8DioGetPinValue (u8 copy_u8Port, u8 copy_u8Pin)
{
	u8 L_u8Value;
	switch(copy_u8Port)
		{
			case DIO_PORTA: L_u8Value = GET_BIT(PINA, copy_u8Pin); break;
			case DIO_PORTB: L_u8Value = GET_BIT(PINB, copy_u8Pin); break;
			case DIO_PORTC: L_u8Value = GET_BIT(PINC, copy_u8Pin); break;
			case DIO_PORTD: L_u8Value = GET_BIT(PIND, copy_u8Pin); break;
		}
	return L_u8Value;
}

void MDIO_voidDioTogglePin (u8 copy_u8Port, u8 copy_u8Pin)
{
	switch(copy_u8Port)
		{
			case DIO_PORTA: TOG_BIT(PORTA, copy_u8Pin); break;
			case DIO_PORTB: TOG_BIT(PORTB, copy_u8Pin); break;
			case DIO_PORTC: TOG_BIT(PORTC, copy_u8Pin); break;
			case DIO_PORTD: TOG_BIT(PORTD, copy_u8Pin); break;
		}
}

void MDIO_voidDioSetPortDirection (u8 copy_u8Port, u8 copy_u8Direction)
{
	switch(copy_u8Port)
		{
			case DIO_PORTA: DDRA = copy_u8Direction; break;
			case DIO_PORTB: DDRB = copy_u8Direction; break;
			case DIO_PORTC: DDRC = copy_u8Direction; break;
			case DIO_PORTD: DDRD = copy_u8Direction; break;
		}
}

void MDIO_voidDioSetPortValue (u8 copy_u8Port, u8 copy_u8Value)
{
	switch(copy_u8Port)
		{
			case DIO_PORTA: PORTA = copy_u8Value;  break;
			case DIO_PORTB: PORTB = copy_u8Value;  break;
			case DIO_PORTC: PORTC = copy_u8Value;  break;
			case DIO_PORTD: PORTD = copy_u8Value;  break;
		}
}
