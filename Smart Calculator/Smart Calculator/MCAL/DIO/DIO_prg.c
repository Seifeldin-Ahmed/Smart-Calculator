/*
 * DIO_prg.c



 *
 *  Created on: Aug 24, 2022
 *      Author: Seif
 */



#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Utils.h"

#include "DIO_int.h"
#include "DIO_prv.h"
#include "DIO_cfg.h"

/* Name:  DIO_vidInit
 * Description:  initialize all MC Pins according to "DIO_cfg.h"
 * Arguments: void
 * Return: void
 * */

void DIO_vidInit()
{   /*
       #define DIO_u8_OUTPUT_LOW             0
       #define DIO_u8_OUTPUT_HIGH            1
       #define DIO_u8_INPUT_FLOATING         2
       #define DIO_u8_INPUT_PULLUP           3
     */
        #undef DIO_u8_OUTPUT_LOW
        #undef DIO_u8_OUTPUT_HIGH
        #undef DIO_u8_INPUT_FLOATING
        #undef DIO_u8_INPUT_PULLUP

       #define DIO_u8_OUTPUT_LOW             1
       #define DIO_u8_OUTPUT_HIGH            1
       #define DIO_u8_INPUT_FLOATING         0
       #define DIO_u8_INPUT_PULLUP           0

      /* Set DDR Values */
	DIO_u8_DDRA_REG = CONC(DIO_u8_PORTA_PIN7, DIO_u8_PORTA_PIN6, DIO_u8_PORTA_PIN5
								, DIO_u8_PORTA_PIN4 , DIO_u8_PORTA_PIN3, DIO_u8_PORTA_PIN2
								, DIO_u8_PORTA_PIN1, DIO_u8_PORTA_PIN0);   /* 0b00001111   */

		DIO_u8_DDRB_REG = CONC(DIO_u8_PORTB_PIN7, DIO_u8_PORTB_PIN6, DIO_u8_PORTB_PIN5
								, DIO_u8_PORTB_PIN4 , DIO_u8_PORTB_PIN3, DIO_u8_PORTB_PIN2
								, DIO_u8_PORTB_PIN1, DIO_u8_PORTB_PIN0);

		DIO_u8_DDRC_REG = CONC(DIO_u8_PORTC_PIN7, DIO_u8_PORTC_PIN6, DIO_u8_PORTC_PIN5
								, DIO_u8_PORTC_PIN4 , DIO_u8_PORTC_PIN3, DIO_u8_PORTC_PIN2
								, DIO_u8_PORTC_PIN1, DIO_u8_PORTC_PIN0);

		DIO_u8_DDRD_REG = CONC(DIO_u8_PORTD_PIN7, DIO_u8_PORTD_PIN6, DIO_u8_PORTD_PIN5
								, DIO_u8_PORTD_PIN4 , DIO_u8_PORTD_PIN3, DIO_u8_PORTD_PIN2
								, DIO_u8_PORTD_PIN1, DIO_u8_PORTD_PIN0);

	/*
	 *
       #define DIO_u8_OUTPUT_LOW             1
       #define DIO_u8_OUTPUT_HIGH            1
       #define DIO_u8_INPUT_FLOATING         0
       #define DIO_u8_INPUT_PULLUP           0
	 *
	 * */

     #undef DIO_u8_OUTPUT_LOW
     #undef DIO_u8_OUTPUT_HIGH
     #undef DIO_u8_INPUT_FLOATING
     #undef DIO_u8_INPUT_PULLUP

    #define DIO_u8_OUTPUT_LOW             0
    #define DIO_u8_OUTPUT_HIGH            1
    #define DIO_u8_INPUT_FLOATING         0
    #define DIO_u8_INPUT_PULLUP           1


	/* set Port values */
		DIO_u8_PORTA_REG = CONC(DIO_u8_PORTA_PIN7, DIO_u8_PORTA_PIN6, DIO_u8_PORTA_PIN5
									, DIO_u8_PORTA_PIN4 , DIO_u8_PORTA_PIN3, DIO_u8_PORTA_PIN2
									, DIO_u8_PORTA_PIN1, DIO_u8_PORTA_PIN0);   /* 0b11110001   */

			DIO_u8_PORTB_REG = CONC(DIO_u8_PORTB_PIN7, DIO_u8_PORTB_PIN6, DIO_u8_PORTB_PIN5
									, DIO_u8_PORTB_PIN4 , DIO_u8_PORTB_PIN3, DIO_u8_PORTB_PIN2
									, DIO_u8_PORTB_PIN1, DIO_u8_PORTB_PIN0);

			DIO_u8_PORTC_REG = CONC(DIO_u8_PORTC_PIN7, DIO_u8_PORTC_PIN6, DIO_u8_PORTC_PIN5
									, DIO_u8_PORTC_PIN4 , DIO_u8_PORTC_PIN3, DIO_u8_PORTC_PIN2
									, DIO_u8_PORTC_PIN1, DIO_u8_PORTC_PIN0);

			DIO_u8_PORTD_REG = CONC(DIO_u8_PORTD_PIN7, DIO_u8_PORTD_PIN6, DIO_u8_PORTD_PIN5
									, DIO_u8_PORTD_PIN4 , DIO_u8_PORTD_PIN3, DIO_u8_PORTD_PIN2
									, DIO_u8_PORTD_PIN1, DIO_u8_PORTD_PIN0);

	/*
	#define DIO_u8_OUTPUT_LOW             0
    #define DIO_u8_OUTPUT_HIGH            1
    #define DIO_u8_INPUT_FLOATING         0
    #define DIO_u8_INPUT_PULLUP           1
	 * */
   #undef DIO_u8_OUTPUT_LOW
   #undef DIO_u8_OUTPUT_HIGH
   #undef DIO_u8_INPUT_FLOATING
   #undef DIO_u8_INPUT_PULLUP

  #define DIO_u8_OUTPUT_LOW             0
  #define DIO_u8_OUTPUT_HIGH            1
  #define DIO_u8_INPUT_FLOATING         2
  #define DIO_u8_INPUT_PULLUP           3
}




