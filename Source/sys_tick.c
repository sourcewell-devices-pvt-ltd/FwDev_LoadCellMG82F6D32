/**
******************************************************************************
* @file    sys_tick.c
* @author  Nasreen Shaikh
* @version 01.00
* @date    30-MAR-2018
* @brief   This is a peripheral interface for Cortex M0 SysTick timer.
* 			+ SysTick_Init initializes this inbuilt timer to generate an interrupt
* 			  every 1 milisecond
* 			+ A free running timer is included which can be used as a generic
* 			  timer for time crucial functions.
*
******************************************************************************
* @attention
* @{
* <h2><center>&copy; Copyright 2017 Marjan Solar </center></h2>
*			                All rights reserved.
* An unpublished work by Petrotec  Limited . This material contains
* CONFIDENTIAL INFORMATION that is the property of Petrotec  Limited .
* Any unauthorized use, duplication or disclosure is prohibited.
* @}
******************************************************************************
*/

/*
*******************************************************************************
*                               FILE HISTORY
*******************************************************************************
* Change    : 01
* Author    : Nasreen Shaikh
* Date      : 30-MAR-2018
* Brief     : created file
*
*******************************************************************************
*/

/*
*******************************************************************************
*                           PRIVATE INCLUDES
*******************************************************************************
*/

#include "sys_tick.h"


/*
*******************************************************************************
*                          PRIVATE MACROS                                
*******************************************************************************
*/

#define FREE_TIMER_MAX_COUNT        	(0xFFFFFFFFUL)


#define    T0_50MSL         0x00                 // ( 65536 - 46080 )%256 in 11.0592Mhz
#define    T0_50MSH         0x4C                 // ( 65536 - 46080 )/256 in 11.0592Mhz
#define    T0_TIMEROUT      60                   // 60*50ms = 3s
/*
*******************************************************************************
*                         PRIVATE VARIABLE DECLARATION
*******************************************************************************
*/

static uint32_t free_running_timer = 0;

/*
*******************************************************************************
*                         PRIVATE FUNCTION DECLARATION
*******************************************************************************
*/

// None

/**
******************************************************************************
* @fn void SysTick_Init(void)
******************************************************************************
* @brief  Initialize the Hardware timer for the 1msec interval.
* @note   None
* @param  None
* @retval None
******************************************************************************
*/

void SysTick_Init(void) 
{
	TMOD |= 0x01;                                  // Set Timer0 in mode 1, 16bit timer/counter Mode
	TL0 = T0_50MSL;
	TH0 = T0_50MSH;

}// End of SysTick_Init

/**
******************************************************************************
* @fn uint32_t SysTick_GetFreeRunningTimer(void)
******************************************************************************
* @brief  Return the current value of timer.
* @note   None
* @param  None
* @retval free_running_timer: Current value of timer
******************************************************************************
*/

uint32_t SysTick_GetFreeRunningTimer(void)
{
	return(free_running_timer);
}// End of SysTick_GetFreeRunningTimer


/**
******************************************************************************
* @fn bool_t SysTick_IsTimeOutOccurred(uint32_t *prvs_timer_ptr, uint32_t timeout_period)
******************************************************************************
* @brief  This routine checks the timer variable with current timer and the updates
* 		  the status of timeout flag. In case of timer the ui_prcs timer
* 		  variable is updated with current timer for next interval.
* @note   None
* @param  None
* @retval is_time_out_occured: TRUE => If timeout occurred
  	  	  	       	   	   	   FALSE=> If no Timeout
******************************************************************************
*/

bool_t SysTick_IsTimeOutOccurred(uint32_t *prvs_timer_ptr, uint32_t timeout_period)
{
	uint32_t timer_difference = 0;
	bool_t is_time_out_occured = FALSE;
	
	timer_difference = (free_running_timer - *prvs_timer_ptr);

	if(timer_difference > timeout_period)
	{
		is_time_out_occured = TRUE;
		*prvs_timer_ptr = free_running_timer;
	}
	else
	{
		is_time_out_occured = FALSE;
	}
	
	return(is_time_out_occured);
} // End of SysTick_IsTimeOutOccurred

/**
******************************************************************************
* @fn void SysTick_Handler(void)
******************************************************************************
* @brief  SysTick_Handler of module.
*	   	  Increments the free running timer on each timer interrupt.
* @note   None
* @param  None
* @retval None
******************************************************************************
*/
#ifdef C51_COMPILER
void INT_TIMER0(void) interrupt 1 using 2 // Timer0 Interrupt
#else
void INT_TIMER0(void) __interrupt (1)  // Timer0 Interrupt
#endif
{
	TL0 = T0_50MSL;
	TH0 = T0_50MSH;
	//--> Increment free running timer
	free_running_timer++;

}//End of INT_TIMER0



/*-------------------------------END OF FILE----------------------------------*/
