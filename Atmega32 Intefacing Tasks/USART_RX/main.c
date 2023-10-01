/*RX*/
#include <avr/io.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/M_UART/UART_Interface.h"
#include "MCAL/M_DIO/MDIO_Interface.h"

#include "HAL/H_LCD/LCD_Interface.h"

int main (void)
{
	u8 L_u8Data;
	MDIO_voidDioSetPinDirection(DIO_PORTD, DIO_PIN_0, DIO_IN); //RX PIN
	MDIO_voidDioSetPinDirection(DIO_PORTD, DIO_PIN_1, DIO_IN); //TX PIN

	HLCD_voidLcdInit();

	UART_voidInit();
	while(1)
	{
		L_u8Data = UART_voidRecieveData();
		HLCD_voidLcdSendData(L_u8Data);
	}
	return 0;
}
