/*Assignment 3: Some operations on two numbers*/

#include <stdio.h>
void main()
{
	int a,b;
	printf("Please enter number a: ");
	scanf("%d",&a);
	printf("\nPlease enter number b: ");
	scanf("%d",&b);
	
	printf("a + b = %d", a + b);
	printf("\na - b = %d", a - b);
	printf("\na & b = %d", a & b);
	printf("\na | b = %d", a | b);
	printf("\na ^ b = %d", a ^ b);
}	