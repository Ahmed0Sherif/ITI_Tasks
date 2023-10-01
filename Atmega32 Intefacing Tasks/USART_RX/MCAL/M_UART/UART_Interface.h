/*
 * UART_Interface.h
 *
 *  Created on: Aug 23, 2023
 *      Author: User
 */

#ifndef MCAL_M_UART_UART_INTERFACE_H_
#define MCAL_M_UART_UART_INTERFACE_H_

#define DISABLE	0
#define ENABLE	1

/**TX AND RX ENABLE
 * ENABLE
 * DISABLE
 */

#define TX_EN ENABLE
#define RX_EN ENABLE


/**DOUBLE SPEED
 * ENABLE
 * DISABLE
 */

#define DOUBLE_SPD DISABLE

/**MULTI-PROCESSOR
 * ENABLE
 * DISABLE
 */

#define MULTIPROCESSOR	DISABLE

/**INTERRUPTS
 * ENABLE
 * DISABLE
 */

#define RX_COM 		DISABLE
#define TX_COM 		DISABLE
#define DATA_EMPTY	DISABLE
/////////////////////

#define ODD_PARITY	2
#define EVEN_PARITY	3

/**PARITY_SEL
 * DISABLE
 * ODD_PARITY
 * EVEN_PARITY
 */

#define PARITY_SEL DISABLE
////////////////////////////

#define SYNC 	4
#define ASYNC 	5

/**MODE
 * SYNC
 * ASYNC
 */

#define MODE ASYNC
////////////////////////////

#define FIVE	6
#define SIX 	7
#define SEVEN	8
#define EIGHT	9
#define NINE	10

/**DATA_BITS
 * FIVE
 * SIX
 * SEVEN
 * EIGHT
 * NINE
 */

#define DATA_BITS EIGHT
///////////////////////////

#define ONE 11
#define TWO 12

/*STOP_BITS
 * ONE
 * TWO
 */

#define STOP_BITS TWO
////////////////////////////

/*FUNCTIONS*/
void UART_voidInit (void);

void UART_voidSendData	(u8 copy_u8Data);

u8 UART_voidRecieveData	(void);


#endif /* MCAL_M_UART_UART_INTERFACE_H_ */
