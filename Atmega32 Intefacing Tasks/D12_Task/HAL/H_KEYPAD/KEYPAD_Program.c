#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>
#include "../../MCAL/M_DIO/MDIO_Interface.h"
#include "KEYPAD_Interface.h"

u8 KPD_u8Arr [4][4] = KPD_KEYS;
u8 KPD_u8RowArr [4] = {KPD_R1_PIN, KPD_R2_PIN, KPD_R3_PIN, KPD_R4_PIN};
u8 KPD_u8ColArr [4] = {KPD_C1_PIN, KPD_C2_PIN, KPD_C3_PIN, KPD_C4_PIN};

void HKPD_voidKPDInt(void)
{
	MDIO_voidDioSetPortDirection(KPD_PORT, 0x0f);
	MDIO_voidDioSetPortValue(KPD_PORT, 0xff);
}



u8 HKPD_u8KPDGetKeyValue(void)
{
	u8 L_u8RowCount, L_u8ColCount, L_u8GetPin, L_u8ReturnedKey;
	u8 L_u8Flag = 0;
	/*LOOP FOR ROWS*/
	for (L_u8RowCount = 0; L_u8RowCount < 4; L_u8RowCount ++)
	{
		/*Activate COLS*/
		MDIO_voidDioSetPinValue(KPD_PORT, KPD_u8RowArr[L_u8RowCount], 0);

		/*LOOP FOR ROWS*/
		for (L_u8ColCount = 0; L_u8ColCount < 4; L_u8ColCount ++)
		{
			L_u8GetPin = MDIO_u8DioGetPinValue(KPD_PORT, KPD_u8ColArr[L_u8ColCount]);
			if (L_u8GetPin == 0)
			{
				/*DEBOUNC*/
				_delay_ms(20);
				L_u8GetPin = MDIO_u8DioGetPinValue(KPD_PORT, KPD_u8ColArr[L_u8ColCount]);
				while(L_u8GetPin == 0)
				{
					L_u8GetPin = MDIO_u8DioGetPinValue(KPD_PORT, KPD_u8ColArr[L_u8ColCount]);
				}
				L_u8ReturnedKey = KPD_u8Arr[L_u8RowCount][L_u8ColCount];
				L_u8Flag = 1;
				break;
			}
		}
		/*DEACTIVATING COL*/
		MDIO_voidDioSetPinValue(KPD_PORT, KPD_u8RowArr[L_u8RowCount], 1);
		if (L_u8Flag == 1)
		{
			break;
		}

	}
	if (L_u8Flag == 1)
		return L_u8ReturnedKey;
	else
		return 0xff;
}
