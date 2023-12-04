/*
 * BIT_MATH_H.h
 *
 * Created: 7/22/2023 1:40:20 PM
 *  Author: Ba3aBe3
 */ 

# ifndef  _BIT_MATH_H_  // syntax style _NAME_H_
# define  _BIT_MATH_H_

#define SET_BIT(var, bit)		var |= (1<< bit)
#define TOG_BIT(var, bit)		var ^= (1<< bit)
#define CLR_BIT(var, bit)		var &= ~(1<< bit)
#define GET_BIT(var, bit)		((var >> bit) & 1)

#endif