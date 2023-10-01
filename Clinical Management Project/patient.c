
#include <stdio.h>
#include "patient.h"
#include "admin.h"

extern Patient patientRecord[SIZE];
extern Reservation reserveRecord[RESERVE_SIZE];

u8 PATIENT_u8PatientCheck(void)
{
	u16 L_u16ID;
	u8 L_u8Counter;
	printf("Enter ID: ");
	scanf("%d", &L_u16ID);
	
	for (L_u8Counter = 0; L_u8Counter < SIZE; L_u8Counter ++)
	{
		if (L_u16ID == patientRecord[L_u8Counter].ID)
		{
			return L_u8Counter;
		}
	}
	return ABSCENT;
}

u8 PATIENT_u8PatientView(u16 copy_u16ID)
{
	u8 L_u8Counter;
	for (L_u8Counter = 0; L_u8Counter < SIZE; L_u8Counter++)
	{
		if ( patientRecord[L_u8Counter].ID == copy_u16ID )
			break;
		
		printf("Patient #%d 's Data:\n", patientRecord[L_u8Counter].ID);
		printf("Name: %s.\n", patientRecord[L_u8Counter].Name);
		printf("Age: %d.\n", patientRecord[L_u8Counter].Age);
		printf("Gender: %s.\n", patientRecord[L_u8Counter].Gender);
		
		return copy_u16ID;
	}
	
}