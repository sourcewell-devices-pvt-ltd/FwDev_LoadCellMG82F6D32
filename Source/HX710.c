/**
 ******************************************************************************
 * @file    HX710.C
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


/*
 *******************************************************************************
 *                                INCLUDE FILES
 *******************************************************************************
 */

#include"HX710.H"

/*
 *******************************************************************************
 *                          PRIVATE MACROS & CONSTANTS
 *******************************************************************************
 */
#define NO_OF_SAMP 						(10U)          //20 OG VALUE

#ifdef C51_COMPILER
sbit ADDO = P1^6;
sbit ADSK = P1^7;
#endif
/*
 *******************************************************************************
 *                         PRIVATE VARIABLE DECLARATION
 *******************************************************************************
 */

static load_cell_db_t load_cell_db;

/*
 *******************************************************************************
 *                         PRIVATE FUNCTION DECLARATION
 *******************************************************************************
 */

static uint32_t read(void);
static float read_average(uint8_t times);

/**
 *******************************************************************************
 * @fn void LoadCellDbInit(void)
 *******************************************************************************
 * @brief    void LoadCellDbInit(void)
 * @param     None
 * @retval    None
 ********************************************************************************
 */

void LoadCellDbInit(void)
{
	Initial_IAP();

	IAP_Read(CAL_VALUE_ADDR , (uint8_t *)(&load_cell_db.cal_value) , MEM_DATA_SIZE);

	if(DEFAULT_MEM_SIGN != load_cell_db.mem_sign )
	{
		load_cell_db.mem_sign = DEFAULT_MEM_SIGN;
		load_cell_db.cal_value = 1;
		load_cell_db.offset = 0;

		IAP_Program(CAL_VALUE_ADDR , (uint8_t *)(&load_cell_db.cal_value) , MEM_DATA_SIZE);
		IAP_Read(CAL_VALUE_ADDR , (uint8_t *)(&load_cell_db.cal_value) , MEM_DATA_SIZE);
	}

}//End of LoadCellDbInit


/**
 *******************************************************************************
 * @fn  load_cell_db_t *GetLoadCellDb(void)
 *******************************************************************************
 * @brief     load_cell_db_t *GetLoadCellDb(void)
 * @param     None
 * @retval    None
 ********************************************************************************
 */

load_cell_db_t *GetLoadCellDb(void)
{
	return(&load_cell_db);
}//End of GetLoadCellDb


/**
 ******************************************************************************
 * @fn float read()
 ******************************************************************************
 * @brief float read()
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
void LoadCellPrcs(void)
{

	uint32_t sum = 0;
	uint8_t ctr = 0;
	static uint32_t load_cell_timer = 0;
	int32_t temp_raw_val = 0;

	if(TRUE == SysTick_IsTimeOutOccurred(&load_cell_timer, 5))
	{
		for (ctr =0; ctr < NO_OF_SAMP; ctr++)
		{
			sum += read();
		}
		load_cell_db.raw_value = sum / NO_OF_SAMP;
		
		temp_raw_val = load_cell_db.raw_value;
		temp_raw_val -=  load_cell_db.offset;
		load_cell_db.real_value = temp_raw_val/load_cell_db.cal_value;
	}

}//End of LoadCellPrcs

#ifdef C51_COMPILER
/**
 ******************************************************************************
 * @fn float read()
 ******************************************************************************
 * @brief float read()
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
uint32_t read(void)
{
	uint32_t Count;
	uint8_t i;

	ADDO=1;
	ADSK=0;
	Count=0;
	while(ADDO);

	for (i=0;i<24;i++)
	{
		ADSK=1;
		Count=Count<<1;
		ADSK=0;
		if(ADDO)
			Count++;
	}
	ADSK=1;
	Count=Count^0x800000;
	ADSK=0;

	return(Count);
}// End of read
#else
/**
 ******************************************************************************
 * @fn float read()
 ******************************************************************************
 * @brief float read()
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
uint32_t read(void)
{
	uint32_t Count;
	uint8_t i;

	//ADDO=1;
	P1 &= ~(1<<7);
	Count=0;
	while((P1 & (1 << 6)) == (1 << 6));

	for (i=0;i<24;i++)
	{
		P1 |= (1<<7);
		Count=Count<<1;
		P1 &= ~(1<<7);
		if((P1 & (1 << 6)) == (1 << 6))
			Count++;
	}
	P1 |= (1<<7);
	Count=Count^0x800000;

	P1 &= ~(1<<7);


	return(Count);
}// End of read
#endif

/**
 ******************************************************************************
 * @fn float read_average(uint8_t times)
 ******************************************************************************
 * @brief
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */

float read_average(uint8_t times)
{
	float sum = 0;
	uint8_t i, j;
	for (i = 0; i < times; i++)
	{
		sum += read();
		for(j =0; j< 100; j++)
		{}
	}
	return sum / times;
}// End of read_average


/**
 ******************************************************************************
 * @fn void LoadCellTare (uint8_t times)
 ******************************************************************************
 * @brief
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */

void LoadCellTare (uint8_t times)
{
	load_cell_db.offset = read_average(times);
	IAP_Program(OFFSET_ADDR , (uint8_t *)(&load_cell_db.offset) , 4);
}//End of LoadCellTare

/*-------------------------------END OF FILE----------------------------------*/
