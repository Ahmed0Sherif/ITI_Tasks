#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include <avr/io.h>

#include "MCAL/M_DIO/MDIO_Interface.h"
#include "MCAL/M_TMR/TIME_Interface.h"
#include "MCAL/M_ADC/ADC_Interface.h"
#include "MCAL/EXT_INT/EXIT_Interface.h"

#include "HAL/H_SERVO/SERVO_Interface.h"

void writeServo();
void testADC();

s16 G_s16ADCValue;
s8 G_u8Servo;

int main (void)
{
	MDIO_voidDioSetPinDirection(DIO_PORTD, DIO_PIN_5, DIO_OUT);

	MADC_voidADCSingleInit();

	EXTI_voidGIE();

	MADC_voidADCInt();
	HSERVO_voidServoTIMER1Init();

	MADC_voidADCSetCallBack(writeServo);

	while (1)
	{
		MADC_voidADCStart();

	}
	return 0;
}


void writeServo()
{
	G_s16ADCValue = MADC_u16ADCReturnValue();
	G_u8Servo = ( 180.0 * G_s16ADCValue / 1023 );
	HSERVO_voidServoTIMER1Write(G_u8Servo);
}

void testADC()
{
	G_s16ADCValue = ADCL;
	MDIO_voidDioSetPortValue(DIO_PORTB, ADCL);
	MDIO_voidDioSetPortValue(DIO_PORTC, ADCH);

	MDIO_voidDioTogglePin(DIO_PORTA, DIO_PIN_2);
}

