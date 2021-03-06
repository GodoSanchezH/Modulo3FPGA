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
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "altera_up_avalon_adc_regs.h"
#include "altera_up_avalon_adc.h"


#define	ADC_ADRR	0x21020	//DIRECCION DEL ADC
#define LED_ADRR 	0x21050	//DIRECCION DEL GPIO


int main()
{

	volatile int*adc = (int*)(ADC_ADRR);
	volatile int*led = (int*)(LED_ADRR);
	uint16_t data = 0;//donde se acumulara la lectura del canal
	uint32_t contador = 0;
	uint8_t channel = 0;


	for(;;){
		*(adc)=0;//Iniciamos el adc
		contador +=1;


		//Lectura ADC
		data = *(adc+channel);//selecciono el canal
		printf("ADC0 -> %u\n\r",data);
		//adc0 -> 12 bits -> 4095-> 8 led ->1023 /16>
		data = data/16;//data>>4;

		*(led)=data;// cargo el valor hacia el led
		if(contador = 500000){

			contador=0;
			channel = !channel;
		}

	}

  return 0;
}
