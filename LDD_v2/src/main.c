/**************************************************************************//**
 * @file
 * @brief Empty Project
 * @author Energy Micro AS
 * @version 3.20.2
 ******************************************************************************
 * @section License
 * <b>(C) Copyright 2014 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silicon Labs Software License Agreement. See 
 * "http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt"  
 * for details. Before using this software for any purpose, you must agree to the 
 * terms of that agreement.
 *
 ******************************************************************************/
#include <math.h>

#include "em_device.h"
#include "em_chip.h"
#include "accel.h"
#include "buzzer.h"

#define G_TO_ADC_SQUARED 290322 //539

/**************************************************************************//**
 * @brief  Main function
 *****************************************************************************/
int not_main(void)
{
  int32_t x_reading_old;
  int32_t y_reading_old;
  int32_t z_reading_old;
  int32_t composite_reading_old;
  int32_t x_reading;
  int32_t y_reading;
  int32_t z_reading;
  int32_t composite_reading;
  int32_t x_reading_delta;
  int32_t y_reading_delta;
  int32_t z_reading_delta;
  int32_t mag_composite_reading_delta;

  // X, Y, Z Offsets
  int32_t X_OFFSET = 4095*((3.3-1.44)/3.3); // 1.44V
  int32_t Y_OFFSET = 4095*((3.3-1.44)/3.3); // 1.44V
  int32_t Z_OFFSET = 4095*((3.3-1.53)/3.3); // 1.53V

  float x_accel;
  float y_accel;
  float z_accel;

  float total_accel;

  /* Chip errata */
  CHIP_Init();

  /* Infinite loop */

  accel_setup();
  accel_turn_on();
  buzzer_setup();

  // Initial readings
  wait_numseconds(1);
  x_reading = accel_read_x() - X_OFFSET;
  y_reading = accel_read_y() - Y_OFFSET;
  z_reading = accel_read_z() - Z_OFFSET;
  composite_reading = x_reading*x_reading + y_reading*y_reading + z_reading*z_reading;

  wait_numseconds(5);

  // Laundry Done Check:
  do
  {
	  // Copy into old reading
	  x_reading_old = x_reading;
	  y_reading_old = y_reading;
	  z_reading_old = z_reading;
	  composite_reading_old = composite_reading;

	  // Get new reading & buzz
	  x_reading = accel_read_x() - X_OFFSET;
	  y_reading = accel_read_y() - Y_OFFSET;
	  z_reading = accel_read_z() - Z_OFFSET;
	  composite_reading = x_reading*x_reading + y_reading*y_reading + z_reading*z_reading;

	  for(int i =0; i< 10; i++)
	  {
	  buzzer_millisecond();
	  }

	  // Delta of two readings
	  x_reading_delta = x_reading - x_reading_old;
	  y_reading_delta = y_reading - y_reading_old;
	  z_reading_delta = z_reading - z_reading_old;
	  mag_composite_reading_delta = abs(composite_reading - composite_reading_old);
	  //composite_reading_delta = sqrt(x_reading_delta*x_reading_delta + y_reading_delta*y_reading_delta + z_reading_delta*z_reading_delta);

	  // Wait 3 sec
	  wait_numseconds(3);


  } while(   (mag_composite_reading_delta > (G_TO_ADC_SQUARED/100)));
		  //|| ((composite_reading < (G_TO_ADC_SQUARED*(0.75*0.75)))  ||  (composite_reading > (G_TO_ADC_SQUARED*(1.25*1.25))))   );*/

  // Buzz for 10 seconds
  buzzer_second();
  buzzer_second();
  buzzer_second();
  buzzer_second();
  buzzer_second();
  buzzer_second();
  buzzer_second();
  buzzer_second();
  buzzer_second();
  buzzer_second();
  buzzer_second();

}
