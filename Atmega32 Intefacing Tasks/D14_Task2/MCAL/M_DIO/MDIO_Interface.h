
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define DIO_PORTA 	0
#define DIO_PORTB	1
#define DIO_PORTC 	2
#define DIO_PORTD	3

#define DIO_PIN_0	0
#define DIO_PIN_1	1
#define DIO_PIN_2	2
#define DIO_PIN_3	3
#define DIO_PIN_4	4
#define DIO_PIN_5	5
#define DIO_PIN_6	6
#define DIO_PIN_7	7

#define DIO_IN		0
#define DIO_OUT		1

#define LOW			0
#define HIGH		1

void MDIO_voidDioSetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction);

void MDIO_voidDioSetPinValue (u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value);

u8 MDIO_u8DioGetPinValue (u8 copy_u8Port, u8 copy_u8Pin);

void MDIO_voidDioTogglePin (u8 copy_u8Port, u8 copy_u8Pin);

void MDIO_voidDioSetPortDirection (u8 copy_u8Port, u8 copy_u8Direction);

void MDIO_voidDioSetPortValue (u8 copy_u8Port, u8 copy_u8Value);

void MDIO_voidDioTogglePort (u8 copy_u8Port);



#endif
