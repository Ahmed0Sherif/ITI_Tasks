/*Task 01: Traffic Lights*/
#include <avr/io.h>
#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/M_DIO/MDIO_Interface.h"
#include "HAL/H_SEVEN/HSEVEN_Interface.h"

static s8 G_s8Counter = 0;

void displayTwoSegments(u8 L_delay);

int main (void)
{

	HSEVEN_voidSevenInitDisplay(0); //Displaying Units
	HSEVEN_voidSevenInitDisplay(1); //Displaying Tens

	for (G_s8Counter = 0; G_s8Counter < 3; G_s8Counter++)
	{
		MDIO_voidDioSetPinDirection(2,G_s8Counter,1);
	}

	while (1)
	{
		MDIO_voidDioSetPinValue (2, 0, 1);
		displayTwoSegments(10);
		MDIO_voidDioSetPinValue (2, 0, 0);

		MDIO_voidDioSetPinValue (2, 1, 1);
		displayTwoSegments(3);
		MDIO_voidDioSetPinValue (2, 1, 0);

		MDIO_voidDioSetPinValue (2, 2, 1);
		displayTwoSegments(10);
		MDIO_voidDioSetPinValue (2, 2, 0);
	}
	return 0;
}

void displayTwoSegments(u8 L_delay)
{
	for (G_s8Counter = L_delay; G_s8Counter >= 1 ; G_s8Counter --)
			{
				HSEVEN_voidSevenShowNum(0, G_s8Counter % 10);
				HSEVEN_voidSevenShowNum(1, G_s8Counter / 10);
				_delay_ms(1000);
			}
}