/*  Name: DIO_enuSetPinValue
 *  Description: Set Desired Pin on Desired Port to Desired Value
 *  Arguments:   First Argument:   Copy_u8Port,        options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 *               Second Argument:  Copy_u8Pin,         options(from DIO_u8_PIN0 to DIO_u8_PIN7)
 *               Third Argument: Copy_u8Value,         options(DIO_u8_HIGH,DIO_u8_LOW)
 *
 *  Return: Error Status : DIO_OK , DIO_NOK
 * */
DIO_tenuErrorStatus DIO_enuSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
	//check error status //
	if(Copy_u8Port > DIO_u8_PORTD || Copy_u8Pin > DIO_u8_PIN7 || Copy_u8Value> DIO_u8_HIGH)
		Local_enuErrorStatus= DIO_NOK;
	else
	{
		switch (Copy_u8Port)
		{
            case DIO_u8_PORTA:
            		(Copy_u8Value == DIO_u8_HIGH)? (DIO_u8_PORTA_REG |= (1<<Copy_u8Pin)) : (DIO_u8_PORTA_REG &= ~(1<<Copy_u8Pin));
            		break;

            case DIO_u8_PORTB:
           				(Copy_u8Value == DIO_u8_HIGH)? (DIO_u8_PORTB_REG |= (1<<Copy_u8Pin)) : (DIO_u8_PORTB_REG &= ~(1<<Copy_u8Pin));
           				break;

            case DIO_u8_PORTC:
           				(Copy_u8Value == DIO_u8_HIGH)? (DIO_u8_PORTC_REG |= (1<<Copy_u8Pin)) : (DIO_u8_PORTC_REG &= ~(1<<Copy_u8Pin));
           				break;

            case DIO_u8_PORTD:
           				(Copy_u8Value == DIO_u8_HIGH)? (DIO_u8_PORTD_REG |= (1<<Copy_u8Pin)) : (DIO_u8_PORTD_REG &= ~(1<<Copy_u8Pin));
           				break;
		}
	}
	return Local_enuErrorStatus;

}


/*  Name: DIO_enuGetPinValue
 *  Description: Get Desired Pin Value from Desired Port
 *  Arguments:   First Argument:   Copy_u8Port,        options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 *               Second Argument:  Copy_u8Pin,         options(from DIO_u8_PIN0 to DIO_u8_PIN7)
 *               Third Argument: Add_pu8PinValue,      Variable address to store pin Value
 *
 *  Return: Error Status : DIO_OK , DIO_NOK
 * */
DIO_tenuErrorStatus DIO_enuGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Add_pu8PinValue)
{
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;

	// Error Checks  //
   if((Copy_u8Port>DIO_u8_PORTD) || (Copy_u8Pin > DIO_u8_PIN7) || (Add_pu8PinValue == NULL))
	   Local_enuErrorStatus = DIO_NOK;
   else
   {
	     switch (Copy_u8Port)
	   		  {
	               case DIO_u8_PORTA:
	            	   *Add_pu8PinValue= ((DIO_u8_PINA_REG >> Copy_u8Pin) & 1);
	               		break;

	               case DIO_u8_PORTB:
	            	   *Add_pu8PinValue= ((DIO_u8_PINB_REG>>Copy_u8Pin)& 1) ;
	            	   break;

	               case DIO_u8_PORTC:
	            	   *Add_pu8PinValue= ((DIO_u8_PINC_REG>>Copy_u8Pin)& 1) ;
	            	   break;

	               case DIO_u8_PORTD:
	            	   *Add_pu8PinValue= ((DIO_u8_PIND_REG>>Copy_u8Pin)& 1) ;
	            	   break;
	   	   	}
   }
   return Local_enuErrorStatus;
}



