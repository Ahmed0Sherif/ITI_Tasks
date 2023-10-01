/*Assignment 3: Minimum and Maximum within an array*/

#include <stdio.h>

void main ()
{
	/*******Array Initialization*******/
	int arr [10], i, j;
	for (i = 0; i < 10; i++)
	{
		printf("\nEnter Element #%d: ", i);
		scanf("%d",&arr[i]);
	}
	
	/********Sorting the array********/
	
	for (i = 0; i < 9; i++ ) //Loop for each iteration
	{
		for (j = 0 ; j < 9 - i; j++)
		{
			if ( arr[j] > arr [j +1] ) //If true, perform swap
			{
				arr[j] = arr[j] ^ arr[j + 1];
				arr[j + 1] = arr[j] ^ arr[j + 1];
				arr[j] = arr[j] ^ arr[j + 1];
			}
		}
	}
	
	printf("The minimum value = %d\nThe maximum value = %d.",arr[0],arr[9]);
}