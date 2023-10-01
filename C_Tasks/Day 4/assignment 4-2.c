#include <stdio.h>

void main (void)
{
	int x = 7, y = 23, z = 5;
	int* p = & x; int* q = &y; int* r = &z;
	
	/************First Requirement****************/
	printf("The value of x = %d\n",x);
	printf("The value of y = %d\n",y);
	printf("The value of z = %d\n",z);
	printf("The value of p = %p\n",p);
	printf("The value of q = %p\n",q);
	printf("The value of r = %p\n",r);
	printf("The value accessed by p = %d\n",*p);
	printf("The value accessed by q = %d\n",*q);
	printf("The value accessed by r = %d\n",*r);
	
	/************Second and Third Requirement****************/
	printf("\n\n Swapping Pointers... \n\n");
	r = p; p = q; q = r;
	
	/************Fourth Requirement****************/
	printf("The value of x = %d\n",x);
	printf("The value of y = %d\n",y);
	printf("The value of z = %d\n",z);
	printf("The value of p = %p\n",p);
	printf("The value of q = %p\n",q);
	printf("The value of r = %p\n",r);
	printf("The value accessed by p = %d\n",*p);
	printf("The value accessed by q = %d\n",*q);
	printf("The value accessed by r = %d\n",*r);
}