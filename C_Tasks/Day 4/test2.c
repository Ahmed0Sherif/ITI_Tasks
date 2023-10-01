#include <stdio.h>

int scalar (int* ptr1, int* ptr2);
void main (void)
{
	int arr1[5] = {2, 3};
	int arr2[5] = {2, 3};	
	printf("%d",scalar(arr1, arr2));
}

int scalar (int* ptr1, int* ptr2)
{
	int i,result = 0;
	for (i = 0; i < 2; i++)
	{
		result = result + ptr1[i] * (ptr2[i]);
	}
	return result;
}