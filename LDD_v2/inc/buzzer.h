/*
 * buzzer.h
 *
 *  Created on: Jul 11, 2015
 *      Author: manofwar
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "stdint.h"


//ADC Buzzer Enable GPIO definition
#define BUZZER_EN_PORT		 gpioPortE
#define BUZZER_EN_PIN			 10


/// Setup buzzer
void buzzer_setup(void);

/// Turn on/off accelerometer
void buzzer_en(void);
void buzzer_dis(void);
void wait_second(void);
void wait_millisecond(void);
void wait_numseconds(int seconds);
void buzzer_second(void);
void buzzer_millisecond(void);

#endif /* BUZZER_H_ */
