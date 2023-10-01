
#include <stdio.h>
void bubSort( int* ptr);

void  main (void)
{
	int arr[10],i ;
	for (i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("\nEnter Element #%d: ", i);
		scanf("%d",&arr[i]);
	}
	bubSort(arr);
	printf("The sorted array:\n");
	for (i = 0; i < sizeof(arr) / sizeof(int); i++ )
	{
		printf("%d\t", arr[i]);
	}
}

void bubSort(int *ptr)
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			if( ptr[j] > ptr[j+1] )
			{
				ptr[j] = ptr[j] ^ ptr[j+1];
				ptr[j+1] = ptr[j] ^ ptr[j+1];
				ptr[j] = ptr[j] ^ ptr[j+1];
			}
		}
	}
}