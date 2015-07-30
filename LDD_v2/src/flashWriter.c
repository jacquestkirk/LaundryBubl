/*
 * flashWriter.c
 *
 *  Created on: Jul 12, 2015
 *      Author: jacquestkirk
 */

#include "flashWriter.h"
#include "em_msc.h"

uint32_t * address = (uint32_t *) FLASH_START_ADDR;

void flashwriter_init(void)
{
	MSC_Init();
}

void flashwriter_write_triple_int32(int32_t *x_reading, int32_t *y_reading,	int32_t *z_reading)
{
	//todo: pack more efficiently
	flashwriter_int32(x_reading);
	flashwriter_int32(y_reading);
	flashwriter_int32(z_reading);
}

void flashwriter_int32(int32_t * data)
{
	if((int)address >= FLASH_MAX_ADDR) //don't start writing outside of the valid range
	{
		return;
	}


	if((int)address % 1024 == 0 ) //if we are on a page boundary, erase the page before writing
	{
		MSC_ErasePage(address);
	}


	MSC_WriteWord(address, data, 4);

	address = address + 1;
}
