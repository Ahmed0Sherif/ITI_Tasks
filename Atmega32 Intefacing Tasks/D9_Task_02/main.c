/*Task 02: Display birthday*/
/*July 7th*/
#include <avr/io.h>
#include <util/delay.h>

/*Codes:          gbcdefa*/
#define ZERO	0b0111111
#define ONE 	0b0110000
#define TWO		0b1101101
#define THREE	0b1111001
#define FOUR	0b1110010
#define FIVE	0b1011011
#define SIX 	0b1011111
#define SEVEN	0b0110001
#define EIGHT	0b1111111
#define NINE	0b1111011

/*Task 01: Display numbers from 0 to 9 then roll back*/
int main (void)
{
	DDRA = 0b01111111;
	DDRB = 0b01111111;
	while(1)
	{
		PORTA = THREE;
		PORTB = TWO;
		_delay_ms(1000);


		PORTA = EIGHT;
		PORTB = ZERO;
		_delay_ms(1000);

	}
	return 0;
}
