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
#include <sys/alt_irq.h>
#include <alt_types.h>


//Funcion de ISR
void IO_SW_ISR(void *context);


//funcion para establecer la interrupcion de entrada

void IO_SW_Setup();

//variable para la captura del flaco

volatile int edge_val =0;

int main()
{
  printf("Interrucpiones NIOS II \n");
  uint16_t  cont=0;
  IO_SW_Setup();

 for(;;){
	 if (edge_val & 0x01) {
		cont++;
		edge_val =0;
		  printf("Aumento de cuenta %u\n",cont);
	} else if (edge_val & 0x02) {

		cont--;
				edge_val =0;
				  printf("Disminuye de cuenta %u\n",cont);
	}

	 IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE,cont);

 }




}
void IO_SW_Setup(void){

	// Habilitar las interrupciones
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(SW_BASE,0X03);//0b11

	//limpio las interrupciones existentes
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(SW_BASE,0x00);

	 void *edge_val_ptr ;

	 edge_val_ptr = (void*) &edge_val;
//el registro de interrubion enlasarlo
	alt_ic_isr_register(SW_IRQ_INTERRUPT_CONTROLLER_ID,
			SW_IRQ,
			IO_SW_ISR,
			edge_val_ptr,
			0x00);



}


void IO_SW_ISR(void *context){

volatile int *edge_ptr;

edge_ptr = (volatile int *) context;

*edge_ptr =  IORD_ALTERA_AVALON_PIO_EDGE_CAP(SW_BASE);

//limpio las interrupciones existentes
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(SW_BASE,0x00);

}
