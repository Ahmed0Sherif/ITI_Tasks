/*Assignment 5: Login*/

#include <stdio.h>

void main ()
{
	int user_1 = 1234, pass_1 = 7788,	//Ahmed
	user_2 = 5678, pass_2 = 5566,		//Amr
	user_3 = 9870, pass_3 = 1122;		//Wael
	
	int user, pass;
	
	int i;
	
	printf("Please Enter your ID: "); scanf("%d", &user);
	switch(user)
	{
		case 1234:
			printf("Please Enter your Password: "); scanf("%d", &pass);
			if (pass != 7788)
			{
				for (i = 1; i <= 2; i++)
				{
					printf("Try Again: "); scanf("%d", &pass);
					if (pass == 7788)
						break;
				}
				if (i > 2)
					printf("Incorrect Password for 3 times, No more tries.");
				else
					printf("Welcome, Ahmed.");
			}
			else
				printf("Welcome, Ahmed.");
			break;
			
		case 5678:
			printf("Please Enter your Password: "); scanf("%d", &pass);
			if (pass != 5566)
			{
				for (i = 1; i <= 2; i++)
				{
					printf("Try Again: "); scanf("%d", &pass);
					if (pass == 5566)
						break;
				}
				if (i > 2)
					printf("Incorrect Password for 3 times, No more tries.");
				else
					printf("Greetings, Amr.");
			}
			else
				printf("Greetings, Amr.");
			break;
			
		case 9870:
			printf("Please Enter your Password: "); scanf("%d", &pass);
			if (pass != 1122)
			{
				for (i = 1; i <= 2; i++)
				{
					printf("Try Again: "); scanf("%d", &pass);
					if (pass == 1122)
						break;
				}
				if (i > 2)
					printf("Incorrect Password for 3 times, No more tries.");
				else
					printf("Hello, Wael.");
			}
			else
				printf("Hello, Wael.");
			break;
			
		default:
			printf("You are not registered.");
	}
}