/*
 * accel.c
 *
 *  Created on: Jul 11, 2015
 *      Author: manofwar
 */

#include "buzzer.h"
#include "em_adc.h"
#include "em_gpio.h"
#include "em_cmu.h"
//#include "stdlib.h"


//private functions


//extern void GPIO_PinModeSet();
//////////////////////////////////////
/// Setup buzzer
///////////////////////////////////////
void buzzer_setup(void)
{
	//Setup GPIO to turn accel on/off
	/* Enable GPIO clock */
	CMU_ClockEnable(cmuClock_GPIO, true);

	GPIO_PinModeSet (BUZZER_EN_PORT, BUZZER_EN_PIN, gpioModePushPull, 0);

	//Setup ADC
	/* Enable ADC clock */
	CMU_ClockEnable( cmuClock_ADC0, true);

}

/////////////////////////////////////
/// Enable/disable buzzer
/////////////////////////////////////
void buzzer_en()
{
	GPIO_PinOutSet(BUZZER_EN_PORT, BUZZER_EN_PIN);
}

void buzzer_dis()
{
	GPIO_PinOutClear(BUZZER_EN_PORT, BUZZER_EN_PIN);
}

void wait_second()
{
	for (double i = 0; i < 32258; i++){}
}

void wait_millisecond()
{
	for (double i = 0; i < 32; i++){}
}

void wait_numseconds(seconds)
{
	for (int i = 0; i < seconds; i++)
	{
		wait_second();
	}
}

void buzzer_second()
{
	buzzer_en();
	wait_second();
	buzzer_dis();
}

void buzzer_millisecond()
{
	buzzer_en();
	wait_millisecond();
	buzzer_dis();
}
