#include <stdio.h>
#include <string.h>
typedef struct myCar
{
	int plate;
	char  color [7];
	int price;
} Car ;

void main (void)
{
	Car *ptr;  
	Car car_arr [3];
	int i;
	
	for (i = 0; i< 3; i++)
	{
		printf("For Car#%d:\n\n", i+1);
		printf("Enter the plate number: "); scanf("%d",&car_arr[i].plate);
		printf("Enter the color: "); scanf("%s",&car_arr[i].color);
		printf("Enter the price: "); scanf("%d",&car_arr[i].price);
	}
	printf("\n\n\nPrinting the array using the stuct itself:\n\n\n");
	for (i =0; i < 3; i++)
	{
		printf("User#%d's Car:\n", i + 1);
		printf("Car's Plate No: %d\n", car_arr[i].plate);
		printf("Car's Color: %s\n", car_arr[i].color);
		printf("Car's price: %d\n\n\n", car_arr[i].price);
	}
	
	printf("Printing the array using the a pointer:\n\n\n");
	ptr = car_arr;
	for (i =0; i < 3; i++)
	{
		printf("User#%d's Car:\n", i + 1);
		printf("Car's Plate No: %d\n", ptr-> plate);
		printf("Car's Color: %s\n", ptr ->color);
		printf("Car's price: %d\n\n\n", ptr->price);
		ptr ++;
	}
	
}