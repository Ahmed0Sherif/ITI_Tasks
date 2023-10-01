
#include <stdio.h>

int min (int x, int y, int z, int k);
int max (int x, int y, int z, int k);


void main(void)
{
	int a, b, c, d;
	printf("Enter the 1st number: "); scanf("%d",&a);
	printf("Enter the 2nd number: "); scanf("%d",&b);
	printf("Enter the 3rd number: "); scanf("%d",&c);
	printf("Enter the 4th number: "); scanf("%d",&d);
	
	printf ("The minimum number among these is: %d", min (a,b,c,d) );
	printf ("\nThe maximum number among these is: %d", max (a,b,c,d) );
}

int min (int x, int y, int z, int k)
{
	int min;
	if (x < y)
	{
		if (x < z)
		{
			if (x < k)
			{
				min = x;
			}
			else
			{
				min = k;
			}
		}
		else
		{
			if (z < k)
			{
				min = z;
			}
			else
			{
				min = k;
			}
		}
	}
	else
	{
		if (y < z)
		{
			if (y < k)
			{
				min = y;
			}
			else
			{
				min = k;
			}
		}
		else
		{
			if (z < k)
			{
				min = z;
			}
			else
			{
				min = k;
			}

		}
	}
	return min;
}

int max (int x, int y, int z, int k)
{
	int max;
	if (x > y)
	{
		if (x > z)
		{
			if (x > k)
			{
				max = x;
			}
			else
			{
				max = k;
			}
		}
		else
		{
			if (z > k)
			{
				max = z;
			}
			else
			{
				max = k;
			}
		}
	}
	else
	{
		if (y > z)
		{
			if (y > k)
			{
				max = y;
			}
			else
			{
				max = k;
			}
		}
		else
		{
			if (z > k)
			{
				max = z;
			}
			else
			{
				max = k;
			}

		}
	}
	return max;
}
