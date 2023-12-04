/*
 * _7amok4a_moves.c
 *
 * Created: 8/4/2023 10:22:54 PM
 *  Author: Ba3aBe3
 */ 
#include "STD_TYPES.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#include "LCD_interface.h"
#include "DIO_interface.h"

#include "_7amok4a_positions.h"	

uint8 u8x= 1;
uint8 u8y= 15;

void moveY(uint8 *u8y)
{
	if (*u8y == 0)
	{ *u8y = 15 ;}
	else{*u8y = *u8y-1 ;}
}

void return_to_init_pos()
{
	u8x=1;
	u8y=15;
}


void _7amok4a_run ()
{
	uint16 u16Delay = 300;
	
	LCD_vidSendCommand(0x01); // clear screen
	
// 	return_to_init_pos();
	LCD_udtSpecialChar(run_1,	0, u8x, u8y) ;
	moveY(&u8y);
	_delay_ms(u16Delay);
	
	LCD_vidSendCommand(0x01); // clear screen
// 	_delay_ms(10); /// delay another time to stabilize for saftey
	
	LCD_udtSpecialChar(run_2,	0, u8x, u8y) ;
	moveY(&u8y);
	_delay_ms(u16Delay);
	
	LCD_vidSendCommand(0x01); // clear screen
	_delay_ms(10); /// delay another time to stabilize for saftey
}

void _7amok4a_hi()
{
	uint16 u16Delay = 160;
	
	LCD_vidGoTo(0, 0);
	
	uint8 hi [] = "Hi Iam 7amok4a" ;
	
	
// 	return_to_init_pos();
	uint8 i ;
	uint8 j ;
	for (j= 0; j<8; j++)
	{
		LCD_vidPrint(hi) ;
		for (i= 0; i<2; i++)
		{
			LCD_udtSpecialChar(hi_1,	0, u8x, u8y) ;
			_delay_ms(u16Delay);
			LCD_udtSpecialChar(hi_1_rev,	0, u8x, u8y) ;
			_delay_ms(u16Delay);
		}
		_7amok4a_run();
	}
	
}

void _7amok4a_print_choices()
{
	_delay_ms(200);
	LCD_vidSendCommand(0x01); // clear screen

	LCD_vidGoTo(0, 0);
	
	uint8 choices [] = "1.Run    2.Dance" ;
	uint8 choices2 [] = "3.Die..." ;
	
	LCD_vidPrint(choices) ;
	LCD_vidGoTo(1, 0);
	LCD_vidPrint(choices2) ;
	
	return_to_init_pos();
	
	LCD_udtSpecialChar(hi_1_rev,	0, u8x, u8y) ;

}
void _7amok4a_dance ()
{
	uint16 u16Delay = 200;
	uint8 i ;

	LCD_vidSendCommand(0x01); // clear screen
	
	return_to_init_pos();
	for (i= 0; i<3; i++)
	{
		
		LCD_udtSpecialChar(dance_1,	0, u8x, u8y) ;
		_delay_ms(u16Delay);
		LCD_udtSpecialChar(dance_1_rev,	0, u8x, u8y) ;
		_delay_ms(u16Delay);
		
		LCD_udtSpecialChar(dance_2,	0, u8x, u8y) ;
		_delay_ms(u16Delay);
		LCD_udtSpecialChar(dance_2_rev,	0, u8x, u8y) ;
		_delay_ms(u16Delay);
		
		LCD_udtSpecialChar(dance_3,	0, u8x, u8y) ;
		_delay_ms(u16Delay);
		LCD_udtSpecialChar(dance_3_rev,	0, u8x, u8y) ;
		_delay_ms(u16Delay);
		
		LCD_udtSpecialChar(dance_4_HEAD,	0, u8x, u8y) ;
		_delay_ms(u16Delay);
		LCD_udtSpecialChar(dance_4_HEAD_rev,	0, u8x, u8y) ;
		_delay_ms(u16Delay);
	}
}

void _7amok4a_die()
{
	uint16 u16Delay = 200;
	uint8 i;

	LCD_vidSendCommand(0x01); // clear screen
	
	
	LCD_udtSpecialChar(gun,			0, 1, 0) ;
	return_to_init_pos();
	LCD_udtSpecialChar(hi_1_rev,	1, 1, 15) ;
	_delay_ms(u16Delay);
	_delay_ms(u16Delay);
	
	LCD_udtSpecialChar(gun_burst,	2, 1, 1) ;				// shooot
	DIO_udtSetPinValue(DIO_PORTA, DIO_PIN3, DIO_HIGH);		// make buzzer high
    _delay_ms(u16Delay);

	DIO_udtSetPinValue(DIO_PORTA, DIO_PIN3, DIO_LOW);		// make buzzer low
	
	LCD_udtSpecialChar(gun_bullet,	3, 1, 2) ;
	_delay_ms(u16Delay);
	
	LCD_udtSpecialChar(empty_cursor, 4, 1, 1) ; // empty burst
	for (i=3; i < 15; i++)
	{
		LCD_udtSpecialChar(empty_cursor, 4, 1, i-1) ; // empty bullet
		LCD_udtSpecialChar(gun_bullet,	3, 1, i) ;
		_delay_ms(u16Delay);
	}
	
	LCD_udtSpecialChar(empty_cursor, 4, 1, 14) ; // empty last bullet
	
	LCD_udtSpecialChar(die_1,		1, u8x, u8y) ;
	_delay_ms(u16Delay);
	LCD_udtSpecialChar(die_2,		1, u8x, u8y) ;
	_delay_ms(u16Delay);
	LCD_udtSpecialChar(die_3,		1, u8x, u8y) ;
	_delay_ms(u16Delay);

	
	LCD_udtSpecialChar(die_4,		1, u8x, u8y) ;
	
	DIO_udtSetPinValue(DIO_PORTA, DIO_PIN3, DIO_HIGH);		// make buzzer high
	_delay_ms(u16Delay);

	for (i=0; i < 5; i++)
	{
		LCD_udtSpecialChar(die_5_halo1,	1, u8x, u8y) ;
		_delay_ms(u16Delay);
		LCD_udtSpecialChar(die_5_halo2,	1, u8x, u8y) ;
		_delay_ms(u16Delay);
	}
	
    _delay_ms(u16Delay);
	DIO_udtSetPinValue(DIO_PORTA, DIO_PIN3, DIO_LOW);		// make buzzer low
	
}