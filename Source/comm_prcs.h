/**
******************************************************************************
* @file    comm_prcs.h
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

#ifndef COMM_PRCS_H_
#define COMM_PRCS_H_

/*
*******************************************************************************
*                                INCLUDE FILES
*******************************************************************************
*/

#include "HX710.H"
#include "UART0.H"
#include "string.h"
#include "std_data_types.h"

/*
*******************************************************************************
*                          PUBLIC MACROS & CONSTANTS & CONSTANTS
*******************************************************************************
*/


/*
*******************************************************************************
*                         PUBLIC VARIABLE DECLARATION
*******************************************************************************
*/

/*
*******************************************************************************
*                         PUBLIC FUNCTION DECLARATION
*******************************************************************************
*/
extern void Comm_Init(void);
extern void CommPrcs (void);
//extern void sendConfmenus(void);
extern void UartRxPrcs (uint8_t rx_data);

extern void I2cCommPrcs (void);
extern void I2cRxPrcs (uint8_t rx_data);

#endif /* COMM_PRCS_H_ */
/*-------------------------------END OF FILE----------------------------------*/
