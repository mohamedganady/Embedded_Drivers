/**************************************************************************/
/**************************************************************************/
/********************  Author: Mohamed Mostafa   **************************/
/********************  Layer: MCAL               **************************/
/********************  SWC: UART                 **************************/
/********************  Version:1.00              **************************/
/**************************************************************************/
/**************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_register.h"


void UART_Init(void)
{
	u8 Local_u8UCSRCValue=0;  // to write values on UCSRC

	SET_BIT(Local_u8UCSRCValue, 7);

	/*Stop bit*/
	CLR_BIT(Local_u8UCSRCValue, UCSRC_USBS);

	/*NO Parity*/
	CLR_BIT(Local_u8UCSRCValue, UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRCValue, UCSRC_UPM0);

	/*8 Data Bits (Charcter Size)*/
	SET_BIT(Local_u8UCSRCValue, UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRCValue, UCSRC_UCSZ0);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

	/*Asynchronous*/
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);

	/*Enable RX and TX*/
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);

	UCSRC =Local_u8UCSRCValue;

	/*Set Baud rate 9600*/
	CLR_BIT(UCSRA,UCSRA_U2X);
	UBRRL = 51;
}


u8 UART_u8Recieve(void)
{
	while(GET_BIT(UCSRA, UCSRA_RXC)==0);     //Polling
	return UDR;
}

void UART_voidSend(u8 Copy_u8data)
{
	while(GET_BIT(UCSRA, UCSRA_UDRE)==0);    //Polling , wait until transmit buffer is emit
	UDR = Copy_u8data;

}

