/*Assignmnet 4: School Statistics*/

#include <stdio.h>

void main()
{
	/**********Arrays and Variables****************/
	int classA [10] = {65, 46, 76, 92, 45, 56, 86, 24, 98, 77};
	int classB [10]	= {88, 59, 67, 78, 40, 76, 64, 86, 34, 92};
	int classC [10] = {77, 24, 60, 71, 51, 54, 76, 57, 61, 55};
	
	int min_grade = 50;
	int i, j, passed = 0, failed = 0;
	float average;
	
	/***************Analyzing Each Array******************/
	
	//ClassA
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			if ( classA[j] > classA[j+1] )
			{
				classA[j] = classA[j] ^ classA[j+1];
				classA[j+1] = classA[j] ^ classA[j+1];
				classA[j] = classA[j] ^ classA[j+1];
			}
		}
	}
	
	for (i = 0; i < 10; i++)
	{
		if (classA[i] >= min_grade)
			passed ++;
		else
			failed ++;
		average = average + classA[i];
	}
	average = average / 10.0;
	printf("\n\nFor Class A:\n %d students passed, while %d students failed.", passed, failed);
	printf("\n The highest grade is: %d, the lowest grade: %d, and the average: %2f", classA[9], classA[0],average);
	
	
	//ClassB
	average = 0; failed = 0; passed = 0;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			if ( classB[j] > classB[j+1] )
			{
				classB[j] = classB[j] ^ classB[j+1];
				classB[j+1] = classB[j] ^ classB[j+1];
				classB[j] = classB[j] ^ classB[j+1];
			}
		}
	}
	
	for (i = 0; i < 10; i++)
	{
		if (classB[i] >= min_grade)
			passed ++;
		else
			failed ++;
		average = average + classB[i];
	}
	average = average / 10.0;
	printf("\n\nFor Class B:\n %d students passed, while %d students failed.", passed, failed);
	printf("\n The highest grade is: %d, the lowest grade: %d, and the average: %f", classB[9], classB[0],average);
	
	
	//ClassC
	average = 0; failed = 0; passed = 0;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			if ( classC[j] > classC[j+1] )
			{
				classC[j] = classC[j] ^ classC[j+1];
				classC[j+1] = classC[j] ^ classC[j+1];
				classC[j] = classC[j] ^ classC[j+1];
			}
		}
	}
	
	for (i = 0; i < 10; i++)
	{
		if (classC[i] >= min_grade)
			passed ++;
		else
			failed ++;
		average = average + classC[i];
	}
	average = average / 10.0;
	printf("\n\nFor Class C:\n %d students passed, while %d students failed.", passed, failed);
	printf("\n The highest grade is: %d, the lowest grade: %d, and the average: %f", classC[9], classC[0],average);
}