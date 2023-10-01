#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "math.h"
#include <avr/interrupt.h>
#include "../M_DIO/MDIO_Interface.h"
#include "UART_Interface.h"

void UART_voidInit (void)
{
	u8 L_u8_UCSRCValue = 0b10000000;

	/*BAUD RATE = 9600*/
	u16 L_u166BaudRate = 51;

	UBRRL = (u8) L_u166BaudRate;
	UBRRH = (u8) (L_u166BaudRate >> 8);

#if		RX_COM == ENABLE
		SET_BIT(UCSRB, RXCIE);
#elif	RX_COM == DISABLE
		CLR_BIT(UCSRB, RXCIE);
#endif

#if		TX_COM == ENABLE
		SET_BIT(UCSRB, TXCIE);
#elif	TX_COM == DISABLE
		CLR_BIT(UCSRB, TXCIE);
#endif

#if		DATA_EMPTY == ENABLE
		SET_BIT(UCSRB, UDRIE);
#elif	DATA_EMPTY == DISABLE
		CLR_BIT(UCSRB, UDRIE);
#endif




#if 	DOUBLE_SPD == ENABLE
		SET_BIT(UCSRA, U2X);
#elif	 DOUBLE_SPD == DISABLE
		CLR_BIT(UCSRA, U2X);
#endif
////////////////////////////////////////////
#if 	MULTIPROCESSOR == ENABLE
		SET_BIT(UCSRA, MPCM);
#elif	MULTIPROCESSOR == DISABLE
		CLR_BIT(UCSRA, MPCM);

#endif
///////////////////////////////////////////
#if 	TX_EN == ENABLE
		SET_BIT(UCSRB,TXEN);
#elif	TX_EN == DISABLE
		CLR_BIT(UCSRB,TXEN);

#endif

#if 	RX_EN == ENABLE
		SET_BIT(UCSRB,RXEN);
#elif	RX_EN == DISABLE
		CLR_BIT(UCSRB,RXEN);

#endif

////////////////////////////////////////////
#if		DATA_BITS == FIVE
		L_u8_UCSRCValue = ( L_u8_UCSRCValue & 0xf9 ) | 0b00000000;
		CLR_BIT(UCSRB,UCSZ2);
#elif	DATA_BITS == SIX
		L_u8_UCSRCValue = ( L_u8_UCSRCValue & 0xf9 ) | 0b00000010;
		CLR_BIT(UCSRB,UCSZ2);
#elif	DATA_BITS == SEVEN
		L_u8_UCSRCValue = ( L_u8_UCSRCValue & 0xf9 ) | 0b00000100;
		CLR_BIT(UCSRB,UCSZ2);
#elif	DATA_BITS == EIGHT
		L_u8_UCSRCValue = ( L_u8_UCSRCValue & 0xf9 ) | 0b00000110;
		CLR_BIT(UCSRB,UCSZ2);
#elif	DATA_BITS == NINE
		L_u8_UCSRCValue = ( L_u8_UCSRCValue & 0xf9 ) | 0b00000110;
		SET_BIT(UCSRB,UCSZ2);
#endif

//////////////////////////////////////////
#if		MODE == SYNC
		SET_BIT(L_u8_UCSRCValue, UMSEL);
#elif	MODE == ASYNC
		CLR_BIT(L_u8_UCSRCValue, UMSEL);
#endif
//////////////////////////////////////////
#if 	PARITY_SEL == DISABLE
		CLR_BIT(L_u8_UCSRCValue, UPM0);
		CLR_BIT(L_u8_UCSRCValue, UPM1);
#elif	PARITY_SEL == ODD_PARITY
		SET_BIT(L_u8_UCSRCValue, UPM0);
		SET_BIT(L_u8_UCSRCValue, UPM1);
#elif	PARITY_SEL == EVEN_PARITY
		CLR_BIT(L_u8_UCSRCValue, UPM0);
		SET_BIT(L_u8_UCSRCValue, UPM1);
#endif
////////////////////////////////////////
#if		STOP_BITS == ONE
		CLR_BIT(L_u8_UCSRCValue,USBS);
#elif	STOP_BITS == TWO
		SET_BIT(L_u8_UCSRCValue,USBS);

#endif
//////////////////////////////////////

	/*UPDATA THE UCSRC VALUE*/
	UCSRC = L_u8_UCSRCValue;
}

void UART_voidSendData	(u8 copy_u8Data)
{
	/*WAIT*/
	while( GET_BIT(UCSRA, UDRE) == 0 );
	UDR = copy_u8Data;
}

u8 UART_voidRecieveData	(void)
{
	/*WAIT*/
	while( GET_BIT(UCSRA, RXC) == 0 );
	/*RECIEVE DATA*/
	return UDR;
}

