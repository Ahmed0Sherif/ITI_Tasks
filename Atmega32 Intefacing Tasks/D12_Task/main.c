/*Using a 3x3 Keypad to display numbers form 1 to 9 on seven segment display*/
#include <avr/io.h>
#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/M_DIO/MDIO_Interface.h"
#include "HAL/H_SEVEN/HSEVEN_Interface.h"
#include "HAL/H_KEYPAD/KEYPAD_Interface.h"

#define OFFSET 0x30

int main (void)
{
	u8 L_u8Return = KPD_u8_KEY_NOT_PRESSED;

	HSEVEN_voidSevenInitDisplay(DIO_PORTA);
	HKPD_voidKPDInt();
	while(1)
	{
		L_u8Return = HKPD_u8KPDGetKeyValue();
		if (L_u8Return != KPD_u8_KEY_NOT_PRESSED)
		{
			HSEVEN_voidSevenShowNum(0, L_u8Return - OFFSET); /*	After receiving a character
			 	 	 	 	 	 	 	 	 	 	 	 	 	from the keypad, the offset is
			 	 	 	 	 	 	 	 	 	 	 	 	 	subtracted from it, returning the
			 	 	 	 	 	 	 	 	 	 	 	 	 	number. */
		}

	}
	return 0;
}
