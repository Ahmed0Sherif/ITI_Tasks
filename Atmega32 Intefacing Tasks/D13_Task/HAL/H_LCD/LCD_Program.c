#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>
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
	HLCD_voidLcdSendData(copy_u8String[L_u8Counter]);
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









