/**
 ******************************************************************************
 * @file    HX710.H
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

#ifndef HX710_H_
#define HX710_H_

/*
 *******************************************************************************
 *                                INCLUDE FILES
 *******************************************************************************
 */

#include "REG_MG82F6D32.H"
#include "std_data_types.h"
#include "iap.h"
#include "I2c.h"
#include "sys_tick.h"


/*
 *******************************************************************************
 *                          PUBLIC MACROS & CONSTANTS & CONSTANTS
 *******************************************************************************
 */

typedef struct
{
	int32_t raw_value;
	float32_t real_value;

	//Stored in memory
	float32_t cal_value;
	int32_t offset;
	uint32_t mem_sign;

}load_cell_db_t;

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

extern void LoadCellDbInit(void);
extern load_cell_db_t *GetLoadCellDb(void);
extern void LoadCellPrcs(void);
extern void LoadCellTare(uint8_t times);


#endif /* HX710_H_ */
/*-------------------------------END OF FILE----------------------------------*/
