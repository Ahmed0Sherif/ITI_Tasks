#include <avr/io.h>
#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/M_DIO/MDIO_Interface.h"
#include "HAL/H_LCD/LCD_Interface.h"
#include "HAL/H_SWITCH/SWITCH_Interface.h"
#include "HAL/H_MOTOR/DCMOTOR_Interface.h"


int main (void)
{
	u8 L_u8MotorCtrl_0, L_u8MotorCtrl_1;

	HLCD_voidLcdInit();

	HSW_voidSwitchInit(DIO_PORTA, DIO_PIN_0, INTERN_PULL_UP);
	HSW_voidSwitchInit(DIO_PORTA, DIO_PIN_1, INTERN_PULL_UP);

	HDC_voidDCInit();
	
	HLCD_voidLcdSetLocation(0,1);
	HLCD_voidLcdSendString("DC Motor Dir:");
	while(1)
	{
		L_u8MotorCtrl_0 =  HSW_u8SwitchGetValue(DIO_PORTA, DIO_PIN_0);
		L_u8MotorCtrl_1 =  HSW_u8SwitchGetValue(DIO_PORTA, DIO_PIN_1);
		_delay_ms(10);

		if ( L_u8MotorCtrl_0 ^ L_u8MotorCtrl_1 ) //Checks if both inputs are the same or not)
		{
			if (L_u8MotorCtrl_0)
			{
			HDC_voidDCWrite(DC_CLOCKWISE);
			HLCD_voidLcdSetLocation(1,0);
			HLCD_voidLcdSendString("CountClockwise");
			}
			else if(L_u8MotorCtrl_1)
			{
			HDC_voidDCWrite(DC_COUNTERCLOCKWISE);
			HLCD_voidLcdSetLocation(1,0);
			HLCD_voidLcdSendString("Clockwise     ");

			}
		}
		else
		{
			HDC_voidDCStop();
			HLCD_voidLcdSetLocation(1,0);
			HLCD_voidLcdSendString("Stop          ");
		}
	}
}
