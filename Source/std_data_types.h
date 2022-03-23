/**
******************************************************************************
* @file    std_data_types.h
* @author  Nasreen Shaikh
* @version 01.00
* @date    30-MAR-2018
* @brief   Contains basic integer data types redefined to enable porting of
*          code on different compiler platforms
******************************************************************************
* @attention
* @{
* <h2><center>&copy; Copyright 2017 Marjan Solar </center></h2>
*			                All rights reserved.
* An unpublished work by Petrotec  Limited . This material contains
* CONFIDENTIAL INFORMATION that is the property of Petrotec  Limited .
* Any unauthorized use, duplication or disclosure is prohibited.
* @}
******************************************************************************
*/

/*
*******************************************************************************
*                               FILE HISTORY
*******************************************************************************
* Change    : 01
* Author    : Nasreen Shaikh
* Date      : 30-MAR-2018
* Brief     : created file
*
*******************************************************************************
*/
#ifndef STD_DATA_TYPES_H_
#define STD_DATA_TYPES_H_

/*
*******************************************************************************
*                                INCLUDE FILES                                   
*******************************************************************************
*/
//None

/*
*******************************************************************************
*                          PUBLIC MACROS & CONSTANTS
*******************************************************************************
*/

#ifdef	FALSE
#undef	FALSE
#endif
#define FALSE	(0)

#ifdef	TRUE
#undef	TRUE
#endif
#define	TRUE	(1)

#ifdef	NULL
#undef	NULL
#endif
#define NULL	(0)

#ifdef int8_t
#undef int8_t
#endif
typedef signed char 			int8_t;


#ifdef int16_t
#undef int16_t
#endif
typedef signed short int    	int16_t;


#ifdef int32_t
#undef int32_t
#endif
typedef signed long int     	int32_t;

#ifdef uint8_t
#undef uint8_t
#endif
typedef unsigned char       	uint8_t;


#ifdef uint16_t
#undef uint16_t
#endif
typedef unsigned short int  	uint16_t;


#ifdef uint32_t
#undef uint32_t
#endif
typedef unsigned long int   	uint32_t;

#ifdef bool_t
#undef bool_t
#endif
typedef unsigned char       	bool_t;


typedef float             		float32_t;

#ifdef C51_COMPILER
#define __interrupt(x)			interrupt x
#endif

/*
*******************************************************************************
*                         PUBLIC VARIABLE DECLARATION
*******************************************************************************
*/

//None

/*
*******************************************************************************
*                         PUBLIC FUNCTION DECLARATION
*******************************************************************************
*/
#endif /* STD_DATA_TYPES_H_ */
/*-------------------------------END OF FILE----------------------------------*/
