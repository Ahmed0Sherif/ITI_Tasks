
#include "admin.h"
#include "patient.h"

Patient patientRecord[SIZE];
Reservation reserveRecord [RESERVE_SIZE] = 	{ 	{"1- 2:00-2:30", 0},
												{"2- 2:30-3:00", 0},
												{"3- 3:00-3:30", 0},
												{"4- 4:00-4:30", 0},
												{"5- 4:30-5:00", 0}
											};

u8 L_u8Check;
int main (void)
{	
	u8 L_u8Choice, L_u8Count;	
	
	/*At the beginning of the program
	No one had a reservation, so 
	the reservation variable = 0*/
	for (L_u8Count = 0; L_u8Count < SIZE; L_u8Count ++)
	{
		patientRecord[L_u8Count].reservationTime = 0;
	}
	
	printf("Welcome to The Clinic Management Project.\n");	
	while (1)
	{
		printf("How would you like to login?\n");
		printf("1- Admin\n");
		printf("2- User\n");
		fflush(stdin);
		scanf("%d",&L_u8Choice);
		
		if ( L_u8Choice == 1) //Logged in as Admin
		{
			while (1)
			{	
				L_u8Check = ADMIN_u8AdminEnterPassword();
				if (L_u8Check == IS_VALID)
				{
					while (1)
					{
						printf("Choose your next option:\n");
						printf("1- Add New Patient Record.\n");
						printf("2- Edit Patient Record.\n");
						printf("3- Reserve a Slot With a Doctor.\n");
						printf("4- Cancel Reservation.\n");
						printf("5- Back to Main Menu.\n");
						fflush(stdin);
						scanf("%d",&L_u8Choice);
						switch (L_u8Choice)
						{	
							case 1:
								L_u8Check = ADMIN_u8AdminAddNewRec();
								printf("\n\n");
								break;
								
								case 2:
								L_u8Check = ADMIN_u8AdminEditRec();
								printf("\n\n");
								break;
								
								case 3:
								L_u8Check = ADMIN_u8AdminReserve();
								printf("\n\n");
								break;
								
								case 4:
								L_u8Check = ADMIN_u8AdminCancel();
								printf("\n\n");
								break;
								case 5:
								L_u8Check = 255;
								break;
						}
						if (L_u8Check == 255)
						{
							break;
						}
					}
					break;
				}
				else
				{
					L_u8Check = 254;
					break;
				}	
			}
		if (L_u8Check == 254)
				break;
		}
		else if ( L_u8Choice == 2 ) //Logged in as Patient
		{
			L_u8Check = PATIENT_u8PatientCheck();
			if (L_u8Check != ABSCENT)
			{
				while(1)
				{
					printf("\n\nWelcome. What Would you like to do ?\n");
					printf("1- Check Info.\n");
					printf("2- Check Reservations.\n");
					printf("3- Log out.\n");
					scanf("%d",&L_u8Choice);
					if (L_u8Choice == 1)
					{	
						printf("Patient #%d 's Data:\n", patientRecord[L_u8Check].ID);
						printf("Name: %s.\n", patientRecord[L_u8Check].Name);
						printf("Age: %d.\n", patientRecord[L_u8Check].Age);
						printf("Gender: %s.\n", patientRecord[L_u8Check].Gender);
						printf("Reservation: %d\n", patientRecord[L_u8Check].reservationTime);

					}
					else if (L_u8Choice == 2)
					{
						printf("Patient #%d 's Reservation:\n", patientRecord[L_u8Check].ID);
						if ( patientRecord[L_u8Check].reservationTime == 0 )
						{
						printf("Patient #%d does not have any reservations.\n", patientRecord[L_u8Check].ID);
						}
						else
						{
							printf("Patient #%d has a reservation at %s.\n", patientRecord[L_u8Check].ID, reserveRecord[ patientRecord[L_u8Check].reservationTime - 1].timeSlot );
						}
					}
						
					else if (L_u8Choice == 3)
					{
						L_u8Choice = 255;
					}
					if (L_u8Choice == 255)
						break;
				}
			}
			else if (L_u8Check == ABSCENT)
			{
				printf("ID NOT FOUND.\n");
			}
		}
	}
}
