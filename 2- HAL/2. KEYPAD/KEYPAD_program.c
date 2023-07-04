/*******************************************************************************/
/*******************************************************************************/
/********************    Author: Mohamed Mostafa       *************************/
/********************    Layer: HAL                    *************************/
/********************    SWC: KEYPAD                   *************************/
/********************    Version:1.00                  *************************/
/*******************************************************************************/
/*******************************************************************************/

#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_configuration.h"

#define F_CPU                           8000000UL


u8 static global_u8SArrOfRows [ROW_NO]=KEYPAD_ROWS;
u8 static global_u8SArrOfCols [ROW_NO]=KEYPAD_COLS;



u8 HKEYPAD_u8GetPressedKey(void)
{
	u8 local_u8KeyValue = KEYPAD_NO_BUTTON_PRESSED; /*return local if we cant pressed ny key*/
	u8 local_u8RowCounter, local_u8ColCounter, local_u8PinValue, local_u8Flag=FLAG_DOWN;

	for (local_u8RowCounter=0; local_u8RowCounter<ROW_NO; local_u8RowCounter++)
	{
		// Activate Row
		MDIO_voidSetPinValue(KEYPAD_PORT, global_u8SArrOfRows[local_u8RowCounter], DIO_LOW);
		for (local_u8ColCounter=0; local_u8ColCounter<COL_NO; local_u8ColCounter++)
		{
			// Read Col
			local_u8PinValue = MDIO_u8GetPinValue(KEYPAD_PORT, global_u8SArrOfCols[local_u8ColCounter]);
			if (local_u8PinValue == KEY_PRESSED)
			{
				// for Debouncing Effect
				_delay_ms(KEYPAD_DEBOUNCING_DELAY_MS);
				// Read Col Again
				local_u8PinValue = MDIO_u8GetPinValue(KEYPAD_PORT, global_u8SArrOfCols[local_u8ColCounter]);
				while(local_u8PinValue == KEY_PRESSED)  //polling on flag
				{
					// Read Col Again
					local_u8PinValue = MDIO_u8GetPinValue(KEYPAD_PORT, global_u8SArrOfCols[local_u8ColCounter]);
				}
				local_u8KeyValue = global_u8ArrOfKeyValues[local_u8RowCounter][local_u8ColCounter];
				local_u8Flag = FLAG_UP;
				break; // break Col Loop
			}
		}// End of Col Loop
		// Deactivate Row
		MDIO_voidSetPinValue(KEYPAD_PORT, global_u8SArrOfRows[local_u8RowCounter], DIO_HIGH);
		if (local_u8Flag == FLAG_UP)
		{
			break; // break Row Loop
		}
	}// End of Row Loop

	return local_u8KeyValue;
}
