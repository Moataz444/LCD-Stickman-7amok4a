/*
 * LCD_config.h
 *
 * Created: 7/29/2023 2:35:22 PM
 *  Author: Ba3aBe3
 */ 
#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_

#define LCD_DATA_PORT			DIO -> PORTA
#define LCD_DATA_DIRECTION		DIO -> DDRA

#define LCD_RS DIO_PORTB, DIO_PIN1
#define LCD_RW DIO_PORTB, DIO_PIN2
#define LCD_E  DIO_PORTB, DIO_PIN3


#endif