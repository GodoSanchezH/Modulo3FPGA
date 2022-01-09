
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <xparameters.h>
#include <xgpio.h>
#include <xiic.h>


XIic IIC_MMJ;
XIic_Config IIC_Conf;

#define ADDRESS_DAC 0x60
u32 i;
u8 *data_i2c = 0x60;
// retardo por software ***for(i=0;i<=1000000;i++);**
int main() 
{

	XIic_Initialize(&IIC_MMJ,XPAR_GENERIC_IIC_BUS_DEVICE_ID);//inicializamos el periferico i2c



   for(;;){

	 XIic_Start(&IIC_MMJ);//Bit de start // inicia la comunicacion
	 XIic_SetAddress(&IIC_MMJ,XII_ADDR_TO_SEND_TYPE,ADDRESS_DAC);
	 //XIic_MasterSend(&IIC_MMJ,&data_i2c,strlen(&data_i2c));
	 XIic_Stop(&IIC_MMJ);//Bit de stop // finalizamos la comunicacion
	   for(i=0;i<=1000000;i++);
   }

   return 0;
}

