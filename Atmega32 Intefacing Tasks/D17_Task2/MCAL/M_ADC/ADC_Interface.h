/*
 * ADC_Interface.h
 *
 *  Created on: Aug 20, 2023
 *      Author: User
 */

#ifndef MCAL_M_ADC_ADC_INTERFACE_H_
#define MCAL_M_ADC_ADC_INTERFACE_H_

/****USED MACRO-LIKE FUNCTIONS*********/
#define SINGLE_CHANNEL(X) 	ADMUX=(ADMUX & 0xf8) + X
#define PRESCALAR_SELECT(X)		ADCSRA=(ADCSRA & 0xf8) + X
/*****************/


/*******SINGLE_CHANNELS***********/
#define ADC_0	0
#define ADC_1	1
#define ADC_2	2
#define ADC_3	3
#define ADC_4	4
#define ADC_5	5
#define ADC_6	6
#define ADC_7	7


/*
 * CHOOSE SINGLE CHANNEL
 * ADC_0
 * ADC_1
 * ADC_2
 * ADC_3
 * ADC_4
 * ADC_5
 * ADC_6
 * ADC_7
 */

#define ADC_SINGLE	ADC_0
/***********************/
/***********************/


/******REFERENCE SELECT*******/
#define INTERNAL	0
#define AVCC		1
#define AREF		2

/*
 * CHOOSE SOURCE:
 * INTERNAL
 * AVCC
 * AREF
 */
#define SOURCE AVCC
/*******************************/
/*******************************/

/**********ADJUSTMENT***************/
#define LEFT 	1
#define RIGHT	0
/*
 * CHOOSE ADJUSTMENT:
 * LEFT
 * RIGHT
 */
#define ADJUST LEFT
/***************************/
/***************************/

/************PRESCALAR SELECT***********/
#define ADC_TWO				0
#define ADC_FOUR			1
#define ADC_EIGHT			2
#define ADC_SIXTEEN			3
#define ADC_THRITYTWO		4
#define ADC_SIXTYFOUR		6
#define ADC_ONETWENTYEIGHT	7
/*
 * CHOOSE PRESCALAR:
 * ADC_TWO
 * ADC_FOUR
 * ADC_EIGHT
 * ADC_SIXTEEN
 * ADC_THRITYTWO
 * ADC_SIXTYFOUR
 * ADC_ONETWENTYEIGHT
 */
#define PRESCALAR ADC_EIGHT
/************************/
/***********************/

/*************INTERRUPT ENABLE**************/
#define ENABLE 	0
#define DISABLE 1
/*
 * SELECT INTERRUPT
 * ENABLE
 * DISABLE
 */
#define ADC_INT ENABLE
/***********************/
/***********************/

/**********FUNCTIONS*************/
void MADC_voidADCSingleInit();
void MADC_voidADCStart();
void MADC_voidADCDisable();
void MADC_voidADCInt();
void MADC_voidADCIsDone();
u16 MADC_u16ADCReturnValue (void);
void MADC_voidADCSetCallBack ( void (*copy_ADCEndConv) (void));

#endif /* MCAL_M_ADC_ADC_INTERFACE_H_ */
