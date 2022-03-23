/**
 ******************************************************************************
 * @file    comm_prcs.c
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

#include "comm_prcs.h"


/*
 *******************************************************************************
 *                          PRIVATE MACROS & CONSTANTS
 *******************************************************************************
 */

typedef struct 
{
	uint8_t buffer[16];
	uint8_t *buffer_ptr;
	uint8_t ctr;
}buff_rx_t;

//typedef struct i2c_rx_t
//{
//	uint8_t buffer[16];
//	uint8_t *buffer_ptr;
//	uint8_t ctr;
//};

//typedef enum confMenuStates
//{
//	CONF_MENU_COMMAND = 1,
//	TARE_ZERO_COMMAND,
//	EXIT_CONF_MENU_COMMAND,
//	CALIBRATION_COMMAND
//};

/*
 *******************************************************************************
 *                         PRIVATE VARIABLE DECLARATION
 *******************************************************************************
 */

static buff_rx_t uart_rx_db;
static buff_rx_t i2c_rx_db;

/*
 *******************************************************************************
 *                         PRIVATE FUNCTION DECLARATION
 *******************************************************************************
 */

static void ClearUartRecvBuff(void);
static void ClearI2cRecvBuff(void);
//static bool_t read_calibration_data (void);


/**
 ******************************************************************************
 * @fn void CommPrcs (void)
 ******************************************************************************
 * @brief  void CommPrcs (void)
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
void Comm_Init(void)
{
	Initial_UART0();
	ClearUartRecvBuff();

}//End of Comm_Init

/**
 ******************************************************************************
 * @fn void CommPrcs (void)
 ******************************************************************************
 * @brief  void CommPrcs (void)
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
void CommPrcs (void)
{
	typedef enum
	{
		COMM_SEND_DATA_ST,
		READ_CALIBRATION_SCALE
	}comm_prcs_state_t;

	static comm_prcs_state_t comm_prcs_state = COMM_SEND_DATA_ST;
	load_cell_db_t *load_cell_db_ptr = GetLoadCellDb();
//	uint8_t *temp_ptr = (uint8_t *)(&load_cell_db_ptr->cal_value);
	float32_t temp_cal_value = 0.0;
	uint8_t *temp_ptr = (uint8_t *)(&temp_cal_value);		
	static uint32_t led_toggle_timer = 0;

	switch(comm_prcs_state)
	{
	case COMM_SEND_DATA_ST:
	if(TRUE == SysTick_IsTimeOutOccurred(&led_toggle_timer, 5))
	{
		SFRPI=1;                                  
		P6 ^= 2;                                    //This is to set pin 6.1 toggle
		SFRPI=0;
	}

		if ( 'R' == uart_rx_db.buffer[0])
		{
			UART0_Transmit((uint8_t*)&uart_rx_db.buffer[0] , 1);
			UART0_Transmit((uint8_t*)&load_cell_db_ptr->raw_value , 8);
			ClearUartRecvBuff();
		}
		else if(uart_rx_db.buffer[0] == 'T')
		{
			LoadCellTare(10);
			ClearUartRecvBuff();
		}
		else if(uart_rx_db.buffer[0] == 'C')
		{
			comm_prcs_state = READ_CALIBRATION_SCALE;
		}
		else if ( 'X' == uart_rx_db.buffer[0])
		{
			
			UART0_Transmit((uint8_t*)&uart_rx_db.buffer[0] , 1);
			UART0_Transmit((uint8_t*)&load_cell_db_ptr->cal_value , 8);
			ClearUartRecvBuff();
		}
		break;

	case READ_CALIBRATION_SCALE:
		if(uart_rx_db.ctr >= 5)
		{
			*temp_ptr++ = uart_rx_db.buffer[1];
			*temp_ptr++ = uart_rx_db.buffer[2];
			*temp_ptr++ = uart_rx_db.buffer[3];
			*temp_ptr++ = uart_rx_db.buffer[4];
			
			 load_cell_db_ptr->cal_value = (load_cell_db_ptr->raw_value  - load_cell_db_ptr->offset)/temp_cal_value; 

			ClearUartRecvBuff();
			IAP_Program(CAL_VALUE_ADDR , (uint8_t *)(&load_cell_db_ptr->cal_value) , 4);
			comm_prcs_state = COMM_SEND_DATA_ST;
		}
		break;
	}
}//End of CommPrcs




/**
 ******************************************************************************
 * @fn void I2cCommPrcs (void)
 ******************************************************************************
 * @brief  void I2cCommPrcs (void)
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
void I2cCommPrcs (void)
{
	typedef enum
	{
		COMM_SEND_DATA_ST,
		READ_CALIBRATION_SCALE
	}comm_prcs_state_t;

	static comm_prcs_state_t I2c_comm_prcs_state = COMM_SEND_DATA_ST;
	load_cell_db_t *load_cell_db_ptr = GetLoadCellDb();
//	uint8_t *temp_ptr = (uint8_t *)(&load_cell_db_ptr->cal_value);
	uint8_t *temp_ptr2 = (uint8_t *)(&load_cell_db_ptr->raw_value);
	uint8_t temp_data[9] = {0};
  static uint8_t cal_data_wait = 0;
	
	float32_t temp_cal_value = 0.0;
	uint8_t *temp_ptr = (uint8_t *)(&temp_cal_value);	

	switch(I2c_comm_prcs_state)
	{
	case COMM_SEND_DATA_ST:

		if (i2c_rx_db.buffer[0] == 'R')
		{
			temp_data[0] = i2c_rx_db.buffer[0];
			temp_data[1] = *temp_ptr2++;
			temp_data[2] = *temp_ptr2++;
			temp_data[3] = *temp_ptr2++;
			temp_data[4] = *temp_ptr2++;
			temp_data[5] = *temp_ptr2++;
			temp_data[6] = *temp_ptr2++;
			temp_data[7] = *temp_ptr2++;
			temp_data[8] = *temp_ptr2;
			
//			ClearI2cRecvBuff();
			
			I2cFillBuffer(temp_data);
		}
		else if(i2c_rx_db.buffer[0] == 'T')
		{
			LoadCellTare(10);              //10 OG VALUE
//			ClearI2cRecvBuff();
		}
		else if(i2c_rx_db.buffer[0] == 'C')
		{
			cal_data_wait++;
			if(i2c_rx_db.ctr > 8 )
			{
			  I2c_comm_prcs_state = READ_CALIBRATION_SCALE;
				cal_data_wait = 0;
			}
			if(cal_data_wait > 20)
			{
				ClearI2cRecvBuff();
				cal_data_wait = 0;
			}
		}
		else if (i2c_rx_db.buffer[0] == 'X')
		{
			temp_data[0] = i2c_rx_db.buffer[0];
			temp_data[1] = *temp_ptr++;
			temp_data[2] = *temp_ptr++;
			temp_data[3] = *temp_ptr++;
			temp_data[4] = *temp_ptr++;
			temp_data[5] = *temp_ptr++;
			temp_data[6] = *temp_ptr++;
			temp_data[7] = *temp_ptr++;
			temp_data[8] = *temp_ptr;
			
//			ClearI2cRecvBuff();
			
			I2cFillBuffer(temp_data);
		}
		
		if(i2c_rx_db.buffer[0] != 'C')
		{
			ClearI2cRecvBuff();
		}
		break;

	case READ_CALIBRATION_SCALE:
		if(i2c_rx_db.ctr >= 5)
		{			
			*temp_ptr++ = i2c_rx_db.buffer[1];
			*temp_ptr++ = i2c_rx_db.buffer[2];
			*temp_ptr++ = i2c_rx_db.buffer[3];
			*temp_ptr++ = i2c_rx_db.buffer[4];
			
			 load_cell_db_ptr->cal_value = (load_cell_db_ptr->raw_value  - load_cell_db_ptr->offset)/temp_cal_value; 


			ClearI2cRecvBuff();
			IAP_Program(CAL_VALUE_ADDR , (uint8_t *)(&load_cell_db_ptr->cal_value) , 4);
			I2c_comm_prcs_state = COMM_SEND_DATA_ST;
		}
		break;
	}
}//End of I2cCommPrcs


/**
 ******************************************************************************
 * @fn void UartRxPrcs (uint8_t rx_data)
 ******************************************************************************
 * @brief  void UartRxPrcs (uint8_t rx_data)
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
void UartRxPrcs (uint8_t rx_data)
{
	if(uart_rx_db.ctr < 16)
	{
		*uart_rx_db.buffer_ptr++ = rx_data;
		uart_rx_db.ctr++;
	}
	else
	{
		uart_rx_db.buffer_ptr = uart_rx_db.buffer;
		uart_rx_db.ctr = 0;
	}
}// End of UartRxPrcs


/**
 ******************************************************************************
 * @fn void ClearUartRecvBuff(void)
 ******************************************************************************
 * @brief
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
void ClearUartRecvBuff(void)
{
	(void)memset(uart_rx_db.buffer , 0 , 16);
	uart_rx_db.buffer_ptr = uart_rx_db.buffer;
	uart_rx_db.ctr = 0;
}// End of ClearUartRecvBuff


/**
 ******************************************************************************
 * @fn void I2cRxPrcs (uint8_t rx_data)
 ******************************************************************************
 * @brief  void I2cRxPrcs (uint8_t rx_data)
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
void I2cRxPrcs (uint8_t rx_data)
{
	if(i2c_rx_db.ctr < 16)
	{
		*i2c_rx_db.buffer_ptr++ = rx_data;
		i2c_rx_db.ctr++;
	}
	else
	{
		i2c_rx_db.buffer_ptr = i2c_rx_db.buffer;
		i2c_rx_db.ctr = 0;
	}
}// End of I2cRxPrcs

/**
 ******************************************************************************
 * @fn void ClearI2cRecvBuff(void)
 ******************************************************************************
 * @brief
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
void ClearI2cRecvBuff(void)
{
	(void)memset(i2c_rx_db.buffer , 0 , 16);
	i2c_rx_db.buffer_ptr = i2c_rx_db.buffer;
	i2c_rx_db.ctr = 0;
}// End of ClearI2cRecvBuff



/**
 ******************************************************************************
 * @fn void Delay (void)
 ******************************************************************************
 * @brief
 * @note   None
 * @param  None
 * @retval None
 ******************************************************************************
 */
void Delay (void)
{
	int i, j;

	for(i=0; i<1000; i++)
	{
		for(j=0; j<100; j++)
		{
		}
	}
}//End of Delay

/*-------------------------------END OF FILE----------------------------------*/