/*  Name: DIO_enuSetPortValue
 *  Description: Set Desired Value to Desired Port
 *  Arguments:   First Argument:   Copy_u8Port,        options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 *               Second Argument: Copy_u8PortValue,
 *
 *  Return: Error Status : DIO_OK , DIO_NOK
 * */
DIO_tenuErrorStatus DIO_enuSetPortValue (u8 Copy_u8Port, u8 Copy_u8PortValue)
{
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;

	// check error status //
	if((Copy_u8Port>3 )|| (Copy_u8PortValue > 255))
	{
		Local_enuErrorStatus= DIO_NOK;
	}
	else
	{
		 switch (Copy_u8Port)
	       {
	          case DIO_u8_PORTA:
	        	  DIO_u8_PORTA_REG = Copy_u8PortValue;
	         		break;

	          case DIO_u8_PORTB:
	        	  DIO_u8_PORTB_REG = Copy_u8PortValue;
	      	   break;

	          case DIO_u8_PORTC:
	        	  DIO_u8_PORTC_REG = Copy_u8PortValue;
	      	   break;

	          case DIO_u8_PORTD:
	        	  DIO_u8_PORTD_REG = Copy_u8PortValue;
	      	   break;
	 	  }
	}

   return Local_enuErrorStatus;
}


/*  Name: DIO_enuGetPortValue
 *  Description: Get Desired Port Value
 *  Arguments:   First Argument:   Copy_u8Port,        options(DIO_u8_PORTA,DIO_u8_PORTB,DIO_u8_PORTC,DIO_u8_PORTD)
 *               Second Argument: Add_pu8PortValue,       variable address to store PORT value
 *
 *
 *  Return: Error Status : DIO_OK , DIO_NOK
 * */
DIO_tenuErrorStatus DIO_enuGetPortValue (u8 Copy_u8Port, u8 *Add_pu8PortValue)
{
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;

		// check error status //
		if((Copy_u8Port>3 )|| (Add_pu8PortValue == NULL))
		{
			Local_enuErrorStatus= DIO_NOK;
		}
		else
		{
			 switch (Copy_u8Port)
		       {
		          case DIO_u8_PORTA:
		        	  *Add_pu8PortValue= DIO_u8_PORTA_REG ;
		        	  break;

		          case DIO_u8_PORTB:
		        	  *Add_pu8PortValue= DIO_u8_PORTB_REG ;
		        	  break;

		          case DIO_u8_PORTC:
	            	   *Add_pu8PortValue= DIO_u8_PORTC_REG ;
		      	   break;

		          case DIO_u8_PORTD:
		        	  *Add_pu8PortValue= DIO_u8_PORTD_REG ;
		        	  break;
		 	  }
		}

	   return Local_enuErrorStatus;
}

DIO_tenuErrorStatus DIO_enuTogglePort(u8 Copy_u8Port)
{
 	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;

 	// check error status //
 	if( Copy_u8Port>3 )
 	{
	 	Local_enuErrorStatus= DIO_NOK;
 	}
	 else
	 {
		 switch (Copy_u8Port)
		 {
	          case DIO_u8_PORTA:
	          DIO_u8_PORTA_REG ^= 0xFF;  //first way
	          break;

	          case DIO_u8_PORTB:
	          DIO_u8_PORTB_REG = ~DIO_u8_PORTA_REG; // second way
	          break;

	          case DIO_u8_PORTC:
	          DIO_u8_PORTC_REG ^= 0xFF;
	          break;

	          case DIO_u8_PORTD:
	          DIO_u8_PORTD_REG  ^= 0xFF;
	          break;
		 } 
	 }		 
	 
	 
	 	   return Local_enuErrorStatus;
}



DIO_tenuErrorStatus DIO_enuTogglePin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
	//check error status //
	if(Copy_u8Port > DIO_u8_PORTD || Copy_u8Pin > DIO_u8_PIN7 )
	 {
		 Local_enuErrorStatus= DIO_NOK;
	 }		 
	else
	{
		switch (Copy_u8Port)
		{
			case DIO_u8_PORTA:
			DIO_u8_PORTA_REG ^= (1<<Copy_u8Pin);  
			break;

			case DIO_u8_PORTB:
			DIO_u8_PORTB_REG ^= (1<<Copy_u8Pin);
			break;

			case DIO_u8_PORTC:
			DIO_u8_PORTC_REG ^= (1<<Copy_u8Pin);
			break;

			case DIO_u8_PORTD:
			DIO_u8_PORTD_REG  ^=(1<<Copy_u8Pin);
			break;
		}
	}
	return Local_enuErrorStatus;

}
