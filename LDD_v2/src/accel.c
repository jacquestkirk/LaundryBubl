/*
 * accel.c
 *
 *  Created on: Jul 11, 2015
 *      Author: jacquestkirk
 */

#include "accel.h"
#include "em_adc.h"
#include "em_gpio.h"
#include "em_cmu.h"
//#include "stdlib.h"


//private functions
int32_t adc_read(ADC_SingleInput_TypeDef);
//extern void GPIO_PinModeSet();
//////////////////////////////////////
/// Setup accelerometer
///////////////////////////////////////
void accel_setup(void)
{
	//Setup GPIO to turn accel on/off
	/* Enable GPIO clock */
	CMU_ClockEnable(cmuClock_GPIO, true);

	GPIO_PinModeSet(ACCEL_PWR_PORT, ACCEL_PWR_PIN, gpioModePushPull, 0);

	//Setup ADC
	/* Enable ADC clock */
	CMU_ClockEnable( cmuClock_ADC0, true);

	/* Base the ADC configuration on the default setup. */
	ADC_Init_TypeDef       init  = ADC_INIT_DEFAULT;

	/* Initialize timebases */
	init.timebase = ADC_TimebaseCalc(0);
	init.prescale = ADC_PrescaleCalc(400000, 0);
	ADC_Init(ADC0, &init);
}

/////////////////////////////////////
/// Turn on/off accelerometer
/////////////////////////////////////
void accel_turn_on()
{
	GPIO_PinOutSet(ACCEL_PWR_PORT,ACCEL_PWR_PIN);
}

void accel_turn_off()
{
	GPIO_PinOutClear(ACCEL_PWR_PORT,ACCEL_PWR_PIN);
}


////////////////////////////////////////
/// Read data from accelerometer
///////////////////////////////////////
int32_t accel_read_x()
{

	return adc_read(ACCEL_X_CHANNEL);
}

int32_t accel_read_y()
{
	return adc_read(ACCEL_Y_CHANNEL);
}

int32_t accel_read_z()
{
	return adc_read(ACCEL_Z_CHANNEL);
}

int32_t adc_read(ADC_SingleInput_TypeDef input)
{
	/* Set input to temperature sensor. Reference must be 1.25V*/
	ADC_InitSingle_TypeDef sInit = ADC_INITSINGLE_DEFAULT;
	sInit.reference = adcRefVDD;
	sInit.input     = input;

	ADC_InitSingle(ADC0, &sInit);

	/*
	ADC_InitSingle_TypeDef sInit = ADC_INITSINGLE_DEFAULT;
	sInit.reference = ADC_REF;
	sInit.input = input;

	ADC_InitSingle(ADC0, &sInit);*/

	ADC_Start(ADC0, adcStartSingle);
	while ( ( ADC0->STATUS & ADC_STATUS_SINGLEDV ) == 0 ){}
	return ADC_DataSingleGet(ADC0);
}

float accel_adc_to_gs(int32_t adc_reading)
{
	return (abs(adc_reading)*7.2/4095);
}


