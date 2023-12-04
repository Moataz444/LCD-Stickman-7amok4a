/*
 * LCD_program.c
 *
 * Created: 7/29/2023 2:30:32 PM
 *  Author: Ba3aBe3
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH_H.h"

#define F_CPU 16000000UL
#include "util/delay.h"

#include "DIO_interface.h"
#include "DIO_private.h"

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

void LCD_vidSendCommand (uint8 u8Command)
{
	/* !Comment: Clearing Rs to send command */
	DIO_udtSetPinValue( LCD_RS, DIO_LOW);
	
	/* !Comment: Clearing Rw to write data */
	DIO_udtSetPinValue( LCD_RW, DIO_LOW);
	
	/* !Comment: Writing the data on the data pins */
	LCD_DATA_PORT = u8Command & 0xF0 ;
	
	/* !Comment: Generate pulse on En pin */
	DIO_udtSetPinValue(LCD_E, DIO_HIGH) ;
	_delay_us(10); /// us = mirco seconds
	DIO_udtSetPinValue(LCD_E, DIO_LOW) ;
	
	_delay_us(200); /// delay another time to stabilize for saftey
	
	/* !Comment: Writing the data on the data pins */
	LCD_DATA_PORT = u8Command << 4;
	
	/* !Comment: Generate pulse on En pin */
	DIO_udtSetPinValue(LCD_E, DIO_HIGH);
	_delay_us(10);
	DIO_udtSetPinValue(LCD_E, DIO_LOW);
	
	_delay_us(2000); /// delay another time to stabilize for saftey
}

void LCD_vidSendData (uint8 u8Data) 
{
	/* !Comment: Clearing Rs to send command */
	DIO_udtSetPinValue( LCD_RS, DIO_HIGH);
	
	/* !Comment: Clearing Rw to write data */
	DIO_udtSetPinValue( LCD_RW, DIO_LOW);
	
	/* !Comment: Writing the data on the data pins */
	LCD_DATA_PORT = u8Data & 0xF0 ;
	
	/* !Comment: Generate pulse on En pin */
	DIO_udtSetPinValue(LCD_E, DIO_HIGH) ;
	_delay_us(10); /// us = mirco seconds
	DIO_udtSetPinValue(LCD_E, DIO_LOW) ;
	_delay_us(200); /// delay another time to stabilize for saftey
	
	/* !Comment: Writing the data on the data pins */
	LCD_DATA_PORT = u8Data << 4 ;
	
	/* !Comment: Generate pulse on En pin */
	DIO_udtSetPinValue(LCD_E, DIO_HIGH) ;
	_delay_us(10); /// us = mirco seconds
	DIO_udtSetPinValue(LCD_E, DIO_LOW) ;
	_delay_us(200); /// delay another time to stabilize for saftey
}

void LCD_vidInit(void)
{
	LCD_DATA_DIRECTION = 0xFF;
	
	DIO_udtSetPinDirection(LCD_RW, DIO_OUTPUT);
	DIO_udtSetPinDirection(LCD_RS, DIO_OUTPUT);
	DIO_udtSetPinDirection(LCD_E, DIO_OUTPUT);
	
	_delay_ms(40); // delay according to data sheet
	
	LCD_vidSendCommand(0x33) ; // = 0x3 and 0x03 instead of sending twice
	LCD_vidSendCommand(0x32) ; // = 0x3 and 0x02 instead of sending twice 
	
	LCD_vidSendCommand(0x28) ; // = 0x2 and 0x08 instead of sending twice 8= n=1 and f=0 x=don't care=0

	LCD_vidSendCommand(0x0c) ; // = 0x0 and 0x08 instead of sending twice   //0f if not working 1 d c b 0c=1d00
	LCD_vidSendCommand(0x01) ; // = 0x0 and 0x01 instead of sending twice
	
	_delay_ms(2); // delay according to data sheet

	
	LCD_vidSendCommand(0x06) ; // = 0x0 and 0x06 instead of sending twice  6= 10s s=1


}

void LCD_vidPrint(uint8* pu8Word)
{
	uint8 u8Counter = 0 ; 
	while (pu8Word[u8Counter] != '\0')
	{
		LCD_vidSendData(pu8Word[u8Counter]) ;
		u8Counter++ ;
	}
}

void LCD_vidGoTo(uint8 u8X, uint8 u8Y)
{
	if(u8X == 0)
	{
	LCD_vidSendCommand(u8Y + 128);
	}
	else if(u8X == 1)
	{
	LCD_vidSendCommand((u8Y+ 0x40) + 128);
	}
}

void LCD_udtSpecialChar (uint8* pu8CharArr, uint8 u8CGRAMLocation,
						 uint8 u8DDRAMRow, uint8 u8DDRAMColumn)
{
	uint8 u8Counter ;
	
	/* switch to CGRAM */
	LCD_vidSendCommand((u8CGRAMLocation*8) + 64) ; // 64 = 000 1 u8CGRAMLocation in data sheet
	
	/* Write on CGRAM */
	for (u8Counter = 0; u8Counter < 8; u8Counter++)
	{
		LCD_vidSendData(pu8CharArr[u8Counter]) ;
	}
	
	/* go back to DDRAM */
	LCD_vidGoTo(u8DDRAMRow, u8DDRAMColumn) ;
	
	/* print CGRAM data */
	LCD_vidSendData(u8CGRAMLocation) ;
}
