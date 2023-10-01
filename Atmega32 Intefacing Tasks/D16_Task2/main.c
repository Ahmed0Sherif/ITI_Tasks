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

	MTIMER_voidTimer2COMPSetCallBack(toggleLED);
	while (1)
	{
		MTIMER_voidTimer2COMPDelay(18, 122);
		/*Regarding the change of implementing the delay:
		 * I tried to do the same calculations done in the overflow
		 * but basically, didn't work and completely wasted some time
		 * so I gave up..
		 * The numbers here are calculated using the same rules in lectures
		 * # of overflows = delay time (us) / Overflow time (8192 us in this case)
		 * Then the fraction part is multiplied by 256 to calculate the value put in OCR2
		 * I am sorry...
		 *   */
	}
	return 0;
}

void toggleLED(void)
{
	MDIO_voidDioTogglePin(DIO_PORTA, DIO_PIN_0);

}
