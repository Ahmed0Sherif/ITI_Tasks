/*TX*/
#include <avr/io.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/M_UART/UART_Interface.h"
#include "MCAL/M_DIO/MDIO_Interface.h"

#include "HAL/H_KEYPAD/KEYPAD_Interface.h"

int main (void)
{
	u8  L_u8KPDPress = KPD_u8_KEY_NOT_PRESSED;

	MDIO_voidDioSetPinDirection(DIO_PORTD, DIO_PIN_0, DIO_IN); //RX PIN
	MDIO_voidDioSetPinDirection(DIO_PORTD, DIO_PIN_1, DIO_IN); //TX PIN

	HKPD_voidKPDInt();
	UART_voidInit();

	while(1)
	{
		L_u8KPDPress = HKPD_u8KPDGetKeyValue();
		if (L_u8KPDPress != KPD_u8_KEY_NOT_PRESSED)
		{
			UART_voidSendData(L_u8KPDPress);
		}
	}
	return 0;
}
