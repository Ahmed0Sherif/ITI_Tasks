#include <stdio.h>




typedef struct 
{
	int id;
	int science;
	int math;
} student;

void main (void)
{
	int i_d, i;
	student arr [] = { {20, 54, 34},{20, 45, 64}, {30, 54, 76}, {40, 87, 34} };
	printf("Enter The ID: ");
	scanf("%d",&i_d);
	if (i_d < 10)
	{
		printf("Invaild ID.");
	}
	else
	{
		for (i = 0; i < 4; i++)
		{
			if (arr[i].id == i_d)
				break;
		}
		printf("Science: %d, Math: %d", arr[i].science, arr[i].math);
	}
}