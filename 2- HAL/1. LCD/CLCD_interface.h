/****************************************************************************/
/********************    Author: Mohamed Mostafa    *************************/
/********************    Layer:  HAL                *************************/
/********************    SWC: LCD                   *************************/
/********************    Version:1.00               *************************/
/****************************************************************************/

/*preprocessor file guard */
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_u8SendCommand(u8 Copy_u8command);                   // RS(Register select ) command -----0
void CLCD_u8SendData(u8 Copy_u8DATA);                        // DATA ----- 1
void CLCD_void(void);                                       // to prepare lcd 






#endif 