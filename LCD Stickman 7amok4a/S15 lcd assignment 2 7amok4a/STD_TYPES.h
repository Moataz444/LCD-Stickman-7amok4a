/*
 * STD_TYPES.h
 *
 * Created: 7/22/2023 1:41:17 PM
 *  Author: Ba3aBe3
 */ 

# ifndef _STD_TYPES_H_ // syntax style _NAME_H_
# define _STD_TYPES_H_

typedef unsigned char		uint8;
typedef unsigned short int  uint16;
typedef unsigned long int	uint32;

typedef enum	// test cases
{
	E_OK		, //0
	E_NOT_OK	, //1
	E_PENDING	, //2
	}Std_ReturnType; //new name

#endif