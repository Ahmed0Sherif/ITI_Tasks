#include <avr/io.h>
#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/M_DIO/MDIO_Interface.h"
#include "MCAL/EXT_INT/EXIT_Interface.h"
#include "HAL/H_SWITCH/SWITCH_Interface.h"

void toggleLED_0(void);

s8 type = 0;
int main (void)
{
	HSW_voidSwitchInit(DIO_PORTD, DIO_PIN_2, INTERN_PULL_UP);

	EXTI_voidGIE();

	EXTI_voidInit();

	EXTI_voidEXTISetCallBack(0, &toggleLED_0);

	MDIO_voidDioSetPortDirection(DIO_PORTA, 0xff);


	MDIO_voidDioSetPortValue(DIO_PORTA, 0xf0);

	while(1)
		{
		MDIO_voidDioTogglePort(DIO_PORTA);
		_delay_ms(200);
		}
	return 0;
}

void toggleLED_0(void)
{
	type = type ^ 1;
	if (type == 0)
	{
		MDIO_voidDioSetPortValue(DIO_PORTA, 0x00);
		MDIO_voidDioSetPortValue(DIO_PORTA, 0xf0);
	}
	else
	{
		MDIO_voidDioSetPortValue(DIO_PORTA, 0x00);
		MDIO_voidDioSetPortValue(DIO_PORTA, 0xaa);
	}
}


