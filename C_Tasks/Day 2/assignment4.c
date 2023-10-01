/*Assignment 4: Endless Summation Program*/

#include <stdio.h>
void main()
{
	int num1, num2;
	while (1)
	{
		printf("\nPlease Enter the first number: "); scanf("%d", &num1);
		printf("\nPlease Enter the second number: "); scanf("%d", &num2);
		printf("The result is %d \n", num1 + num2);
	}
}