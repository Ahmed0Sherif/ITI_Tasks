#ifndef SEVEN_INTERFACE_H
#define SEVEN_INTERFACE_H

/*Regarding Pin Mapping
Each pin of the seven segement is
mapped to each pin of any port as follows:

A -> 0	B -> 1	
C -> 2	D -> 3	
E -> 4	F -> 5
G -> 6	
*/
#define ZERO	0b00111111
#define ONE		0b00000110
#define TWO		0b01011011
#define THREE	0b01001111
#define FOUR	0b01100110
#define FIVE	0b01101101
#define SIX		0b01111101
#define SEVEN	0b00000111
#define EIGHT	0b01111111
#define NINE	0b01101111

void HSEVEN_voidSevenInitDisplay (u8 copy_u8Port);
void HSEVEN_voidSevenShowNum(u8 copy_u8Port, u8 number);


#endif
