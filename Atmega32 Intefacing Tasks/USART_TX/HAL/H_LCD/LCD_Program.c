#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>
#include <stdlib.h>
#include "../../MCAL/M_DIO/MDIO_Interface.h"
#include "LCD_Interface.h"


void HLCD_voidLcdInit()
{
	/*SET DATA_PORT AS OUT*/
	MDIO_voidDioSetPortDirection(LCD_DATA_PORT, 0xff);
	MDIO_voidDioSetPinDirection(LCD_CONTROL_PORT, RS, 1);
	MDIO_voidDioSetPinDirection(LCD_CONTROL_PORT, RW, 1);
	MDIO_voidDioSetPinDirection(LCD_CONTROL_PORT, EN, 1);
	
	/*delay for 30 ms*/
	_delay_ms(30);
	HLCD_voidLcdSendCommand(LCD_FUNC_SET);
	_delay_ms(1);
	/*DISPLAY ON/OFF CTRL*/
	HLCD_voidLcdSendCommand(LCD_ONOFF);
	_delay_ms(1);
	HLCD_voidLcdSendCommand(LCD_CLEAR);
	_delay_ms(2);
	HLCD_voidLcdSendCommand(LCD_ENTRY);
}

void HLCD_voidLcdSendCommand(u8 copy_u8Command)
{
	/*RS = 0*/
	MDIO_voidDioSetPinValue(LCD_CONTROL_PORT, RS, 0);
	/*RW = 0*/
	MDIO_voidDioSetPinValue(LCD_CONTROL_PORT, RW, 0);
	/*PUTTING COMMAND ON DATA PORT*/
	MDIO_voidDioSetPortValue(LCD_DATA_PORT,copy_u8Command);
	/*ENABLE PULSE*/
	MDIO_voidDioSetPinValue(LCD_CONTROL_PORT, EN, 1);
	_delay_ms(2);
	MDIO_voidDioSetPinValue(LCD_CONTROL_PORT, EN, 0);
}

void HLCD_voidLcdSendData(u8 copy_u8Data)
{
	/*RS = 1*/
	MDIO_voidDioSetPinValue(LCD_CONTROL_PORT, RS, 1);
	/*RW = 0*/
	MDIO_voidDioSetPinValue(LCD_CONTROL_PORT, RW, 0);
	/*PUTTING COMMAND ON DATA PORT*/
	MDIO_voidDioSetPortValue(LCD_DATA_PORT,copy_u8Data);
	/*ENABLE PULSE*/
	MDIO_voidDioSetPinValue(LCD_CONTROL_PORT, EN, 1);
	_delay_ms(2);
	MDIO_voidDioSetPinValue(LCD_CONTROL_PORT, EN, 0);
}

void HLCD_voidLcdSendString(u8 *copy_u8String)
{
	u8 L_u8Counter;
	for (L_u8Counter = 0; copy_u8String[L_u8Counter] != '\0'; L_u8Counter++ )
	{
	HLCD_voidLcdSendData((u8*)copy_u8String[L_u8Counter]);
	}
}


void HLCD_voidLcdSetLocation(u8 copy_u8LineNum, u8 copy_u8CharNum)
{
	switch(copy_u8LineNum)
	{
	case 0: HLCD_voidLcdSendCommand(0x80 + copy_u8CharNum); break;
	case 1: HLCD_voidLcdSendCommand(0xc0 + copy_u8CharNum); break;
	}

}

void HLCD_voidLcdSendIntValue(u32 copy_u32Data)
{
	u32 L_u8Carrier;
	u32 L_u32Divider;
	if (copy_u32Data >= 0 && copy_u32Data < 10 ) //For single digit number
	{
		HLCD_voidLcdSendData(48 + copy_u32Data);
	}
	else
	{
		L_u32Divider = 1;
		if(copy_u32Data < 0)
		{
			HLCD_voidLcdSendData('-');
			copy_u32Data = copy_u32Data * -1;
		}
		while (1)
		{
			if(copy_u32Data > L_u32Divider)
			{
				L_u32Divider = L_u32Divider * 10;
				if(copy_u32Data < L_u32Divider * 10)
					break;
			}
		}
		//Printing Sequence
		while(1)
		{
			if (copy_u32Data < 10 && (copy_u32Data >= L_u32Divider || copy_u32Data == 0 ))
			{
				HLCD_voidLcdSendData(48 + copy_u32Data);
				break;
			}

			else
			{
				L_u8Carrier = copy_u32Data / L_u32Divider;
				HLCD_voidLcdSendData(48 + L_u8Carrier);
				L_u8Carrier = copy_u32Data % L_u32Divider;
				if(L_u8Carrier < L_u32Divider && L_u8Carrier >= L_u32Divider / 10 )
				{
					copy_u32Data = L_u8Carrier;
					L_u32Divider = L_u32Divider / 10;
				}
				else
				{
					if (L_u32Divider > 10)
					{
						HLCD_voidLcdSendData(48);
						copy_u32Data = L_u8Carrier;
						L_u32Divider = L_u32Divider / 100;
						if (copy_u32Data < L_u32Divider)
						{
							HLCD_voidLcdSendData(48);
							L_u32Divider = L_u32Divider / 10;
						}
					}
					else
					{
						HLCD_voidLcdSendData(48);
						break;
					}
				}

			}
		}
	}

//	}
//	do
//	{
//
//	}
//	while(copy_u32Data != 0);
}

void HLCD_voidLcdSendInteger(u32 copy_u32Data)
{
	s8 L_Au8NumberCarrier [16] ;
	itoa(copy_u32Data, (s8*)L_Au8NumberCarrier, 10);
	HLCD_voidLcdSendString((s8*)L_Au8NumberCarrier);
}







