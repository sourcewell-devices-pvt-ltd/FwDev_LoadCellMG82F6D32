/**
******************************************************************************
* @file    UART0.C
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

#include <uart0.h>

/*
 *******************************************************************************
 *                          PRIVATE MACROS & CONSTANTS
 *******************************************************************************
 */
typedef struct
{
	uint8_t *buffer_ptr;
	uint8_t ctr;
	bool_t is_tx_over ;
}uart_tx_t;

/*
 *******************************************************************************
 *                         PRIVATE VARIABLE DECLARATION
 *******************************************************************************
 */

static uart_tx_t uart_tx;


/*
 *******************************************************************************
 *                         PRIVATE FUNCTION DECLARATION
 *******************************************************************************
 */

/**
 ******************************************************************************
 * @fn void INT_UART0(void)
 ******************************************************************************
 * @brief  void INT_UART0(void)
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
#ifdef C51_COMPILER
void INT_UART0(void) interrupt 4 using 2
#else
void INT_UART0(void) __interrupt  (4)
#endif
{	
	uint8_t rx_data = 0;
	SFRPI = 0;
	if((S0CON & 0x01) == 0x01)
	{
		S0CON &= 0xFE;
		rx_data = S0BUF;
		UartRxPrcs(rx_data);
	}
	else
	{
		S0CON &= 0xFD;
		if(uart_tx.ctr > 0)
		{
			S0BUF = *uart_tx.buffer_ptr++;
			uart_tx.ctr--;
		}
		else
		{
			uart_tx.is_tx_over = TRUE;
		}
	}
}// End of INT_UART0

/**
 ******************************************************************************
 * @fn void UART0_Transmit( uint8_t *buff_ptr , int len )
 ******************************************************************************
 * @brief
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
void UART0_Transmit( uint8_t *buff_ptr , uint8_t len )
{
	uart_tx.buffer_ptr = buff_ptr;
	uart_tx.ctr = len;
	uart_tx.is_tx_over = FALSE;
  SFRPI = 0;
	S0BUF = *uart_tx.buffer_ptr++;
	uart_tx.ctr--;

	while(FALSE == UART0_IsTxOver());

}// End of UART0_Transmit

/**
 ******************************************************************************
 * @fn bool_t UART0_IsTxOver(void)
 ******************************************************************************
 * @brief
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
bool_t UART0_IsTxOver(void)
{
	return(uart_tx.is_tx_over);
}// End of UART0_IsTxOver


/**
 ******************************************************************************
 * @fn void Initial_UART0 (void)
 ******************************************************************************
 * @brief
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
void Initial_UART0( void )
{
  TMOD |= 0x20;                                  // Set Timer1 at Mode 1
  CKCON0 |= AFS;                                 // IHRCO switch to 11.0592MHz.
	SFRPI = 0;
  S0CON = 0x50;                                  // Set UART0 at 8bit Mode
  TH1 = 0xFA;                                    // BR = 115200@11.059Mhz
  TL1 = 0xFA;                                    //
  AUXR2 = T1X12;                                 //
  PCON0 |= SMOD1;                                //

  uart_tx.is_tx_over = TRUE;

}//End of Initial_UART0



/*-------------------------------END OF FILE----------------------------------*/
