#include <avr/io.h>
#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/M_DIO/MDIO_Interface.h"
#include "MCAL/EXT_INT/EXIT_Interface.h"
#include "HAL/H_SWITCH/SWITCH_Interface.h"

void toggleLED_0(void);
void toggleLED_1(void);


int main (void)
{
	HSW_voidSwitchInit(DIO_PORTD, DIO_PIN_2, INTERN_PULL_UP);
	HSW_voidSwitchInit(DIO_PORTD, DIO_PIN_3, INTERN_PULL_UP);

	MDIO_voidDioSetPinDirection(DIO_PORTA, DIO_PIN_0, DIO_OUT);
	MDIO_voidDioSetPinDirection(DIO_PORTA, DIO_PIN_1, DIO_OUT);

	EXTI_voidGIE();

	EXTI_voidInit();

	EXTI_voidEXTISetCallBack(0, &toggleLED_0);
	EXTI_voidEXTISetCallBack(1, &toggleLED_1);

	while(1)
		{

		}
	return 0;
}

void toggleLED_0(void)
{
	MDIO_voidDioTogglePin(DIO_PORTA, DIO_PIN_0);
}
void toggleLED_1(void)
{
	MDIO_voidDioTogglePin(DIO_PORTA, DIO_PIN_1);
}
