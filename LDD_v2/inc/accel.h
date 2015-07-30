/*
 * accel.h
 *
 *  Created on: Jul 11, 2015
 *      Author: jacquestkirk
 */

#ifndef ACCEL_H_
#define ACCEL_H_

#include "stdint.h"



#define ADC_REF adcRef1V25

//Channel definitions
#define ACCEL_X_CHANNEL adcSingleInpCh5
#define ACCEL_Y_CHANNEL adcSingleInpCh6
#define ACCEL_Z_CHANNEL adcSingleInpCh7

//ADC Power GPIO definition
#define ACCEL_PWR_PORT       gpioPortD
#define ACCEL_PWR_PIN        4



/// Setup accelerometer
void accel_setup(void);

/// Turn on/off accelerometer
void accel_turn_on(void);
void accel_turn_off(void);

// Read data from accelerometer
int32_t accel_read_x(void);
int32_t accel_read_y(void);
int32_t accel_read_z(void);

// Calculator functions
float accel_adc_to_gs(int32_t);


#endif /* ACCEL_H_ */
