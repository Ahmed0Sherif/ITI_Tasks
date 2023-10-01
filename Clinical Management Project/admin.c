
#include <stdio.h>
#include "admin.h"

extern Patient patientRecord[SIZE];
extern Reservation reserveRecord[RESERVE_SIZE];

Patient * P_Patient = patientRecord;
const Patient * P_BasePointer = patientRecord;

u8 ADMIN_u8AdminEnterPassword(void)
{	u16 L_u8pass;
	u8  L_u8Count = 0;
	printf("Enter Password: ");
	scanf("%d", &L_u8pass);
	for (L_u8Count = 0; L_u8Count < 2; L_u8Count ++)
	{
		if (L_u8pass == PASSWORD)
		{
			break;
		}
		else
		{
			printf("Wrong Password, Try Again (%d)\n", L_u8Count);
			scanf("%d", &L_u8pass);
		}
	}
	if (L_u8Count >= 3)
	{
		printf("\nInvalid.");
		return IS_INVALID;	
	}
	else
	{
		printf("\nWelcome, Admin.\n");
		return IS_VALID;	

	}
}

u8 ADMIN_u8AdminAddNewRec(void)
{
	u8 L_u8CurrentPlace, L_u8Counter = 0;
	u16 L_u8ID;
	L_u8CurrentPlace = P_Patient - P_BasePointer;
	if (L_u8CurrentPlace >= SIZE) //The Array is full
	{
		printf("The record is full");
		return FULL_NUMBER;
	}
	else //Adding new record
	{	printf("Writing in Slot #%d\n", L_u8CurrentPlace + 1);
		printf("Enter the ID:\n");
		scanf("%d",&L_u8ID);
		/*Checking if the ID already exists*/
		for (L_u8Counter = 0; L_u8Counter < SIZE; L_u8Counter++)
		{
			if ( patientRecord[L_u8Counter].ID == L_u8ID )
			{
			printf("ID Already Exisits.");
			return IS_INVALID;	
			}
		}
		//patientRecord[L_u8Counter].ID = L_u8ID ; //Issue found
		/*Reason of Issue = L_u8Counter does not correspond to the current location
		*solution: use the pointer P_Patient
		*
		*/
		P_Patient->ID = L_u8ID ;
		
		printf("Enter the Name:\n");
		//fgets(&P_Patient->Name,20,stdin);
		scanf("%s",&P_Patient->Name);
		printf("Enter the Age:\n");
		scanf("%d",&P_Patient->Age);
		printf("Male or Female?:\n");
		scanf("%s",&P_Patient->Gender);
		
		P_Patient++;
		return IS_VALID;
	}
	return IS_VALID;
}

u8 ADMIN_u8AdminEditRec(void)
{
	u16 L_u8ID;
	u8  L_u8Counter = 0;
	u8 L_u8Carrier;
	printf("Enter ID:\n");
	scanf("%d", &L_u8ID);
	
	for (L_u8Counter = 0; L_u8Counter < SIZE; L_u8Counter++)
	{
		if ( patientRecord[L_u8Counter].ID == L_u8ID )
		{
		printf("ID Found at Slot #%d. \n", L_u8Counter + 1);
		break;
		}
	}
	/*Checks for non-existant ID*/
	if (L_u8Counter >= SIZE) 
	{
		printf("ID is Not Found.\n");
		return NOT_FOUND;
	}
	
	printf("Patient #%d:\n",L_u8Counter + 1 );
	printf("Name: %s\n", patientRecord[L_u8Counter].Name);
	printf("Age: %d\n", patientRecord[L_u8Counter].Age);
	printf("Gender: %s\n", patientRecord[L_u8Counter].Gender);
	printf("Reservation: %d\n", patientRecord[L_u8Counter].reservationTime);
	
	L_u8Carrier = patientRecord[L_u8Counter].reservationTime;
	
	
	printf("Renter the Name:\n");
	scanf("%s",&patientRecord[L_u8Counter].Name);
	printf("Renter the Age:\n");
	scanf("%d",&patientRecord[L_u8Counter].Age);
	printf("Male or Female?:\n");
	scanf("%s",&patientRecord[L_u8Counter].Gender);
	patientRecord[L_u8Counter].reservationTime = L_u8Carrier;
	
	return IS_VALID;
}

