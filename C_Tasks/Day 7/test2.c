
#include <stdio.h>
extern int reference;
extern int x;


void compareRef(int length, float* correction)
{
	reference = 4;
	if (length <= reference)
		*correction = length * 0.5;
	else
		*correction = -length * 0.5;
}

void printX()
{
	printf("%d", x);
}