/*
 * LCD_interface.h
 *
 * Created: 7/29/2023 2:29:45 PM
 *  Author: Ba3aBe3
 */ 

#ifndef _LCD_INERFACE_H_
#define _LCD_INERFACE_H_

void LCD_vidInit (void) ;

void LCD_vidSendCommand (uint8 u8Command) ;
void LCD_vidSendData (uint8 u8Data) ;

void LCD_vidPrint (uint8* pu8Word) ;
void LCD_vidGoTo(uint8 u8X, uint8 u8Y) ;

void LCD_udtSpecialChar (uint8* pu8CharArr, uint8 u8CGRAMLocation,
uint8 u8DDRAMRow, uint8 u8DDRAMColumn) ;

#endif