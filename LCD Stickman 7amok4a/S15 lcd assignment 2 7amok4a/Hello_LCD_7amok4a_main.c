/*
 * Hello_Dio.c
 *
 * Created: 7/22/2023 4:28:28 PM
 *  Author: Ba3aBe3
 */


#include "STD_TYPES.h"   /// include order matters to avoid errors
#include "BIT_MATH_H.h"

	#define F_CPU 16000000UL
	#include <util/delay.h>

	#include "LCD_interface.h"
	#include "DIO_interface.h"
	
	#include "_7amok4a_moves.h"
	
	
	int main(void)
	{
		
		LCD_vidInit();
		
		DIO_udtSetPinDirection(DIO_PORTA, DIO_PIN3, DIO_OUTPUT); // buzzer

		DIO_udtSetPinDirection(DIO_PORTB, DIO_PIN0, DIO_INPUT); // push button 1
		DIO_udtSetPinValue(DIO_PORTB, DIO_PIN0, DIO_LOW); // MAKE PUSH button high  // because avr are all pull up resistor (high by default)
		uint8 pushButtonValue1 =0 ; // var to store PUSH button input value (high by default)
		
		DIO_udtSetPinDirection(DIO_PORTD, DIO_PIN6, DIO_INPUT); // push button 2
		DIO_udtSetPinValue(DIO_PORTD, DIO_PIN6, DIO_LOW); // MAKE PUSH button high  // because avr are all pull up resistor (high by default)
		uint8 pushButtonValue2 =0 ; // var to store PUSH button input value (high by default)
		
		DIO_udtSetPinDirection(DIO_PORTD, DIO_PIN2, DIO_INPUT); // push button 3
		DIO_udtSetPinValue(DIO_PORTD, DIO_PIN2, DIO_LOW); // MAKE PUSH button high  // because avr are all pull up resistor (high by default)
		uint8 pushButtonValue3 =0 ; // var to store PUSH button input value (high by default)
		
		uint8 i ;
		
		_7amok4a_hi();
	
		while (1)
		{
			_7amok4a_print_choices() ;
			
			DIO_udtGetPinValue(DIO_PORTB, DIO_PIN0, &pushButtonValue1); // get pushButtonValue1
			DIO_udtGetPinValue(DIO_PORTD, DIO_PIN6, &pushButtonValue2); // get pushButtonValue2
     		DIO_udtGetPinValue(DIO_PORTD, DIO_PIN2, &pushButtonValue3); // get pushButtonValue3
			
			if(pushButtonValue1 == DIO_HIGH)						   // check if button is pushed
			{
				for (i= 0; i<8; i++)
				{_7amok4a_run(); }  
			}
			else if(pushButtonValue2 == DIO_HIGH)	
			{_7amok4a_dance(); }
			else if(pushButtonValue3 == DIO_HIGH)
			{_7amok4a_die(); }
			else{}


			
		}
		return 0;
}
