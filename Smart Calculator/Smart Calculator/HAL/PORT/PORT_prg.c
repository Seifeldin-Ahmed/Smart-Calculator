/*
 * CFile1.c
 *
 * Created: 28/09/2022 9:12:11 PM
 *  Author: seif
 */ 


#include "../../LIB/STD_Types.h"
#include "PORT_int.h"

#include "../../MCAL/DIO/DIO_int.h"

void PORT_vidInit()
{
	DIO_vidInit();
}