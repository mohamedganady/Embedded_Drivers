/************************************************************************/
/************************************************************************/
/********************  Author: Mohamed Mostafa   *************************/
/********************  Layer: MCAL               *************************/
/********************  SWC: TIMER                *************************/
/********************  Version:1.00              *************************/
/************************************************************************/
/************************************************************************/

#ifndef  TIMER_REGISTER_H_
#define  TIMER_REGISTER_H_

#define TCCRO                       *((volatile u8*)0x53)              /* Timer0 control register */
#define TCCRO                       6                                  /* Waveform generation mode bit0 */
#define TCCRO                       3                                  /* Waveform generation mode bit1 */
#define TCCRO                       2                                  /* Prescaler bit2 */
#define TCCRO                       1                                  /* Prescaler bit1 */
#define TCCRO                       0                                  /* Prescaler bit0 */


#define OCR0                        *((volatile u8*)0x5C)              /* Output compare register0 */

#define TIMSK                       *((volatile u8*)0x59)              /* Timer mask */
#define TIMSK_OCIE0                 1                                  /* Output compare 0 interrupt enable */




#endif
