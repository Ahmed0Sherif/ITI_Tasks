
#include <stdio.h>
#include <math.h>



void main ()
{
	float a,b,c;
	float discriminator;
	int sign;
	printf("Enter The Coefficients of the quadratic equation: ");
	scanf("%f%f%f", &a,&b,&c);
	discriminator = pow(b,2) - 4*a*c;
	sign = discriminator > 0 ? 1 : (discriminator < 0 ? -1 : 0);
	
	switch(sign)
	{
		case 1:
		case 0:
			printf("Solutions are: %f and %f", (-b+sqrt(discriminator))/2*a , ( -b-sqrt(discriminator) )/2*a );
			break;
		case -1:
			printf("Solutions are: %f + j%f and %f + j%f", (-b/2*a) , (sqrt(-discriminator))/2*a, (-b/2*a) , -(sqrt(-discriminator))/2*a );
			break;
	}
}