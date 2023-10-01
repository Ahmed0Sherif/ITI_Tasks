#include <avr/io.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/M_TMR/TIME_Interface.h"
#include "SERVO_Interface.h"
void HSERVO_voidServoTIMER1Init(void)
{
	MTIMER_voidTimer1FPWM_ICR_INIT();

	//Forces the timer to work at 50 Hz at 8MHz F_CPU
	TCCR1B = (TCCR1B & 0xf8) | 0x02;
	ICR1 = 19999;
}

void HSERVO_voidServoTIMER1Write(u8 copy_u8Angle)
{
	OCR1A = ((50* copy_u8Angle)+8991)/9;
/*@ copy_u8Angle = 0, OCR1A = 999
 *@ copy_u8Angle = 180, OCR1A = 1999
 * By solving the straight line equation.
 **/
}
