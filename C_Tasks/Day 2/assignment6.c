/*Assignment 6: Drawing a pyramid of certain height taken from user.*/

#include <stdio.h>
void main ()
{
	char levels,level_num,i;
	printf("Enter the number of levels: ");
	scanf("%d",&levels);
	
	for(level_num = 1; level_num <= levels; level_num++) /*Repeat for every level*/
	{
		for(i = levels -1; i >=level_num ;i--) /*Print spaces = number of levels - the level number*/
		{
			printf(" ");
		}
		for (i =1; i <=2*level_num -1; i++) /*Print 'x's = 2*level number + 1*/
		{
			printf("x");
		}
		printf("\n"); /*The end of each line.*/
	}
}