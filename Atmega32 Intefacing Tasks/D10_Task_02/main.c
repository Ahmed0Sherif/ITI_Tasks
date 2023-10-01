#include <avr/io.h>
#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/M_DIO/MDIO_Interface.h"
#include "HAL/H_SEVEN/HSEVEN_Interface.h"

#define LED_PORT 1
#define IN_PORT 0

int main (void)
{
	s8 L_s8Count;
	u8 L_u8In0 = 0, L_u8In1 = 0, L_u8In2 = 0 , L_u8Compare = 0 ;

	for (L_s8Count = 0;  L_s8Count < 3; L_s8Count++)
	{
		MDIO_voidDioSetPinDirection(IN_PORT, L_s8Count, 0);
		MDIO_voidDioSetPinValue(IN_PORT, L_s8Count, 1);
	}
	MDIO_voidDioSetPortDirection(LED_PORT, 0xff);
	while(1)
	{
		L_u8In0 = MDIO_u8DioGetPinValue(IN_PORT, 0);
		L_u8In1 = MDIO_u8DioGetPinValue(IN_PORT, 1);
		L_u8In2 = MDIO_u8DioGetPinValue(IN_PORT, 2);

		L_u8Compare = L_u8In0 + L_u8In1 * 2 + L_u8In2 * 4;

		switch(	L_u8Compare )
		{

		case 0: //Flashing every 500 ms
			MDIO_voidDioSetPortValue(LED_PORT, 0xff);
			_delay_ms(500);
			MDIO_voidDioSetPortValue(1, 0x0);
			_delay_ms(500);
			break;

		case 1://Shifting Left every 250 ms
			for (L_s8Count = 7; L_s8Count >= 0; L_s8Count --)
			{
				MDIO_voidDioSetPinValue(LED_PORT, L_s8Count, 1);
				_delay_ms(250);
				MDIO_voidDioSetPinValue(LED_PORT, L_s8Count, 0);
				_delay_ms(250);
			}
			break;


		case 2://Shifting Right every 250 ms
			for (L_s8Count = 0; L_s8Count < 8; L_s8Count ++)
			{
				MDIO_voidDioSetPinValue(LED_PORT, L_s8Count, 1);
				_delay_ms(250);
				MDIO_voidDioSetPinValue(LED_PORT, L_s8Count, 0);
				_delay_ms(250);
			}
			break;


		case 3://2-LEDs Converging every 300 ms
			for (L_s8Count = 0; L_s8Count < 4; L_s8Count ++)
			{
				MDIO_voidDioSetPinValue(LED_PORT, L_s8Count, 1);
				MDIO_voidDioSetPinValue(LED_PORT, 7 - L_s8Count, 1);
				_delay_ms(300);
				MDIO_voidDioSetPortValue(LED_PORT, 0x00);
			}
			break;


		case 4://2-LEDs Diverging every 300 ms
			for (L_s8Count = 3; L_s8Count >= 0; L_s8Count --)
			{
				MDIO_voidDioSetPinValue(LED_PORT, L_s8Count, 1);
				MDIO_voidDioSetPinValue(LED_PORT, 7 - L_s8Count, 1);
				_delay_ms(300);
				MDIO_voidDioSetPortValue(LED_PORT, 0x00);
			}
			break;


		case 5://Ping Pong effect every 250 ms
			for (L_s8Count = 7; L_s8Count >= 0; L_s8Count --)
			{
				MDIO_voidDioSetPinValue(LED_PORT, L_s8Count, 1);
				_delay_ms(250);
				MDIO_voidDioSetPinValue(LED_PORT, L_s8Count, 0);
				_delay_ms(250);
			}
			for (L_s8Count = 1; L_s8Count < 7; L_s8Count ++)
			{
				MDIO_voidDioSetPinValue(LED_PORT, L_s8Count, 1);
				_delay_ms(250);
				MDIO_voidDioSetPinValue(LED_PORT, L_s8Count, 0);
				_delay_ms(250);
			}
			break;


		case 6: //Incrementing (Snake effect) every 300 ms
			for (L_s8Count = 0; L_s8Count < 8; L_s8Count ++)
			{
				MDIO_voidDioSetPinValue(LED_PORT, L_s8Count, 1);
				_delay_ms(300);
			}
			MDIO_voidDioSetPortValue(LED_PORT, 0x0);
			break;

		case 7:
			for (L_s8Count = 0; L_s8Count < 4; L_s8Count ++)
			{
				MDIO_voidDioSetPinValue(LED_PORT, L_s8Count, 1);
				MDIO_voidDioSetPinValue(LED_PORT, 7 - L_s8Count, 1);
				_delay_ms(300);
				MDIO_voidDioSetPortValue(LED_PORT, 0x00);
			}

			for (L_s8Count = 2; L_s8Count >= 0; L_s8Count --)
			{
				MDIO_voidDioSetPinValue(LED_PORT, L_s8Count, 1);
				MDIO_voidDioSetPinValue(LED_PORT, 7 - L_s8Count, 1);
				_delay_ms(300);
				MDIO_voidDioSetPortValue(LED_PORT, 0x00);
			}
			break;
		}
	}
	return 0;
}
