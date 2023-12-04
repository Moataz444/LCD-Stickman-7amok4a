/*
 * _7_SEGMENT.H
 *
 * Created: 7/28/2023 4:13:08 PM
 *  Author: Ba3aBe3
 */ 


#ifndef _7_SEGMENT_H_
#define _7_SEGMENT_H_


#define D_LOW DIO_udtSetPinValue(DIO_PORTA, DIO_PIN4, DIO_LOW)		 // 7-SEGMENT  A HIGH
#define D_HIGH DIO_udtSetPinValue(DIO_PORTA, DIO_PIN4, DIO_HIGH)		 // 7-SEGMENT  A LOW

#define C_LOW DIO_udtSetPinValue(DIO_PORTA, DIO_PIN5, DIO_LOW)		 // 7-SEGMENT  B HIGH
#define C_HIGH DIO_udtSetPinValue(DIO_PORTA, DIO_PIN5, DIO_HIGH)		 // 7-SEGMENT  B LOW

#define B_LOW DIO_udtSetPinValue(DIO_PORTA, DIO_PIN6, DIO_LOW)		 // 7-SEGMENT  C HIGH
#define B_HIGH DIO_udtSetPinValue(DIO_PORTA, DIO_PIN6, DIO_HIGH)		 // 7-SEGMENT  C LOW

#define A_LOW DIO_udtSetPinValue(DIO_PORTA, DIO_PIN7, DIO_LOW)		 // 7-SEGMENT  D HIGH
#define A_HIGH DIO_udtSetPinValue(DIO_PORTA, DIO_PIN7, DIO_HIGH)		 // 7-SEGMENT  D LOW

Std_ReturnType HAL_udtInit7Segment(void);

Std_ReturnType HAL_udtSet7Segment(uint8 u8_7_SegmentNumber);



#endif
