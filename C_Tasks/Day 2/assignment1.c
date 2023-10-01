/*Assignment 1: Searching for a number among 10 entered numbers*/

#include <stdio.h>

void main ()
{
	int i, num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, target;
	
	printf("Enter Number 1: ");	scanf("%d",&num1);
	printf("Enter Number 2: ");	scanf("%d",&num2);
	printf("Enter Number 3: ");	scanf("%d",&num3);
	printf("Enter Number 4: ");	scanf("%d",&num4);
	printf("Enter Number 5: ");	scanf("%d",&num5);
	printf("Enter Number 6: ");	scanf("%d",&num6);
	printf("Enter Number 7: ");	scanf("%d",&num7);
	printf("Enter Number 8: ");	scanf("%d",&num8);
	printf("Enter Number 9: ");	scanf("%d",&num9);
	printf("Enter Number 10: ");scanf("%d",&num10);
	printf("Enter The value you want to search: ");scanf("%d",&target);
	
	if(target == num1)
		printf("Value exists in element #1");
	else if(target == num2)
		printf("Value exists in element #2");
	else if(target == num3)
		printf("Value exists in element #3");
	else if(target == num4)
		printf("Value exists in element #4");
	else if(target == num5)
		printf("Value exists in element #5");
	else if(target == num6)
		printf("Value exists in element #6");
	else if(target == num7)
		printf("Value exists in element #7");
	else if(target == num8)
		printf("Value exists in element #8");
	else if(target == num9)
		printf("Value exists in element #9");
	else if(target == num10)
		printf("Value exists in element #10");
	else
		printf("Apologies, but your value does not exist.");
}