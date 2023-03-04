/*
 * KEYPAD_cfg.c
 *
 *  Created on: Aug 29, 2022
 *      Author: Dell
 */



#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "KEYPAD_cfg.h"

const  u8 row =KEYPAD_u8_ROWS_NUM ;
const u8 col = KEYPAD_u8_COLS_NUM;
 const u8 KEYPAD_au8Buttons[KEYPAD_u8_ROWS_NUM][KEYPAD_u8_COLS_NUM] =
{
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'#','0','=','+'}
};


const u8 KEYPAD_au8RowsPins[KEYPAD_u8_ROWS_NUM]=
{
	 DIO_u8_PIN0,
	 DIO_u8_PIN1,
	 DIO_u8_PIN2,
	 DIO_u8_PIN3

};

const u8 KEYPAD_au8RowsPORT[KEYPAD_u8_ROWS_NUM]=
{
     DIO_u8_PORTC,
     DIO_u8_PORTC,
     DIO_u8_PORTC,
     DIO_u8_PORTC

};

const u8 KEYPAD_au8ColsPins[KEYPAD_u8_COLS_NUM]=
{
     DIO_u8_PIN4,
     DIO_u8_PIN5,
     DIO_u8_PIN6,
     DIO_u8_PIN7

};

const u8 KEYPAD_au8ColsPORT[KEYPAD_u8_COLS_NUM]=
{
     DIO_u8_PORTC,
     DIO_u8_PORTC,
     DIO_u8_PORTC,
     DIO_u8_PORTC

};


