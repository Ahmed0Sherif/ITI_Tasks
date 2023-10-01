#include <avr/io.h>
#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/M_DIO/MDIO_Interface.h"
#include "HAL/H_LCD/LCD_Interface.h"

static s8 i = 0;
int main(void)
{
	HLCD_voidLcdInit();
	while(1)
	{
		for(i = 0; i <16; i ++)
		{
			HLCD_voidLcdSetLocation(i % 2, i);
			HLCD_voidLcdSendString("Ahmed");
			_delay_ms(100);
			HLCD_voidLcdSendCommand(LCD_CLEAR);
		}
		_delay_ms(200);
		for(i = 15; i >= 0; i --)
		{
			HLCD_voidLcdSetLocation(i % 2, i);
			HLCD_voidLcdSendString("Sherif");
			_delay_ms(100);
			HLCD_voidLcdSendCommand(LCD_CLEAR);
		}
	}
	return 0;
}



