/**
******************************************************************************
* @file    UART0.H
* @author  Harshal
* @version 01.00
* @date    25-Aug-2021
* @brief   System Initialization file for   module.
*  	       + Initialization / configuration of all hardware modules is done
*  	     	 in this file.
******************************************************************************
* @attention
* @{
* <h2><center>&copy; Copyright 2017  </center></h2>
*			                All rights reserved.
* An unpublished work by  Limited . This material contains
* CONFIDENTIAL INFORMATION that is the property of   Limited .
* Any unauthorized use, duplication or disclosure is prohibited.
* @}
******************************************************************************
*/

/*
*******************************************************************************
*                               FILE HISTORY
*******************************************************************************
* Change    : 00
* Author    : Harshal
* Date      : 25-Aug-2021
* Brief     : created file
*
*******************************************************************************
*/

#ifndef UART0_H_
#define UART0_H_

/*
*******************************************************************************
*                                INCLUDE FILES
*******************************************************************************
*/

#include "std_data_types.h"
#include "HX710.H"

/*
*******************************************************************************
*                          PUBLIC MACROS & CONSTANTS & CONSTANTS
*******************************************************************************
*/

typedef struct
{
	uint8_t buffer[16];
	uint8_t *buffer_ptr;
	uint8_t ctr;
}uart_rx_t;

/*
*******************************************************************************
*                         PUBLIC VARIABLE DECLARATION
*******************************************************************************
*/
extern void UartRxPrcs (uint8_t rx_data);

/*
*******************************************************************************
*                         PUBLIC FUNCTION DECLARATION
*******************************************************************************
*/

extern void Initial_UART0( void );
extern void UART0_recieve( void );
extern void UART0_Transmit( uint8_t *buff_ptr , uint8_t len );
extern bool_t UART0_IsTxOver(void);

#endif /* UART0_H_ */
/*-------------------------------END OF FILE----------------------------------*/




