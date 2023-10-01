#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

/*MACROS FOR PORT*/
#define KPD_PORT 1

/*MACROS FOR ROWS*/
#define KPD_R1_PIN    0
#define KPD_R2_PIN    1
#define KPD_R3_PIN    2
#define KPD_R4_PIN    3

/*MACROS FOR COLUMNS*/
#define KPD_C1_PIN    4
#define KPD_C2_PIN    5
#define KPD_C3_PIN    6
#define KPD_C4_PIN    7

#define KPD_u8_KEY_NOT_PRESSED		0xff

/*MACROS FOR KPD*/
#define KPD_KEYS 		{ {'7', '8', '9', '/'},\
						  {'4', '5', '6', '*'},\
						  {'1', '2', '3', '-'}, \
						  {'C', '0', '=', '+'} }

void HKPD_voidKPDInt(void);
u8 HKPD_u8KPDGetKeyValue(void);



#endif
