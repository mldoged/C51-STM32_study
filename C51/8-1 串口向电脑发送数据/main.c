#include <REGX52.H>//2023.8.3
#include "delay.h"
#include "uart.h"

unsigned char sec=0x01;

void main()
{
	Uart_Init();

	while(1)
	{
		Uart_sendbyte(sec);
		delay(1000); 
		sec++;
	}
}