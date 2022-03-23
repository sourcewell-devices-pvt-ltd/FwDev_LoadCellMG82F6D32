/**
 ******************************************************************************
 * @file    IAP.C
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

#include"iap.h"

/*
 *******************************************************************************
 *                          PRIVATE MACROS & CONSTANTS
 *******************************************************************************
 */

#define ISP_ENABLE          		0x80              // Set ISP Enable
#define ISP_DISABLE        			0x00              // Set ISP Disable
#define IAP_START_ADDR_MSB			(0x7C)

/*
 *******************************************************************************
 *                         PRIVATE VARIABLE DECLARATION
 *******************************************************************************
 */

//NONE

/*
 *******************************************************************************
 *                         PRIVATE FUNCTION DECLARATION
 *******************************************************************************
 */

/**
 ******************************************************************************
 * @fn void Initial_IAP(void)
 ******************************************************************************
 * @brief 
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
void Initial_IAP(void)
{ 
	CKCON0 = 80;                                   // IHRCO = 11.059Mhz
} //End of Initial_IAP

/**
 ******************************************************************************
 * @fn void IAP_Erase(uint8_t AddrH, uint8_t Page_Cnt)
 ******************************************************************************
 * @brief float read()
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
void IAP_Erase(uint8_t addr, uint8_t Page_Cnt)
{
	CKCON1 = CKCON1 & 0xC0 ;
	CKCON1 = CKCON1 | (11 -1 & 0x3F) ;
	while( Page_Cnt )
	{
		//T0Cnt = 0;                                   // clear Over Time
		IFADRH = addr;
		IFADRL = 0x00;
		IFMT = 0x03;							                   // erase
		ISPCR = ISP_ENABLE;
		SCMD = 0x46;
		SCMD = 0xB9;
		ISPCR = ISP_DISABLE;
		Page_Cnt--;
		addr += 2;                                  // For next PAGE, 512 bytes
	}
}// End of IAP_Erase

/**
 ******************************************************************************
 * @fn void IAP_Program(uint8_t addr, uint8_t *data_ptr)
 ******************************************************************************
 * @brief
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */

void IAP_Program(uint8_t addr, uint8_t *data_ptr, uint8_t data_len)
{
	uint8_t ctr = 0;
	uint8_t temp_buff[MEM_DATA_SIZE];

	//Copy to temporary buffer as page erase in next step
	IAP_Read(0 , temp_buff, MEM_DATA_SIZE);
	IAP_Erase(0x7C, 1);

	//Copy only the required data into temp_buff
	for(ctr = 0; ctr < data_len; ctr++)
	{
		temp_buff[addr + ctr] = *data_ptr++;
	}

	//Program the complete temp buff in memory
	for(ctr = 0; ctr < MEM_DATA_SIZE; ctr++)
	{
		CKCON1 = CKCON1 & 0xC0 ;
		CKCON1 = CKCON1 | (11 -1 & 0x3F) ;
		IFADRH = IAP_START_ADDR_MSB;
		IFADRL = ctr;
		IFD = temp_buff[ctr];
		IFMT = 0x02;
		ISPCR = ISPCR | ISP_ENABLE;
		SCMD = 0x46;
		SCMD = 0xB9;
		ISPCR = ISPCR & 0x7F ;
	}
}// End of IAP_Program

/**
 ******************************************************************************
 * @fn void IAP_Read(uint16_t addr, uint8_t *data_ptr)
 ******************************************************************************
 * @brief
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */

void IAP_Read(uint8_t addr, uint8_t *data_ptr, uint8_t data_len)
{
	uint8_t ctr = 0;

	for(ctr = 0; ctr < data_len; ctr++)
	{
		CKCON1 = CKCON1 & 0xC0 ;
		CKCON1 = CKCON1 | (11 -1 & 0x3F) ;
		IFADRH = IAP_START_ADDR_MSB;
		IFADRL = addr + ctr;
		IFMT = 0x01;
		IFD = 0x00 ;

		ISPCR = ISPCR |ISP_ENABLE;
		SCMD = 0x46;
		SCMD = 0xB9;
		ISPCR = ISPCR & 0x7F ;

		*data_ptr++ = IFD;
	}

}//End of IAP_Read

/*-------------------------------END OF FILE----------------------------------*/
