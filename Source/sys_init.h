/**
******************************************************************************
* @file    sys_init.h
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

#ifndef SYS_INIT_H_
#define SYS_INIT_H_
/*
*******************************************************************************
*                                INCLUDE FILES                                   
*******************************************************************************
*/
#include <iap.h>
#include <HX710.h>
#include "sys_tick.h"
#include <comm_prcs.h>
#include <I2c.h>

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
extern void Sys_Init(void);

#endif /* SYS_INIT_H_ */
/*-------------------------------END OF FILE----------------------------------*/
