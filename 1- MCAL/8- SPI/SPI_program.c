/*************************************************************************/
/*************************************************************************/
/********************  Author: Mohamed Mostafa   *************************/
/********************  Layer: MCAL               *************************/
/********************  SWC: SPI                  *************************/
/********************  Version:1.00              *************************/
/*************************************************************************/
/*************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_register.h"
#include "SPI_interface.h"


void SPI_voidInitMaster(void)
{
	/*Master initialization*/
	SET_BIT(SPCR,SPCR_MSTR);

	/*clock prescaler: divide by 16*/
	SET_BIT(SPCR , SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidInitSlave(void)
{
	/*Slave initialization*/
	CLR_BIT(SPCR,SPCR_MSTR);

	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);

}

u8 SPI_u8Transceive(u8 COPY_u8Data)
{
	/*Send the data*/
	SPDR = COPY_u8Data ;

	/*wait (busy waiting) until transfer complete*/
	while(GET_BIT(SPSR , SPSR_SPIF)==0);

	/*GET the exchanged data*/
	return SPDR;
}
