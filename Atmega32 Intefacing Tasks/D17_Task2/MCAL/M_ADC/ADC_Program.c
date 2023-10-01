#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include "../M_DIO/MDIO_Interface.h"
#include "ADC_Interface.h"

static void (*ADC_CONV_END)(void);

static u8 G_u8Check;
void MADC_voidADCSingleInit()
{
#if ADC_SINGLE ==ADC_0
	SINGLE_CHANNEL(0);
#elif ADC_SINGLE ==ADC_1
	SINGLE_CHANNEL(1);
#elif ADC_SINGLE ==ADC_2
	SINGLE_CHANNEL(2);
#elif ADC_SINGLE ==ADC_3
	SINGLE_CHANNEL(3);
#elif ADC_SINGLE ==ADC_4
	SINGLE_CHANNEL(4);
#elif ADC_SINGLE ==ADC_5
	SINGLE_CHANNEL(5);
#elif ADC_SINGLE ==ADC_6
	SINGLE_CHANNEL(6);
#elif ADC_SINGLE ==ADC_7
	SINGLE_CHANNEL(7);
#endif


#if 	SOURCE == AREF
	 CLR_BIT(ADMUX, REFS0);
	 CLR_BIT(ADMUX, REFS1);
#elif	SOURCE == AVCC
	 SET_BIT(ADMUX, REFS0);
	 CLR_BIT(ADMUX, REFS1);
#elif	SOURCE == INTERNAL
	 SET_BIT(ADMUX, REFS0);
	 SET_BIT(ADMUX, REFS1);
#endif

#if 	ADJUST == LEFT
	SET_BIT(ADMUX, ADLAR);
#elif	ADJUST == RIGHT
	CLR_BIT(ADMUX, ADLAR);
#endif

#if 	PRESCALAR == ADC_TWO
	PRESCALAR_SELECT(1);
#elif	PRESCALAR == ADC_FOUR
	PRESCALAR_SELECT(2);
#elif	PRESCALAR == ADC_EIGHT
	PRESCALAR_SELECT(3);
#elif	PRESCALAR == ADC_SIXTEEN
	PRESCALAR_SELECT(4);
#elif	PRESCALAR == ADC_THIRTYTWO
	PRESCALAR_SELECT(5);
#elif	PRESCALAR == ADC_SIXTYFOUR
	PRESCALAR_SELECT(6);
#elif	PRESCALAR == ADC_ONETWENTYEIGHT
	PRESCALAR_SELECT(7);
#endif
	SET_BIT(ADCSRA, ADEN);
}
void MADC_voidADCStart()
{
G_u8Check = 0;
SET_BIT(ADCSRA,ADSC);
}

void MADC_voidADCIsDone()
{
	while( GET_BIT(ADCSRA, ADIF) == 0);
	SET_BIT(ADCSRA, ADIF);
}

void MADC_voidADCDisable()
{
ADCSRA = 0x00;
}

void MADC_voidADCInt()
{
#if ADC_INT == ENABLE
	SET_BIT(ADCSRA, ADIE);
#elif
	CLR_BIT(ADCSRA, ADIE);
#endif
}

void MADC_voidADCSetCallBack ( void (*copy_ADCEndConv) (void))
{
	ADC_CONV_END = copy_ADCEndConv;
}

u16 MADC_u16ADCReturnValue (void)
{
#if 	ADJUST == RIGHT
		return ADCW;
#elif 	ADJUST == LEFT
		return (ADCW >>6);
#endif

}
ISR(ADC_vect)
{
	ADC_CONV_END();
}
