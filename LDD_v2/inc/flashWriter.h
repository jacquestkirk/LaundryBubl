/*
 * flashWriter.h
 *
 *  Created on: Jul 12, 2015
 *      Author: jacquestkirk
 */

#ifndef FLASHWRITER_H_
#define FLASHWRITER_H_

#include "stdint.h"

#define FLASH_START_ADDR 0x00004000
#define FLASH_MAX_ADDR 0x00020000

void flashwriter_init(void);

void flashwriter_write_triple_int32(int32_t *x_reading, int32_t *y_reading, int32_t *z_reading);

void flashwriter_int32(int32_t *data);

#endif /* FLASHWRITER_H_ */
