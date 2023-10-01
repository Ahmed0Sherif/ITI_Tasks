#include <avr/io.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/M_DIO/MDIO_Interface.h"
#include "MCAL/EXT_INT/EXIT_Interface.h"
#include "MCAL/M_TMR/TIME_Interface.h"

void toggleLED(void);

int main (void)
{
	MDIO_voidDioSetPinDirection(DIO_PORTA, DIO_PIN_0, DIO_OUT);

	EXTI_voidGIE();

	MTIMER_voidTimer2OVFSetCallBack(toggleLED);
	while (1)
	{
		MTIMER_voidTimer2OVFDelay(1000);
	}
	return 0;
}

void toggleLED(void)
{
	MDIO_voidDioTogglePin(DIO_PORTA, DIO_PIN_0);

}
