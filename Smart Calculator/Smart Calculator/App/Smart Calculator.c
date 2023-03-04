/*
 * Smart_Calculator.c
 *
 * Created: 04/03/2023 10:02:27 PM
 * Author: Seifeldin Ahmed Ismail
 */ 

#define F_CPU 8000000UL
#include "util\delay.h"
#include "../LIB/STD_Types.h"
#include "../HAL/PORT/PORT_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/Keypad/KEYPAD_int.h"
int main()
{


	u8 Local_au8Inputs[16]={'$','$','$','$','$','$','$','$','$','$','$','$','$','$','$','$'}; // to store inputs to it [ '$' means the array is empty ]
	u8 Local_u8Operation=0;
	u8 Local_u8GetPressedKey=0; // for keypad
	u16 Local_u16Operand=0;
	f32 Local_f32TotalResult=0;
	u32 Local_u32FloatingResult=0; // if 100/3 == 3.33 so floating result will display .33
	u8 Local_u8Iterator=0; // for iterating on LCD Columns
    PORT_vidInit();
	LCD_VidInit();

	while(1)
	{

  //********************************************* First Section for Taking the Inputs ******************************************************
		u8 Local_u8ExitFlag=0; // for exit flag
		while (Local_u8Iterator<16  &&   Local_u8ExitFlag !=1)
		{

			do {
				KEYPAD_enuGetPressedKey(&Local_u8GetPressedKey);  // getting input number 1;
            }while( Local_u8GetPressedKey == 100 );


			_delay_ms(250); // for debouncing
			if (Local_u8GetPressedKey != '#')
			{
				Local_au8Inputs[Local_u8Iterator]=Local_u8GetPressedKey; // store input to the array to make calculations on it
				LCD_enuSendCharacter(Local_au8Inputs[Local_u8Iterator]); // display the current input
			}

			if(Local_u8GetPressedKey == '=')
			{
				Local_u8ExitFlag= 1;
			}

			Local_u8Iterator++;

			if(Local_u8GetPressedKey == '#')
			{
				LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
				for (Local_u8Iterator=0 ; Local_u8Iterator < 16 ; Local_u8Iterator++)
				  {
					Local_au8Inputs[Local_u8Iterator]='$';  // clear inputs (back to initial state )
				  }
				Local_u8Iterator=0;
				Local_f32TotalResult=0;
			}

		}
	//************************************************************************************************************************************


		Local_u8Iterator=0;

   //***************************************** Second Section for Calculations ***********************************************************

		while(Local_u8Iterator<16   &&  Local_au8Inputs[Local_u8Iterator]!='$')
		{
			   if(Local_au8Inputs[Local_u8Iterator] >= '0' &&  Local_au8Inputs[Local_u8Iterator] <= '9')
			   {

			   	Local_u16Operand = Local_u16Operand * 10;
			   	Local_u16Operand = Local_u16Operand + (u16)(Local_au8Inputs[Local_u8Iterator]-48);
			   	 // if the user enter 123 >> at first operand will equal 1 then >> 10 >>> 10+2 = 12 and so on
			   }

			   if(Local_au8Inputs[Local_u8Iterator] == '+' || Local_au8Inputs[Local_u8Iterator] == '-' || Local_au8Inputs[Local_u8Iterator] == '*' || Local_au8Inputs[Local_u8Iterator] == '/' || Local_au8Inputs[Local_u8Iterator] == '='  )
			   {   	    if (Local_f32TotalResult == 0)
			   	    {
			   	    	Local_f32TotalResult = (f32)Local_u16Operand;
			   	    }
			   	    else
			   	    {

			   	    	     switch (Local_u8Operation)
			   	    	     {
			   	    	              case '+' :
			   	    	             	 Local_f32TotalResult +=(f32)Local_u16Operand;
			   	    	             	 break;
			   	    	              case '-' :
			   	    	             	 Local_f32TotalResult -=(f32)Local_u16Operand;
			   	    	             	 break;
			   	    	              case '*' :
			   	    	             	 Local_f32TotalResult *=(f32)Local_u16Operand;
			   	    	             	 break;
			   	    	              case '/' :
			   	    	                  Local_f32TotalResult /=(f32)Local_u16Operand;
			   	    	                  break;

			   	    	     }
			   	    }
				   	 Local_u8Operation = Local_au8Inputs[Local_u8Iterator];
				   	Local_u16Operand=0;

			   }

			   Local_u8Iterator ++;
		}

   //**************************************************************************************************************************************


  //****************************************** Third Section For Displaying The Result of Calcuations *************************************

		LCD_enuGoTo(1,0);
		if(Local_f32TotalResult<0)
		{                    //1 0000 0000 - 1111 1111
			LCD_enuSendCharacter('-');
			Local_f32TotalResult=0-(u32)Local_f32TotalResult;           //256 - (-3) = 256 +3 = 259 (over flow ) = 3
			LCD_enuSendNumber((u32)Local_f32TotalResult);
		}
		else
		{ Local_u32FloatingResult=(u32)Local_f32TotalResult;
		Local_u32FloatingResult=(Local_f32TotalResult-(f32)Local_u32FloatingResult)*100; // if total result =100.33 so  100.33-100= .33 * 100 =33
		LCD_enuSendNumber((u32)Local_f32TotalResult);
		}
		if(Local_u32FloatingResult>0)
		{
			LCD_enuSendCharacter('.');
			LCD_enuSendNumber(Local_u32FloatingResult);
		}
//_delay_ms(1000);
  //***************************************************************************************************************************************
	}
return 0;
}