#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include <avr/io.h>
#include <math.h>
#include <stdlib.h>

#include "MCAL/M_DIO/MDIO_Interface.h"
#include "MCAL/M_TMR/TIME_Interface.h"

#include "HAL/H_KEYPAD/KEYPAD_Interface.h"
#include "HAL/H_LCD/LCD_Interface.h"
#include "HAL/H_SERVO/SERVO_Interface.h"

#define DIGITS 3
u8 G_u8Position ;
u8 G_u8Return;
u32 G_u32Val;
u8 * G_Pu8NumberArr;

s32 getFinalValue(void);
void printValue(void);

int main(void)
{
	/*Initializing Some Globals*/
	u8 L_Au8NumberArr[4] = {'0','0','0', '\0' };
	G_Pu8NumberArr = L_Au8NumberArr;
	u8 	L_u8StartFlag = 0;
	G_u32Val = 0 ;
	G_u8Return = KPD_u8_KEY_NOT_PRESSED;

	/*Servo Control Pin*/
	MDIO_voidDioSetPinDirection(DIO_PORTD, DIO_PIN_5, DIO_OUT);
	HSERVO_voidServoTIMER1Init();

	/*Initializing Keypad and LCD*/
	HLCD_voidLcdInit();

	HKPD_voidKPDInt();
	 while(1)
	 {
		G_u8Return = HKPD_u8KPDGetKeyValue(); /*Receives Button Press*/

		if (G_u8Return != KPD_u8_KEY_NOT_PRESSED)
		{
			if (G_u8Return == '/') //Start
			{
				if (L_u8StartFlag == 0)	//Starts only when program is closed
				{
					HLCD_voidLcdSendString("Enter angle:");
					HLCD_voidLcdSetLocation(1,0);
					L_u8StartFlag = 1;
				}
			}
			else if (G_u8Return == 'C')	//Close
			{
				if (L_u8StartFlag == 1) //Closes when program is running
				{
					HLCD_voidLcdSendCommand(LCD_CLEAR);
					G_u32Val = 0;
					HSERVO_voidServoTIMER1Write((u8)G_u32Val);
					G_u8Position = 0;
					HLCD_voidLcdSetLocation(0,0);
					L_u8StartFlag = 0;
				}
			}
			else if ( (G_u8Return >= '0') &&  (G_u8Return <= '9')) //Printing Numbers
			{
				if (L_u8StartFlag == 1)
				{
					if (G_u8Position < DIGITS)
					{
						HLCD_voidLcdSendData(G_u8Return);
						//L_u32Stored = getValue();
						G_Pu8NumberArr[G_u8Position] = G_u8Return;
						G_u8Position ++;
					}
				}
			}

			else if ( G_u8Return == '+') //Increment Position
			{
				if (L_u8StartFlag == 1)
				{
					if (G_u8Position < DIGITS)
					{
						HLCD_voidLcdSetLocation(1,++G_u8Position);
					}
				}
			}
			else if ( G_u8Return == '-') //Decrement Position
			{
				if (L_u8StartFlag == 1)
				{
					if (G_u8Position >= 0)
					{
						HLCD_voidLcdSetLocation(1,--G_u8Position);
					}
				}
			}
			else if ( G_u8Return == '=')
				if (L_u8StartFlag == 1)
				{
					HLCD_voidLcdSetLocation(1,7);
					HLCD_voidLcdSendData(' ');
					HLCD_voidLcdSendData(' ');
					HLCD_voidLcdSetLocation(1,6);
					if (getFinalValue() == -1)
					{
						HLCD_voidLcdSendString("ERR");
					}
					else
					{
					HLCD_voidLcdSendInteger(getFinalValue());
					HSERVO_voidServoTIMER1Write((u8)G_u32Val);
					}

					HLCD_voidLcdSetLocation(1,G_u8Position);
				}
		}
	 }
	 return 0;
}


s32 getFinalValue(void)
{
	G_u32Val = 0;
	HLCD_voidLcdSendCommand(LCD_ONOFF_NCUR); /*Just To avoid flickering */
	u8 L_u8copyPos = 0;
	for (L_u8copyPos = 0; L_u8copyPos < DIGITS; L_u8copyPos++)
	{
		/*The value entered by user is calculated by subtracting '0' from each entered character, then multiplying by a power of 10*/
		G_u32Val = G_u32Val + (G_Pu8NumberArr[L_u8copyPos] - 48) * ( (L_u8copyPos >= 1) ? (L_u8copyPos ==2 ? 1 : 10 ): 100 );
		/*Tried using the pow(,) of math.h, but a lot errors occured*/
	}

	HLCD_voidLcdSendCommand(LCD_ONOFF);
	if (G_u32Val > 180)
	{
		return -1; //Error Check
	}
	else
	{
		return G_u32Val; //Valid Value.
	}
}

void printValue(void)
{
	u8 L_u8Pointer;
	for (L_u8Pointer = 0; L_u8Pointer< DIGITS; L_u8Pointer ++)
	{
		HLCD_voidLcdSendData(G_Pu8NumberArr[L_u8Pointer]);
	}
}
