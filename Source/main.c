/**
 ******************************************************************************
 * @file    main.c
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

#include "main.h"

#ifdef SDCC_COMPILER
extern void INT_UART0(void) __interrupt (4);
extern void INT_TWSI(void) __interrupt  (12);
extern void INT_TIMER0(void) __interrupt (1) ;
#endif

/*
 *******************************************************************************
 *                          PRIVATE MACROS & CONSTANTS
 *******************************************************************************
 */

//None

/*
 *******************************************************************************
 *                         PRIVATE VARIABLE DECLARATION
 *******************************************************************************
 */

//None

/*
 *******************************************************************************
 *                         PRIVATE FUNCTION DECLARATION
 *******************************************************************************
 */

/**
 ******************************************************************************
 * @fn  void main(void)
 ******************************************************************************
 * @brief 
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
void main(void)
{	
	uint32_t timer = 0;
//	static uint32_t led_toggle_timer = 0;
	
	typedef enum
	{
		LOAD_CELL_PRCS_STATE,
		COMM_PRCS_STATE,
		I2C_COMM_PRCS_STATE
	}main_state_t;

	main_state_t main_state = LOAD_CELL_PRCS_STATE;	

	Sys_Init();

//	UART0_Transmit("Hello World\n", 12);

	while(1)

	{
//		if(TRUE == (SysTick_IsTimeOutOccurred(&timer , 20)))
//		{
//			UART0_Transmit("Hello World\n", 12);
//		}
		
//			if(TRUE == SysTick_IsTimeOutOccurred(&led_toggle_timer, 5))
//	{
//		SFRPI=1;                                  
//		P6 ^= 2;                                    //This is to set pin 6.1 toggle
//		SFRPI=0;
//	}
		
		switch(main_state)
		{
		case LOAD_CELL_PRCS_STATE:
			LoadCellPrcs();
			main_state = COMM_PRCS_STATE;
			break;
		case COMM_PRCS_STATE:
			CommPrcs();
			main_state = I2C_COMM_PRCS_STATE;
			break;
		case I2C_COMM_PRCS_STATE:
			I2cCommPrcs();
			main_state = LOAD_CELL_PRCS_STATE;
			break;
		}
	}
} //End of main


/*-------------------------------END OF FILE----------------------------------*/
