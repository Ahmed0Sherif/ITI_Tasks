
#include <stdio.h>

void add(int* x, int *y, int* sum);

// void addArr(int* ptr);

void main (void)
{
	int x = 53000;
	char y = 83;
	int arr [] = {1, 2, 3, 4, 5, 6};
	int * ptr1 = &x;
	char* ptr2 = &y;
	printf("%d\n",x); //Value of x
	printf("%p\n",&x); //Address of x
	printf("%d\n",ptr1); //address stored in pointer
	printf("%d\n",*ptr1); //value accessed by pointer
	printf("%p\n",&ptr1); //address of pointer itself
	ptr1 ++;
	printf("%d\n",ptr1); //address stored in pointer
	printf("%d\n", sizeof(x));
	printf("%d\n", sizeof(ptr1));
	printf("%d\n",sizeof(ptr2));
	printf("\n\n\n");
	
	int *ptrArr = arr; //pointer to the first element in the array
	int (*arrPtr)[] = arr; ; //pointer to the whole array;
	
	printf("%d\n", ptr1);
	printf("%d\n", ++ptr1);
	printf("%d\n", ptr2);
	printf("%d\n\n", ++ptr2);
	
	printf("%d\n", ptrArr);
	printf("%d\n", ptrArr +1);
	printf("%d\n", arrPtr);
//	printf("%d\n",arrPtr +1 );
	

	
	printf("\n\n\n");
	printf("%d\n",sizeof(arr)/sizeof(int));
	printf("%d\n",sizeof(ptrArr));
	printf("%d\n",sizeof(*arrPtr));
}

// void (int*ptr)
// {
	// int i;
	// for (i = 0; i < () )
// }

void add(int* x, int* y, int* sum)
{
	*sum = *x + *y;
}