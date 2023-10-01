/*Bonus 1: Swapping Variables*/

 #include <stdio.h>
 
 void main()
 {
	int num1, num2, temp;
	printf("Enter num1 and num2:");
	scanf("%d%d",&num1, &num2);
	printf("Num1 and Num2 before swapping: %d %d", num1, num2);
	
	/*Swapping*/
	temp = num2;
	num2 = num1;
	num1 = temp;
	printf("\nNum1 and Num2 after swapping: %d %d", num1, num2);
	
 }