u8 ADMIN_u8AdminReserve(void)
{	u16 L_u8ID;
	u8  L_u8Counter = 0, L_u8ReserveTimes = 0, L_u8TimeSlot;
	/*Printing Vacant Time Slots*/
	for (L_u8Counter = 0; L_u8Counter < RESERVE_SIZE; L_u8Counter ++)
	{
		if ( reserveRecord[L_u8Counter].Checked == 0 )
		{
			printf("%s\n",reserveRecord[L_u8Counter].timeSlot);
		}
		else
		{
			L_u8ReserveTimes ++;
		}
	}
	if (L_u8ReserveTimes == RESERVE_SIZE)
	{
		printf("All reservations are full.\n");
		return FULL_NUMBER;
	}
	
	printf("Select a time slot:\n");
	scanf("%d", &L_u8TimeSlot);
	fflush(stdin);		

	/*Possible Outcomes:
	*Out of Range Number
	*A Reserved Time Slot
	*Empty Slot
	*/
	
	if (L_u8TimeSlot >= 1 && L_u8TimeSlot <= 5)
	{		
			if ( reserveRecord[L_u8TimeSlot - 1].Checked == 1 )
			{
				printf("Busy Time Slot.");
				return BUSY;	
			}
	}
	else
	{
		printf ("Out Of Range.\n");
		return OUT_OF_RANGE;
	}
	
	/*if the time slot is vacant*/
	/*we take id*/
	printf("Enter ID:\n");
	scanf("%d", &L_u8ID);
	
	for (L_u8Counter = 0; L_u8Counter < SIZE; L_u8Counter++)
	{
		if ( patientRecord[L_u8Counter].ID == L_u8ID )
		{
		printf("ID Found at Slot #%d. \n", L_u8Counter + 1);
		break;
		}
	}
	/*Checks for non-existant ID*/
	if (L_u8Counter >= SIZE) 
	{
		printf("ID is Not Found.\n");
		return NOT_FOUND;
	}
	
	patientRecord[L_u8Counter].reservationTime = L_u8TimeSlot;
	reserveRecord[L_u8TimeSlot - 1].Checked = 1;
	
	printf("Patient of ID: %d is reserved at time slot %s", patientRecord[L_u8Counter].ID, reserveRecord[L_u8TimeSlot - 1].timeSlot);
	
	return IS_VALID;
}

u8 ADMIN_u8AdminCancel(void)
{	u16 L_u8ID;
	u8  L_u8Counter = 0, L_u8ReserveTimes = 5, L_u8TimeSlot;
	/*Printing Reserved Time Slots*/
	for (L_u8Counter = 0; L_u8Counter < RESERVE_SIZE; L_u8Counter ++)
	{
		if ( reserveRecord[L_u8Counter].Checked == 1 )
		{
			printf("%s\n",reserveRecord[L_u8Counter].timeSlot);
		}
		else
		{
			L_u8ReserveTimes --;
		}
	}
	if (L_u8ReserveTimes == 0)
	{
		printf("All Time Slots are available.\n");
		return AVAILABLE;
	}
	
	printf("Select a time slot:\n");
	scanf("%d", &L_u8TimeSlot);
	fflush(stdin);
	
		if (L_u8TimeSlot >= 1 && L_u8TimeSlot <= 5)
	{		
			if ( reserveRecord[L_u8TimeSlot - 1].Checked == 0 )
			{
				printf("busy time slot.");
				return AVAILABLE;	
			}
	}
	else
	{
		printf ("out of range.\n");
		return OUT_OF_RANGE;
	}
	
	/*if the time slot is reserved*/
	/*we take id*/
	printf("Enter ID:\n");
	scanf("%d", &L_u8ID);
	
	for (L_u8Counter = 0; L_u8Counter < SIZE; L_u8Counter++)
	{
		if ( patientRecord[L_u8Counter].ID == L_u8ID )
		{
		printf("ID Found at Slot #%d. \n", L_u8Counter + 1);
		break;
		}
	}
	/*Checks for non-existant ID*/
	if (L_u8Counter >= SIZE) 
	{
		printf("ID is Not Found.\n");
		return NOT_FOUND;
	}
	
	patientRecord[L_u8Counter].reservationTime = 0;
	reserveRecord[L_u8TimeSlot - 1].Checked = 0;
	
	printf("Patient of ID: %d has cancelled their reservation at time slot %s", patientRecord[L_u8Counter].ID, reserveRecord[L_u8TimeSlot - 1].timeSlot);
	
	return IS_VALID;
}
