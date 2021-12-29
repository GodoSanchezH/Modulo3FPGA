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


typedef struct{

	uint8_t Limite;
	uint8_t Contador;
}Modulo3;

typedef enum{
	Reset=0,
	Aumento,
	Escritura,
	Delay
}State;

Modulo3 Fpga_FSM;
State Estados=Reset;

XGpio LEDS,SW;
u32 i,j;
u8 data;
void Ejemplo1(void);
void Ejemplo2(void);
void Ejemplo3(void);
void Ejemplo4(void);
int main()
{

	XGpio_Initialize(&LEDS,XPAR_LEDS_DEVICE_ID);//	Inicializamos Leds
	XGpio_Initialize(&SW,XPAR_DIP_SWITCHES_DEVICE_ID);//Inicializamos SW

	Fpga_FSM.Limite = 0xF;//limite de la cuenta

	for(;;){


		switch(Estados){

		case Reset:
			Fpga_FSM.Contador=0;
			Estados = Aumento;
			break;
		case Aumento:
			Fpga_FSM.Contador++;
			Estados=Delay;
			break;
		case Escritura:
			if(Fpga_FSM.Contador==Fpga_FSM.Limite+1){

				Estados= Reset;
			}else{

				XGpio_DiscreteWrite(&LEDS,1,Fpga_FSM.Contador);
				Estados = Aumento;
			}
			break;
		case Delay:
			for(i=0;i<=1000000;i++);
			Estados=Escritura;
			break;



			}
	}


    return 0;
}
void Ejemplo1(void){
			XGpio_DiscreteWrite(&LEDS,1,0xAA);
			for(i=0;i<=1000000;i++);
			XGpio_DiscreteWrite(&LEDS,1,0x55);
			for(i=0;i<=1000000;i++);
}
void Ejemplo2(void){

	for(i=0;i<=255;i++){
		XGpio_DiscreteWrite(&LEDS,1,i);
		for(j=0;j<=500000;j++);
	}
	for(i=255;i>=0;i--){
		XGpio_DiscreteWrite(&LEDS,1,i);
		for(j=0;j<=500000;j++);
	}


}
void Ejemplo3(void){
	for(i=0;i<=7;i++){
				XGpio_DiscreteWrite(&LEDS,1,pow(2,i));
				for(j=0;j<=1000000;j++);
			}
			for(i=7;i>=0;i--){
				XGpio_DiscreteWrite(&LEDS,1,pow(2,i));
				for(j=0;j<=1000000;j++);
			}

}
void Ejemplo4(void){
	data = XGpio_DiscreteRead(&SW,1);
			XGpio_DiscreteWrite(&LEDS,1,data);
}
