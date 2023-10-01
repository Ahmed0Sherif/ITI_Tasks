
/*Task 01: Display numbers from 0 to 9 then roll back*/
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

int main (void)
{
	char numbers [] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
	int i = 0;
	DDRA = 0b01111111;

	while(1)
	{
		for (i = 0; i < 10; i++)
		{
			PORTA = numbers[i];
			_delay_ms(500);
		}

		_delay_ms(1000);

		for (i = 8; i >= 0; i--)
			{
				PORTA = numbers[i];
				_delay_ms(500);
			}
	}
	return 0;
}
