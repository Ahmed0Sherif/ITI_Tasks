#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/*MACROS*/
#define LCD_DATA_PORT		DIO_PORTC
#define LCD_CONTROL_PORT	DIO_PORTD
#define RS					DIO_PIN_5
#define RW					DIO_PIN_6
#define EN					DIO_PIN_7

/*FUNCTIONS*/
void HLCD_voidLcdInit();
void HLCD_voidLcdSendCommand(u8 copy_u8Command);
void HLCD_voidLcdSendData(u8 copy_u8Data);
void HLCD_voidLcdSendString(u8 *copy_u8String);
void HLCD_voidLcdSetLocation(u8 copy_u8LineNum, u8 copy_u8CharNum);


/*MACROS FOR LCD COMMANDS*/
#define LCD_FUNC_SET	0b00111000
#define LCD_ONOFF		0b00001100
#define LCD_CLEAR		0b00000001
#define LCD_ENTRY		0b00000110


#endif
