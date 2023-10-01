
/*Assignment 2: ID and Password*/

#include <stdio.h>

void main ()
{
	int user_ID = 18012341;
	int user_PASS = 192837465;
	
	int id, pass;
	
	printf("Enter your ID: ");
	scanf("%d",&id);
	 
	if (id == user_ID)
	{
		printf("Enter your password: ");
		scanf("%d",&pass);
		if(pass == user_PASS)
		{
			printf("Welcome, %d.", user_ID);
		}
		else
		{
			printf("Incorrect Password.");
		}
	}
	else
	{
		printf("Incorrect ID.");
	}
	
}