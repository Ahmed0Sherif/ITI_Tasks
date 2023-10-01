/*
Bit Manipulation Library
*/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR, BIT_NO)		VAR = VAR | (1<<BIT_NO)
#define CLR_BIT(VAR, BIT_NO)		VAR = VAR & ~(1<<BIT_NO)
#define GET_BIT(VAR, BIT_NO)		((VAR >> BIT_NO) & 1)
#define TOG_BIT(VAR, BIT_NO)		VAR = VAR ^(1<<BIT_NO)
//VAR = ((VAR >> BIT_NO) & 1)
#endif
