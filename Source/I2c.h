#ifndef _I2C_H
#define _I2C_H

#include <REG_MG82F6D32.H>
#include <comm_prcs.h>
#include <std_data_types.h>

extern void init_i2c(void);	
extern void I2cFillBuffer(uint8_t *buff_ptr);
#endif
