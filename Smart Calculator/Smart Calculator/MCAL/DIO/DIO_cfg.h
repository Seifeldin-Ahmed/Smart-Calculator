/*
 * DIO_cfg.h

 *
 *  Created on: Aug 24, 2022
 *      Author: Seif
 */

#ifndef MCAL_DIO_DIO_CFG_H_
#define MCAL_DIO_DIO_CFG_H_




#define DIO_u8_OUTPUT_LOW             0
#define DIO_u8_OUTPUT_HIGH            1
#define DIO_u8_INPUT_FLOATING         2
#define DIO_u8_INPUT_PULLUP           3

/* options:
 * 			1- DIO_u8_OUTPUT_LOW
 * 			2- DIO_u8_OUTPUT_HIGH
 * 			3- DIO_u8_INPUT_FLOATING
 * 			4- DIO_u8_INPUT_PULLUP
 */


/*   Pins for PORTA  */
#define DIO_u8_PORTA_PIN0       DIO_u8_OUTPUT_LOW
#define DIO_u8_PORTA_PIN1       DIO_u8_OUTPUT_LOW
#define DIO_u8_PORTA_PIN2       DIO_u8_OUTPUT_LOW
#define DIO_u8_PORTA_PIN3       DIO_u8_OUTPUT_LOW
#define DIO_u8_PORTA_PIN4       DIO_u8_OUTPUT_LOW
#define DIO_u8_PORTA_PIN5       DIO_u8_OUTPUT_LOW
#define DIO_u8_PORTA_PIN6       DIO_u8_OUTPUT_LOW
#define DIO_u8_PORTA_PIN7       DIO_u8_OUTPUT_LOW

/*   Pins for PORTB   */
#define DIO_u8_PORTB_PIN0       DIO_u8_OUTPUT_LOW
#define DIO_u8_PORTB_PIN1       DIO_u8_OUTPUT_LOW
#define DIO_u8_PORTB_PIN2       DIO_u8_OUTPUT_LOW
#define DIO_u8_PORTB_PIN3       DIO_u8_OUTPUT_LOW
#define DIO_u8_PORTB_PIN4       DIO_u8_OUTPUT_HIGH
#define DIO_u8_PORTB_PIN5       DIO_u8_OUTPUT_LOW
#define DIO_u8_PORTB_PIN6       DIO_u8_INPUT_FLOATING
#define DIO_u8_PORTB_PIN7       DIO_u8_OUTPUT_LOW


/*   Pins for PORTC  */
#define DIO_u8_PORTC_PIN0       DIO_u8_OUTPUT_HIGH
#define DIO_u8_PORTC_PIN1       DIO_u8_OUTPUT_HIGH
#define DIO_u8_PORTC_PIN2       DIO_u8_OUTPUT_HIGH
#define DIO_u8_PORTC_PIN3       DIO_u8_OUTPUT_HIGH
#define DIO_u8_PORTC_PIN4       DIO_u8_INPUT_PULLUP
#define DIO_u8_PORTC_PIN5       DIO_u8_INPUT_PULLUP
#define DIO_u8_PORTC_PIN6       DIO_u8_INPUT_PULLUP
#define DIO_u8_PORTC_PIN7       DIO_u8_INPUT_PULLUP


/*   Pins for PORTD   */
#define DIO_u8_PORTD_PIN0      DIO_u8_INPUT_PULLUP
#define DIO_u8_PORTD_PIN1      DIO_u8_INPUT_PULLUP
#define DIO_u8_PORTD_PIN2      DIO_u8_INPUT_PULLUP
#define DIO_u8_PORTD_PIN3      DIO_u8_INPUT_PULLUP
#define DIO_u8_PORTD_PIN4      DIO_u8_INPUT_FLOATING
#define DIO_u8_PORTD_PIN5      DIO_u8_INPUT_FLOATING
#define DIO_u8_PORTD_PIN6      DIO_u8_INPUT_FLOATING
#define DIO_u8_PORTD_PIN7      DIO_u8_OUTPUT_LOW



#endif /* MCAL_DIO_DIO_CFG_H_ */
