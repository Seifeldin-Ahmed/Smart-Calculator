/*
 * DIO_int.h

 *
 *  Created on: Aug 24, 2022
 *      Author: Seif
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_



/*  error status  */
typedef enum {
	DIO_OK, //0
	DIO_NOK  //1
}DIO_tenuErrorStatus;



/*  Macros for Ports  */
#define DIO_u8_PORTA      0
#define DIO_u8_PORTB      1
#define DIO_u8_PORTC      2
#define DIO_u8_PORTD      3


/*  Macros for Pins  */
#define DIO_u8_PIN0      0
#define DIO_u8_PIN1      1
#define DIO_u8_PIN2      2
#define DIO_u8_PIN3      3
#define DIO_u8_PIN4      4
#define DIO_u8_PIN5      5
#define DIO_u8_PIN6      6
#define DIO_u8_PIN7      7
 

/*  Macros for Value */
#define DIO_u8_LOW         0
#define DIO_u8_HIGH        1





/*   Needed Functions  */


/* Name:  DIO_vidInit
 * Description:  initialize all MC Pins according to "DIO_cfg.h"
 * Arguments: void
 * Return: void
 * */
void DIO_vidInit(void);



/*  Name: DIO_enuSetPinValue
 *  Description: Set Desired Pin on Desired Port to Desired Value
 *  Arguments:   First Argument:   Copy_u8Port,        options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 *               Second Argument:  Copy_u8Pin,         options(from DIO_u8_PIN0 to DIO_u8_PIN7)
 *               Third Argument: Copy_u8Value,         options(DIO_u8_HIGH,DIO_u8_LOW)
 *
 *  Return: Error Status : DIO_OK , DIO_NOK
 * */
DIO_tenuErrorStatus DIO_enuSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);



/*  Name: DIO_enuGetPinValue
 *  Description: Get Desired Pin Value from Desired Port
 *  Arguments:   First Argument:   Copy_u8Port,        options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 *               Second Argument:  Copy_u8Pin,         options(from DIO_u8_PIN0 to DIO_u8_PIN7)
 *               Third Argument: Add_pu8PinValue,      Variable address to store pin Value
 *
 *  Return: Error Status : DIO_OK , DIO_NOK
 * */
DIO_tenuErrorStatus DIO_enuGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Add_pu8PinValue);




/*  Name: DIO_enuSetPortValue
 *  Description: Set Desired Value to Desired Port
 *  Arguments:   First Argument:   Copy_u8Port,        options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 *               Second Argument: Copy_u8PortValue,       options(from 0 to 255)
 *
 *  Return: Error Status : DIO_OK , DIO_NOK
 */
DIO_tenuErrorStatus DIO_enuSetPortValue (u8 Copy_u8Port, u8 Copy_u8PortValue);



/*  Name: DIO_enuGetPortValue
 *  Description: Get Desired Port Value
 *  Arguments:   First Argument:   Copy_u8Port,        options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 *               Second Argument: Add_pu8PortValue,       variable address to store PORT value
 *
 *
 *  Return: Error Status : DIO_OK , DIO_NOK
 * */
DIO_tenuErrorStatus DIO_enuGetPortValue (u8 Copy_u8Port, u8 *Add_pu8PortValue);




//******** NEW FUNCTIONS ********//

DIO_tenuErrorStatus DIO_enuTogglePort(u8 Copy_u8Port);


DIO_tenuErrorStatus DIO_enuTogglePin(u8 Copy_u8Port, u8 Copy_u8Pin);


#endif /* MCAL_DIO_DIO_INT_H_ */