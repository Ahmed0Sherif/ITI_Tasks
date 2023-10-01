#include <stdio.h>

void Print_arr(int *ptr,int n)
{
    printf("The Array elements are : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(ptr+i));
    }
}