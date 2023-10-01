/***********************************/

/*******************Hard Exercises**************************/

#include <stdio.h>
	int  Add_Sub(int a, int b);
void main (void)
{
	// int i,j;
	// for (i =0, j = 0; i< 7, j <5; i++, j++)
	// {
		// printf("Hi \n");
	// }
	// printf("%d %d", i, j);
	
	
	
	// int i =1, j =2;
	// switch (i,j)
	// {
		// case 0 : printf("a"); break;
		// case 1: printf("b"); break;
		// default: printf("Nope");
	// }
/*Hint, The complier checks the rightmost condition*/




	// int i = 0, j = 1, k =2, m;
	// m = i ++ || j ++|| k ++;
	// printf("%d, %d, %d, %d", m, i, j, k);
	
	// int i;
	// i = 1, 2, 3;
	// int j;
	// j = (1, 2, 3);
	// printf("%d\n",i);
	// printf("%d\n",j);

	int a = 20, b = 10, sum;
	sum = Add_Sub(a,b);
	printf("%d", sum);
}
int Add_Sub(int a, int b)
{
	// return x + y;
	// return x - y;
	return a + b, a - b;
}

