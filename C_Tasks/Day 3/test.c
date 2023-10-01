
#include <stdio.h>
int fact(int num);
void main (void)
{
	int num;
	printf("Enter a number: ");
	scanf("%d",&num);
	
	printf("\nThe factorial of %d = %d",num,  fact(num));
}

int fact(int num)
{
	int result = 1;
	int multiplier = 1;
	do
	{
		result =  result * multiplier;
		multiplier++;
	//	printf("\nresult = %d, multiplier = %d, and the outFlag = %d", result, multiplier, multiplier < num + 1 );
	}
	while(multiplier < num + 1);
	return result;
}