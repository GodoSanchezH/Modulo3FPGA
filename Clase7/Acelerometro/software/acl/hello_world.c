/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <altera_up_avalon_accelerometer_spi.h>
#include <system.h>
#include <unistd.h>

int main()
{

alt_up_accelerometer_spi_dev * acc_dev;

acc_dev = alt_up_accelerometer_spi_open_dev("/dev/accelerometer");
if (acc_dev = NULL) {
	printf("ERROR DE COMUNCIACION");
} else {
	printf("Open acc device\n");
}

int32_t xAcel = 0;
int32_t yAcel = 0;
int32_t zAcel = 0;

  for(;;){

	  alt_up_accelerometer_spi_read_x_axis(acc_dev,&xAcel);
	  alt_up_accelerometer_spi_read_y_axis(acc_dev,&yAcel);
	  alt_up_accelerometer_spi_read_z_axis(acc_dev,&zAcel);

	  printf(" %li %li %li\n",xAcel,yAcel,zAcel);
	  usleep(1000000);

  }

  return 0;
}
