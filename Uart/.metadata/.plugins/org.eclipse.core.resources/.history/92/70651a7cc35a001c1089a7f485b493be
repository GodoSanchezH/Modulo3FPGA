/**
 * Modulo 3 FPGA
 *
 */


//LIbrerias del ANSI C
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
//Librerias del Micro Blaze
#include <xparameters.h> //Libreria de los paremtros y direcciones de Memoria
#include <xgpio.h>
#include <xuartlite.h>
#include  <xintc.h>
#include <xil_exception.h>>



XGpio LEDS,SW;
XUartLite RS232;
XIntc Interrupcion;
u32 i,j;
u8 data;
u8 lectura[5];

void Ejemplo1(void);
u8 buffer_tx[50]= "Hola Mundo\r\n";
void RS232_Interrupcion(void *callback);
int main()
{

	XGpio_Initialize(&LEDS,XPAR_LEDS_DEVICE_ID);//	Inicializamos Leds
	XUartLite_Initialize(&RS232,XPAR_UARTLITE_1_DEVICE_ID);//	Inicializamos el perifferico de la uart
	XIntc_Initialize(&Interrupcion,XPAR_XPS_INTC_0_DEVICE_ID);//	Inicializamos el periferico de interrupcion
	XIntc_Connect(&Interrupcion,XPAR_XPS_INTC_0_RS232_INTERRUPT_INTR,(Xil_ExceptionHandler)RS232_Interrupcion,&RS232);//conectamos la interrupcion de la uart


	XUartLite_EnableInterrupt(&RS232);

	XIntc_Enable(&Interrupcion,XPAR_XPS_INTC_0_RS232_INTERRUPT_INTR);

	XIntc_Start(&Interrupcion,XIN_REAL_MODE);


	microblaze_enable_interrupts();
	for(;;){

		XUartLite_Send(&RS232,buffer_tx,strlen(buffer_tx));
		for(i=0;i<=1000000;i++);

	}


    return 0;
}
void RS232_Interrupcion(void *callback){
	XUartLite_DisableInterrupt(&RS232);
	XUartLite_Recv(&RS232, lectura, 1);
	XGpio_DiscreteWrite(&LEDS, 1, lectura[0]);
	XUartLite_ResetFifos(&RS232);
	XUartLite_EnableInterrupt(&RS232);
}

void Ejemplo1(void){
			XGpio_DiscreteWrite(&LEDS,1,0xAA);
			for(i=0;i<=1000000;i++);
			XGpio_DiscreteWrite(&LEDS,1,0x55);
			for(i=0;i<=1000000;i++);
}
