/**
 ******************************************************************************
 * @file    I2c.c
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

#include "I2c.h"

/*
 *******************************************************************************
 *                          PRIVATE MACROS & CONSTANTS
 *******************************************************************************
 */



/*
 *******************************************************************************
 *                         PRIVATE VARIABLE DECLARATION
 *******************************************************************************
 */

uint8_t i2c_buff[9];
uint8_t i2c_data = 0; 
uint8_t ctr = 0;

	
/*
 *******************************************************************************
 *                         PRIVATE FUNCTION DECLARATION
 *******************************************************************************
 */



/**
 ******************************************************************************
 * @fn void INT_TWSI(void) __interrupt  (14)
 ******************************************************************************
 * @brief
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */

#ifdef C51_COMPILER
void INT_TWSI() interrupt 14
#else
		void INT_TWSI(void) __interrupt  (14)
#endif
		{
	//_push_(SFRPI);	
	SFRPI=0;
	switch(SISTA)
	{
	case 0x60:	//   ACK
	case 0x68:	// OWN SLAVE ADDR RECVD WRITE BIT SET //ACK SENT
		SICON &= (~(STA | STO));
		SICON |= AA;
			ctr=0;
		break;

	case 0x80:	//ACK //BYTE RECVD
		I2cRxPrcs(SIDAT);
		SICON &= (~(STA | STO));
		SICON |= AA;
		break;

	case 0xA0:  // STOP IN RX MODE/REPEATED START RECVD IN SLAVE RECVR MODE
		SICON &= (~(STA | STO));
		SICON |= AA;
		ctr=0;
	
		break;

	case 0xA8:  // +R,  ACK
	case 0xB0:  // OWN SLAVE ADDR RECVD WITH READ BIT LOW//ACK SENT
		//SICON &= (~(STA | STO | AA));
	
		SICON &= (~(STA | STO));
		SICON |= AA;

		SIDAT = i2c_buff[ctr];
		ctr++;
	
		break;

	case 0xC8:	// LAST DATA BYTE SENT   // ACK RECVD
	case 0xB8:  // SIDAT�  ACK
		SICON &= (~(STA | STO));

		if(ctr > 9)
		{
			ctr = 0;
			SICON &= (~ AA);
		}
		else
		{
			SICON |= AA;
		}
		SIDAT = i2c_buff[ctr];
		ctr++;
		break;

	case 0xC0:  // LAST DATA BYTE SENT //NO ACK RECVD
		SICON &= (~(STA | STO));
		SICON |= AA;

		ctr=0;
		break;

	default:
		SICON &= (~(STA | STO));
		SICON |= AA;
		ctr=0;
		break;
	}


		SICON = SICON &(~SI);		// 
		
	} // end of INT_TWSI


/**
 ******************************************************************************
 * @fn void INT_TWSI(void) __interrupt  (14)
 ******************************************************************************
 * @brief
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */

void init_i2c(void)
{
	SFRPI = 0;
	P4M0 &= (~0x03);                // OPEN DRAIN MODE ON P40 AND P41
	P4 |= 1;                        // P4.0 SET
	P4 |= (1<<1);                   // p4.1 SET
	AUXR3 &= (~((1<<2)|(1<<1)));
	SIADR = (0x44 << 1);           //Setting i2c slave address 44 last GC bit set to 1 to respond device on 00 slave address
	SICON &= ~(STA | STO | SI);
	SICON |= (ENSI | AA);
} // end of init_i2c

/**
 ******************************************************************************
 * @fn void INT_TWSI(void) __interrupt  (14)
 ******************************************************************************
 * @brief
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */

void I2cFillBuffer(uint8_t *buff_ptr)
{
	i2c_buff[0] = *buff_ptr++;
	i2c_buff[1] = *buff_ptr++;
	i2c_buff[2] = *buff_ptr++;
	i2c_buff[3] = *buff_ptr++;
	i2c_buff[4] = *buff_ptr++;
	i2c_buff[5] = *buff_ptr++;
	i2c_buff[6] = *buff_ptr++;
	i2c_buff[7] = *buff_ptr++;
	i2c_buff[8] = *buff_ptr;
	
	
//	i2c_buff[0] = 0xFF;
//	i2c_buff[1] = 0xF3;
//	i2c_buff[2] = 0xE1;
//	i2c_buff[3] = 0x2D;
//	i2c_buff[4] = 0x1C;
//	i2c_buff[5] = 0x0A;
//	i2c_buff[6] = 0x7C;
//	i2c_buff[7] = 0xED;
} // end of init_i2c

/*-------------------------------END OF FILE----------------------------------*/

