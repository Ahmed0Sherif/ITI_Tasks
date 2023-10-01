
/*Assignment 2: A simple calculator*/

#include <stdio.h>

float CAL_add(float x, float y);
float CAL_subtract (float x, float y);
float CAL_multiply(float x, float y);
float CAL_divide (float x, float y);
int CAL_and (int x, int y);
int CAL_or  (int x, int y);
int CAL_not (int x);
int CAL_xor (int x, int y);
int CAL_rem (int x, int y);
int CAL_inc (int x);
int CAL_dec (int x);


void main (void)
{
	char operation;
	float x, y;
	int a,b;
	printf("Choose the operation:\n");
	printf("Addition: 1\n");
	printf("Subtraction: 2\n");
	printf("Multiplication: 3\n");
	printf("Division: 4\n");
	printf("Bitwise AND: 5\n");
	printf("Bitwise OR: 6\n");
	printf("Bitwise NOT: 7\n");
	printf("Bitwise XOR: 8\n");
	printf("Remainder: 9\n");
	printf("Increment: 10\n");
	printf("Decrement: 11\n");
	scanf("%d", &operation);
	
	switch (operation)
	{
		case 1:
		printf("Enter the operands:\n");
		scanf("%f%f",&x,&y);
		printf("The sum = %f",CAL_add(x,y) );
		break;
		
		case 2:
		printf("Enter the operands:\n");
		scanf("%f%f",&x,&y);
		printf("The difference = %f",CAL_subtract(x,y) );
		break;
		
		case 3:
		printf("Enter the operands:\n");
		scanf("%f%f",&x,&y);
		printf("The product = %f",CAL_multiply(x,y) );
		break;
		
		case 4:
		printf("Enter the operands:\n");
		scanf("%f%f",&x,&y);
		printf("The quoitient = %f",CAL_divide(x,y) );
		break;
		
		case 5:
		printf("Enter the operands:\n");
		scanf("%d%d",&a,&b);
		printf("The result = %d",CAL_and(a,b) );
		break;
		
		case 6:
		printf("Enter the operands:\n");
		scanf("%d%d",&a,&b);
		printf("The result = %d",CAL_or(a,b) );
		break;
		
		case 7:
		printf("Enter the operand:\n");
		scanf("%d",&a);
		printf("The result = %d",CAL_not(a) );
		break;
		
		case 8:
		printf("Enter the operands:\n");
		scanf("%d%d",&a,&b);
		printf("The result = %d",CAL_xor(a, b) );
		break;
		
		case 9:
		printf("Enter the operands:\n");
		scanf("%d%d",&a,&b);
		printf("The remainder = %d",CAL_rem(a,b) );
		break;
		
		case 10:
		printf("Enter the operand:\n");
		scanf("%d",&a);
		printf("The result = %d",CAL_inc(a) );
		break;
		
		case 11:
		printf("Enter the operand:\n");
		scanf("%d",&a);
		printf("The result = %d",CAL_dec(a) );
		break;
		
		default:
		printf("Please Enter a correct operation.");
	}
}



