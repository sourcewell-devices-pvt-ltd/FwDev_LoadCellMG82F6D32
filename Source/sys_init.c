/**
 ******************************************************************************
 * @file    sys_init.c
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

#include "sys_init.h"


/*
 *******************************************************************************
 *                          PRIVATE MACROS & CONSTANTS
 *******************************************************************************
 */

//NONE

/*
 *******************************************************************************
 *                         PRIVATE VARIABLE DECLARATION
 *******************************************************************************
 */
// None


/*
 *******************************************************************************
 *                         PRIVATE FUNCTION DECLARATION
 *******************************************************************************
 */
// None


void Interrupt_Enable( void )
{
	TCON |= (1 << 4);                                     // Enable Timer0
	IE  |= (1 << 1);                                    // Enable Timer0 interrupt
	TCON |= (1 << 6);                                      // Enable Timer1 for UART
	IE  |= (1 << 4);                                     // Enable Uart0 interrupt
	IE  |= (1 << 7);                                     // Enable All interrupt gate
	EIE1 |=  (1 << 6);									//Enable TWI0 interrupt
}

/**
 ******************************************************************************
 * @fn void Sys_Init(void)
 ******************************************************************************
 * @brief  System initialization function.
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
void Sys_Init(void)
{
/***** P0.1 P6.0 P6.1 set as pushpull mode ****/
		AUXR0 &= (~0xC0);
		P0M0 |= 2;		  // P0.1 as output
	
		SFRPI=1;
		P6M0 |= 3;		  // P6.1 as output
		P2M1 &= ~1;

	
		SFRPI=3;
		P6M1 &= ~3;	
	
		SFRPI=4;
		P0M1=P0M1&(~(2));
	
		SFRPI=0 ;
	
		SFRPI=1;                                  
		P6 |= 3;                                    //This is to set pin 6.0 and 6.1 to off
		
		SFRPI=0 ;                                   
		P0 |= 2;                                    //This is to set pin 0.1 to off 
/*****************************************/

/**** P1.6 and 1.7 as pushpull mode ****/
	P1M0 |= 0x80;         //Configure port 1.7 as digital io & P1.6 to Pushpull mode
	P1M0 &= ~0X40;
	SFRPI = 0; 
	P1M1 &= (~0xC0);  
  P1 |= 0X40;
  	 
/*****************************************/

	LoadCellDbInit();

	Comm_Init();

	SysTick_Init();

	init_i2c();

	Interrupt_Enable();

}// End of Sys_Init


/*-------------------------------END OF FILE----------------------------------*/
