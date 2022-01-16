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
#include <system.h>
#include <altera_avalon_pio_regs.h>

uint32_t i,j;
uint8_t a;
void Ejemplo1(void);
int main()
{
  printf("Modulo 3!\n");
  printf("FPGA - MMJ SMART ELECTRONICS\n");
  printf("NIOS2!!!!\n");

  for(;;){

	a = IORD(PORTX_BASE,0);

	if(a==1){
		IOWR(LATX_BASE,0,0XF0);
	}
	else if(a==2){
		IOWR(LATX_BASE,0,0X0F);
	}
	else if(a==3){
			IOWR(LATX_BASE,0,0X00);
		}
  else IOWR(LATX_BASE,0,0xAA);
  }
  return 0;
}
void Ejemplo1(void){
	IOWR(LATX_BASE,0,0XAA);//1010 1010
		  for(i=0;i<=500000;i++);
		  IOWR(LATX_BASE,0,0X55);//0101 0101
		  for(i=0;i<=500000;i++);

		  for(i=0;i<=255;i++){
			  IOWR(LATX_BASE,0,i);
			  for(j=0;j<=100000;j++);
		  }

}
