
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

void MDIO_voidDioSetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction);

void MDIO_voidDioSetPinValue (u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value);

u8 MDIO_u8DioGetPinValue (u8 copy_u8Port, u8 copy_u8Pin);

void MDIO_voidDioTogglePin (u8 copy_u8Port, u8 copy_u8Pin);

void MDIO_voidDioSetPortDirection (u8 copy_u8Port, u8 copy_u8Direction);

void MDIO_voidDioSetPortValue (u8 copy_u8Port, u8 copy_u8Value);


#endif
