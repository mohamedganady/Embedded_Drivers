/*******************************************************************************/
/*******************************************************************************/
/********************    Author: Mohamed Mostafa       *************************/
/********************    Layer: HAL                    *************************/
/********************    SWC: KEYPAD                   *************************/
/********************    Version:1.00                  *************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_

#define ROW_NO                                 4
#define COL_NO                                 4

u8 global_u8ArrOfKeyValues [ROW_NO][COL_NO]={{'1','2','3','+'},
										     {'4','5','6','-'},
										     {'7','8','9','*'},
											 {'C','0','=','/'}};
											 
#define KEYPAD_NO_BUTTON_PRESSED               255

#define KEYPAD_PORT                            DIO_PORTC

#define ROW0	                               PIN0
#define ROW1	                               PIN1
#define ROW2                                   PIN2
#define ROW3	                               PIN3

#define COL0	                               PIN4
#define COL1	                               PIN5
#define COL2                                   PIN6
#define COL3	                               PIN7

#define KEYPAD_ROWS                        {ROW0,ROW1,ROW2,ROW3}
#define KEYPAD_COLS                        {COL0,COL1,COL2,COL3}

#define KEYPAD_DEBOUNCING_DELAY_MS             30

#endif
