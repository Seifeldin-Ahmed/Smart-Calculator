/*
 * KEYPAD_prg.c
 *
 *  Created on: Aug 29, 2022
 *      Author: Dell
 */


#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "KEYPAD_int.h"
#include "KEYPAD_cfg.h"

void KEYPAD_vidInit()
{
  DIO_vidInit();
}


extern u8 KEYPAD_au8Buttons[KEYPAD_u8_ROWS_NUM][KEYPAD_u8_COLS_NUM];

extern u8 KEYPAD_au8RowsPins[KEYPAD_u8_ROWS_NUM];
extern u8 KEYPAD_au8RowsPORT[KEYPAD_u8_ROWS_NUM];

extern u8  KEYPAD_au8ColsPins[KEYPAD_u8_COLS_NUM];
extern  u8 KEYPAD_au8ColsPORT[KEYPAD_u8_COLS_NUM];


KEYPAD_tenuErrorStatus KEYPAD_enuGetPressedKey(u8 *Add_u8KeyValue)
{
	KEYPAD_tenuErrorStatus Local_enuErrorStatus = KEYPAD_OK;
	u8 Local_u8RowIterator=0;
	u8 Local_u8ColIterator=0;
    u8 Local_u8Test=0;

    if (Add_u8KeyValue == NULL)
    	Local_enuErrorStatus=KEYPAD_NOK;
    else
    {
    	*Add_u8KeyValue=KEYPAD_u8_NOTPRESSED;
        	for(Local_u8RowIterator=0 ; Local_u8RowIterator<KEYPAD_u8_ROWS_NUM ; Local_u8RowIterator++)
	         {
	         	DIO_enuSetPinValue(KEYPAD_au8RowsPORT[Local_u8RowIterator],KEYPAD_au8RowsPins[Local_u8RowIterator],DIO_u8_LOW);
	         	for(Local_u8ColIterator=0 ; Local_u8ColIterator<KEYPAD_u8_COLS_NUM ; Local_u8ColIterator++)
	         		{
                            DIO_enuGetPinValue(KEYPAD_au8ColsPORT[Local_u8ColIterator],KEYPAD_au8ColsPins[Local_u8ColIterator],&Local_u8Test);
                            if(Local_u8Test==0)
                            {
                         	   *Add_u8KeyValue=KEYPAD_au8Buttons[Local_u8RowIterator][Local_u8ColIterator];
                         	   break;
                            }
	         		}
	         	DIO_enuSetPinValue(KEYPAD_au8RowsPORT[Local_u8RowIterator],KEYPAD_au8RowsPins[Local_u8RowIterator],DIO_u8_HIGH);
	         	if(*Add_u8KeyValue!=KEYPAD_u8_NOTPRESSED)
	         		{
	         		  break;
	         		}
	         }

    }
	return Local_enuErrorStatus;
}
