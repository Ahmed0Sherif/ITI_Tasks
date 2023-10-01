/*Assignmnet 4: School Statistics*/


/*This program is the correct one for this assignment. The other one is due to misunderstanding the assignment.*/
#include <stdio.h>

void main()
{
	/**********Arrays and Variables****************/
	int classA [10] = {65, 46, 76, 92, 45, 56, 86, 24, 98, 77};
	int classB [10]	= {88, 59, 67, 78, 40, 76, 64, 86, 34, 92};
	int classC [10] = {77, 24, 60, 71, 51, 54, 76, 57, 61, 55};
	
	int min_grade = 50;
	int i, j, A_passed = 0, A_failed = 0,  B_passed = 0, B_failed = 0, C_passed = 0, C_failed = 0;
	int A_sum = 0, B_sum = 0, C_sum = 0;
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
			A_passed ++;
		else
			A_failed ++;
		A_sum = A_sum + classA[i];
	}
	
	//ClassB
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
			B_passed ++;
		else
			B_failed ++;
		B_sum = B_sum + classB[i];
	}

	//ClassC
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
			C_passed ++;
		else
			C_failed ++;
		C_sum = C_sum + classC[i];

	}
	average = (A_sum + B_sum + C_sum) / 30.0;
	
	printf("Number of passed students: %d\n", A_passed + B_passed + C_passed );
	printf("Number of failed students: %d\n", A_failed + B_failed + C_failed );
	printf("The highest grade is: %d\n", classA[9] > classB[9] ? (classA[9] > classC[9]? classA[9] : classC[9]) : (classB[9] > classC[9]? classB[9] : classC[9]));
	printf("The lowest grade is: %d\n", classA[0] < classB[0] ? (classA[0] < classC[0]? classA[0] : classC[0]) : (classB[0] < classC[0]? classB[0] : classC[0]));
	printf("The average: %f", average);

}