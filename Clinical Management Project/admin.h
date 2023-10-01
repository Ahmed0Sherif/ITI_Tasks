
#ifndef ADMIN_H
#define ADMIN_H

#include <stdio.h>

#define PASSWORD 1234

#define IS_VALID 	0
#define IS_INVALID	1
#define FULL_NUMBER	2
#define NOT_FOUND	3

#define OUT_OF_RANGE	4
#define BUSY			5
#define AVAILABLE	6

#define SIZE 10
#define RESERVE_SIZE 5



typedef unsigned char u8;
typedef unsigned int  u16;

typedef struct
{
	u16 ID;
	u8 Gender [5];
	u8 Name [20];
	u8 Age;
	u8 reservationTime;
} Patient;

typedef struct
{
	u8 timeSlot[15];
	u8 Checked;
} Reservation;


u8 ADMIN_u8AdminEnterPassword(void);

u8 ADMIN_u8AdminAddNewRec(void);

u8 ADMIN_u8AdminEditRec(void);

u8 ADMIN_u8AdminReserve(void);

u8 ADMIN_u8AdminCancel(void);

#endif