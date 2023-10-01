
#ifndef PATIENT_H
#define PATIENT_H

#define EXIST 	0
#define ABSCENT	255

typedef unsigned char u8;
typedef unsigned int  u16;

u8 PATIENT_u8PatientCheck(void);

u8 PATIENT_u8PatientView(u16 copy_u16ID);

u8 PATIENT_u8PatientReserve(void);


#endif