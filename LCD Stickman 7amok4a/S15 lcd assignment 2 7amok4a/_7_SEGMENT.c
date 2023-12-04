/*
 * _7_SEGMENT.c
 *
 * Created: 7/28/2023 4:19:02 PM
 *  Author: Ba3aBe3
 */ 

#include "STD_TYPES.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "_7-SEGMENT.h"

Std_ReturnType HAL_udtInit7Segment
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK ;

	DIO_udtSetPinDirection(DIO_PORTB, DIO_PIN2, DIO_OUTPUT); // 7-SEGMENT  EN1 OUTPUT
	DIO_udtSetPinValue(DIO_PORTB, DIO_PIN2, DIO_HIGH);		 // 7-SEGMENT  EN1 HIGH

	DIO_udtSetPinDirection(DIO_PORTA, DIO_PIN4, DIO_OUTPUT); // 7-SEGMENT  A OUTPUT

	DIO_udtSetPinDirection(DIO_PORTA, DIO_PIN5, DIO_OUTPUT); // 7-SEGMENT  B OUTPUT

	DIO_udtSetPinDirection(DIO_PORTA, DIO_PIN6, DIO_OUTPUT); // 7-SEGMENT  C OUTPUT

	DIO_udtSetPinDirection(DIO_PORTA, DIO_PIN7, DIO_OUTPUT); // 7-SEGMENT  D OUTPUT

	udtReturnValue = E_OK;

	return udtReturnValue;

}


Std_ReturnType HAL_udtSet7Segment
(
uint8 u8_7_SegmentNumber
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK ;

	switch(u8_7_SegmentNumber)
	{
		case 0: A_LOW; B_LOW; C_LOW; D_LOW;
				udtReturnValue = E_OK;
				break;
		case 1: A_LOW; B_LOW; C_LOW; D_HIGH;
				udtReturnValue = E_OK;
				break;
		case 2: A_LOW; B_LOW; C_HIGH; D_LOW;
				udtReturnValue = E_OK;
				break;					
		case 3: A_LOW; B_LOW; C_HIGH; D_HIGH;
				udtReturnValue = E_OK;
				break;
		case 4: A_LOW; B_HIGH; C_LOW; D_LOW;
				udtReturnValue = E_OK;
				break;
		case 5: A_LOW; B_HIGH; C_LOW; D_HIGH;
				udtReturnValue = E_OK;
				break;
		case 6: A_LOW; B_HIGH; C_HIGH; D_LOW;
				udtReturnValue = E_OK;
				break;
		case 7: A_LOW; B_HIGH; C_HIGH; D_HIGH;
				udtReturnValue = E_OK;
				break;
		case 8: A_HIGH; B_LOW; C_LOW; D_LOW;
				udtReturnValue = E_OK;
				break;
		case 9: A_HIGH; B_LOW; C_LOW; D_HIGH;
				udtReturnValue = E_OK;
				break;
		default: break;
	}
		return udtReturnValue;
}

