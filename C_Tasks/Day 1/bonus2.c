/*Bonus 2: Setting, Clearing, Toggling and Reading bits*/

#include <stdio.h>
void main ()
{
	int number;
	int bit_no;
	printf("Enter the number: ");
	scanf("%d", &number);
	printf("\nEnter the bit number: ");
	scanf("%d", &bit_no);
	
	
	printf ("\nSetting the bin #%d in %d = %d", bit_no, number, number | (1 << bit_no));
	printf ("\nClearing the bin #%d in %d = %d", bit_no, number, number & ~(1 << bit_no));
	printf ("\nToggling the bin #%d in %d = %d", bit_no, number, number ^ (1 << bit_no));
	printf ("\nReading the bin #%d in %d = %d", bit_no, number, (number & (1 << bit_no))>>bit_no);
}