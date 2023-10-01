#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/io.h>
#include "../../MCAL/M_DIO/MDIO_Interface.h"
#include "SWITCH_Interface.h"

void HSW_voidSwitchInit(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8PullUp)
{
	MDIO_voidDioSetPinDirection(copy_u8Port, copy_u8Pin, DIO_IN);
	MDIO_voidDioSetPinValue(copy_u8Port, copy_u8Pin, copy_u8PullUp);
}

u8 HSW_u8SwitchGetValue (u8 copy_u8Port, u8 copy_u8Pin)
{
	return MDIO_u8DioGetPinValue (copy_u8Port, copy_u8Pin);
}
