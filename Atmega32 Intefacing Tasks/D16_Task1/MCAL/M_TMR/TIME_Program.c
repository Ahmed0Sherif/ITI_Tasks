#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "math.h"
#include <avr/interrupt.h>
#include "../M_DIO/MDIO_Interface.h"
#include "TIME_Interface.h"

#define NULL ((void *)0)

static void (*TIMER_PFTIMER0OVF)(void);


static void (*TIMER_PFTIMER2OVF)(void);
static void (*TIMER_PFTIMER2COMP)(void);

static u8  L_u8Reg;
static u32 G_u32Overflows;


static u8 G_u8Check;
////////////////////////////////////////////////////////////////////////////////////////



void MTIMER_voidTimer0OVFInit(void)
{
	/*CHOOSE NORMAL MODE*/
		CLR_BIT(TCCR0, WGM00);
		CLR_BIT(TCCR0, WGM01);

		SET_BIT(TIMSK, TOIE0);

#if		CLK == ONE
		TCCR0 = (TCCR0 & 0xf8) | 0x01;
#elif 	CLK == EIGHT
		TCCR0 = (TCCR0 & 0xf8) | 0x02;
#elif 	CLK == SIXTYFOUR
		TCCR0 = (TCCR0 & 0xf8) | 0x03;
#elif 	CLK == TWOFIFTYSIX
		TCCR0 = (TCCR0 & 0xf8) | 0x04;
#elif 	CLK == TENTWENTYFOUR
		TCCR0 = (TCCR0 & 0xf8) | 0x05;
#elif 	CLK == EXTERN_FALLING
		TCCR0 = (TCCR0 & 0xf8) | 0x06;
#elif 	CLK == EXTERN_RISING
		TCCR0 = (TCCR0 & 0xf8) | 0x07;
#endif

}

void MTIMER_voidTimer0OVFDelay(u32 copy_u32Delay_ms)
{
	f32 L_f32MaxCompare;
	f32 L_f32OverFlowCount;
	u32 L_u32Carry;
	u8 L_u8Offset;

	G_u8Check = 0;
	MTIMER_voidTimer0OVFInit();

#if		CLK == ONE
		L_f32MaxCompare = (1000000.0) / F_CPU;
		L_f32MaxCompare = L_f32MaxCompare * 256;
#elif 	CLK == EIGHT
		L_f32MaxCompare = (1000000.0) / F_CPU;
		L_f32MaxCompare = L_f32MaxCompare * 256 * 8;
#elif 	CLK == SIXTYFOUR
		L_f32MaxCompare = (1000000.0) / F_CPU;
		L_f32MaxCompare = L_f32MaxCompare * 256 * 64;
#elif 	CLK == TWOFIFTYSIX
		L_f32MaxCompare = (1000000.0) / F_CPU;
		L_f32MaxCompare = L_f32MaxCompare * 256 * 256;
#elif 	CLK == TENTWENTYFOUR
		L_f32MaxCompare = (1000000.0) / F_CPU;
		L_f32MaxCompare = L_f32MaxCompare * 256 * 1024;

#endif


	if (copy_u32Delay_ms * 1000  <= L_f32MaxCompare)
		{
			L_f32OverFlowCount = (copy_u32Delay_ms / (L_f32MaxCompare/1000.0));
			L_u8Offset = L_f32OverFlowCount * 256.0;
			G_u32Overflows = 1;
			L_u8Reg = 256 - L_u8Offset;
			TCNT0 = L_u8Reg;
		}
	else
		{
			L_f32OverFlowCount = (copy_u32Delay_ms / (L_f32MaxCompare/1000.0));
			L_u32Carry = (copy_u32Delay_ms / (L_f32MaxCompare/1000));

			L_u8Offset = (L_f32OverFlowCount - L_u32Carry) * 256.0;
			G_u32Overflows = L_u32Carry +1 ;
			L_u8Reg = 256 - L_u8Offset;
			TCNT0 = L_u8Reg;
		}

		while (GET_BIT(TIFR, TOV0) == 0 && G_u8Check == 0);
}

void MTIMER_voidTimer0OVFSetCallBack ( void (*copy_PFvoidTimer0OVF) (void))
{
	TIMER_PFTIMER0OVF = copy_PFvoidTimer0OVF ;
}

ISR (TIMER0_OVF_vect)
{
	static u32 L_u32OVFCounter = 0 ;
	L_u32OVFCounter ++ ;
	if (L_u32OVFCounter == G_u32Overflows)
	{
		L_u32OVFCounter = 0 ;
		TCNT0 = L_u8Reg;
		TIMER_PFTIMER0OVF() ;
		G_u8Check = 1;
	}
}




////////////////////////////////////////////////////////////////////////////////////////

void MTIMER_voidTimer2COMPInit(void)

{
	/*CHOOSE CTC MODE*/
		CLR_BIT(TCCR2, WGM20);
		SET_BIT(TCCR2, WGM21);

		SET_BIT(TIMSK, OCIE2);

#if		CLK == ONE
		TCCR2 = (TCCR2 & 0xf8) | 0x01;
#elif 	CLK == EIGHT
		TCCR2 = (TCCR2 & 0xf8) | 0x02;
#elif 	CLK == THRITYTWO
		TCCR2 = (TCCR2 & 0xf8) | 0x03;
#elif 	CLK == SIXTYFOUR
		TCCR2 |= (1<<2);
		//TCCR2 = (TCCR2 & 0xf8) | 0x04;
#elif 	CLK == ONETWENTYEIGHT
		TCCR2 = (TCCR2 & 0xf8) | 0x05;
#elif 	CLK == TWOFIFTYSIX
		TCCR2 = (TCCR2 & 0xf8) | 0x06;
#elif 	CLK == TENTWENTYFOUR
		TCCR2 = (TCCR2 & 0xf8) | 0x07;
#endif

}

