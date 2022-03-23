/**
******************************************************************************
* @file    IAP.H
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

#ifndef IAP_H_
#define IAP_H_

/*
*******************************************************************************
*                                INCLUDE FILES
*******************************************************************************
*/

#include "REG_MG82F6D32.H"
#include "std_data_types.h"


/*
*******************************************************************************
*                          PUBLIC MACROS & CONSTANTS & CONSTANTS
*******************************************************************************
*/
#define DEFAULT_MEM_SIGN				(0xAABBCCEE)

#define CAL_VALUE_ADDR					(0U)
#define OFFSET_ADDR						(CAL_VALUE_ADDR + 4)
#define MEM_SIGN_ADDR					(OFFSET_ADDR + 4)
#define MEM_DATA_SIZE					(MEM_SIGN_ADDR + 4)

/*
*******************************************************************************
*                         PUBLIC VARIABLE DECLARATION
*******************************************************************************
*/

//NONE

/*
*******************************************************************************
*                         PUBLIC FUNCTION DECLARATION
*******************************************************************************
*/
extern void Initial_IAP(void);
extern void IAP_Erase(uint8_t addr, uint8_t Page_Cnt);
extern void IAP_Program(uint8_t addr, uint8_t *data_ptr, uint8_t data_len);
extern void IAP_Read(uint8_t addr, uint8_t *data_ptr, uint8_t data_len);


#endif /* IAP_H_ */
/*-------------------------------END OF FILE----------------------------------*/