void MTIMER_voidTimer2COMPDelay(u8 copy_u8Offset, u32 copy_u32Counts)
{
	G_u8Check = 0;

	G_u32Overflows = copy_u32Counts;
	OCR2 = copy_u8Offset;

	MTIMER_voidTimer2COMPInit();
	while (GET_BIT(TIFR, OCF2) == 0  &&  G_u8Check == 0);
	SET_BIT(TIFR, OCF2);
	TCCR2 =0;

	}

void MTIMER_voidTimer2COMPSetCallBack ( void (*copy_PFvoidTimer2CTC) (void))
{
	TIMER_PFTIMER2COMP = copy_PFvoidTimer2CTC ;
}


void MTIMER_voidTimer2OVFInit(void)

{
	/*CHOOSE NORMAL MODE*/
		CLR_BIT(TCCR2, WGM20);
		CLR_BIT(TCCR2, WGM21);

		SET_BIT(TIMSK, TOIE2);

#if		CLK == ONE
		TCCR2 = (TCCR2 & 0xf8) | 0x01;
#elif 	CLK == EIGHT
		TCCR2 = (TCCR2 & 0xf8) | 0x02;
#elif 	CLK == THRITYTWO
		TCCR2 = (TCCR2 & 0xf8) | 0x03;
#elif 	CLK == SIXTYFOUR
		TCCR2 |= (1<<2);
		//TCCR2 = (TCCR2 & 0xf8) | 0x04;
#elif 	CLK == ONETWENTYEIGHT
		TCCR2 = (TCCR2 & 0xf8) | 0x05;
#elif 	CLK == TWOFIFTYSIX
		TCCR2 = (TCCR2 & 0xf8) | 0x06;
#elif 	CLK == TENTWENTYFOUR
		TCCR2 = (TCCR2 & 0xf8) | 0x07;
#endif

}

void MTIMER_voidTimer2OVFDelay(u32 copy_u32Delay_ms)
{
	f32 L_f32MaxCompare;
	f32 L_f32OverFlowCount;
	u32 L_u32Carry;
	u8 L_u8Offset;

	G_u8Check = 0;

	MTIMER_voidTimer2OVFInit();

#if		CLK == ONE
		L_f32MaxCompare = (1000000.0) / F_CPU;
		L_f32MaxCompare = L_f32MaxCompare * 256;
#elif 	CLK == EIGHT
		L_f32MaxCompare = (1000000.0) / F_CPU;
		L_f32MaxCompare = L_f32MaxCompare * 256 * 8;
#elif 	CLK == THRITYTWO
		L_f32MaxCompare = (1000000.0) / F_CPU;
		L_f32MaxCompare = L_f32MaxCompare * 256 * 32;
#elif 	CLK == SIXTYFOUR
		L_f32MaxCompare = (1000000.0) / F_CPU;
		L_f32MaxCompare = L_f32MaxCompare * 256 * 64;
#elif 	CLK == ONETWENTYEIGHT
		L_f32MaxCompare = (1000000.0) / F_CPU;
		L_f32MaxCompare = L_f32MaxCompare * 256 * 128;
#elif 	CLK == TWOFIFTYSIX
		L_f32MaxCompare = (1000000.0) / F_CPU;
		L_f32MaxCompare = L_f32MaxCompare * 256 * 256;
#elif 	CLK == TENTWENTYFOUR
		L_f32MaxCompare = (1000000.0) / F_CPU;
		L_f32MaxCompare = L_f32MaxCompare * 256 * 1024;

#endif


	if (copy_u32Delay_ms * 1000  <= L_f32MaxCompare)
		{
			L_f32OverFlowCount = (copy_u32Delay_ms / (L_f32MaxCompare/1000.0));
			L_u8Offset = L_f32OverFlowCount * 256.0;
			G_u32Overflows = 1;
			L_u8Reg = 256 - L_u8Offset;
			TCNT2 = L_u8Reg;
		}
	else
	{
		L_f32OverFlowCount = (copy_u32Delay_ms / (L_f32MaxCompare/1000.0));
		L_u32Carry = (copy_u32Delay_ms / (L_f32MaxCompare/1000));

		L_u8Offset = (L_f32OverFlowCount - L_u32Carry) * 256.0;
		G_u32Overflows = L_u32Carry +1 ;
		L_u8Reg = 256 - L_u8Offset;
		TCNT2 = L_u8Reg;

	}

	while (GET_BIT(TIFR, TOV2) == 0 && G_u8Check == 0);
}

void MTIMER_voidTimer2OVFSetCallBack ( void (*copy_PFvoidTimer2OVF) (void))
{
	TIMER_PFTIMER2OVF = copy_PFvoidTimer2OVF ;
}



ISR (TIMER2_OVF_vect)
{
	static u32 L_u32OVFCounter = 0 ;
	L_u32OVFCounter ++ ;
	if (L_u32OVFCounter == G_u32Overflows)
	{
		L_u32OVFCounter = 0 ;
		TCNT2 = L_u8Reg;
		TIMER_PFTIMER2OVF() ;
		G_u8Check = 1;
	}
}


ISR (TIMER2_COMP_vect)
{
	static u32 G_u32CompCounter = 0;
	G_u32CompCounter ++ ;

	if ( G_u32Overflows == G_u32CompCounter)
	{
		TIMER_PFTIMER2COMP() ;
		G_u32CompCounter = 0 ;
		SET_BIT(TIFR, OCF2);
		G_u8Check = 1;
	}

}

