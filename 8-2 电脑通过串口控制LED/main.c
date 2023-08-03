#include <REGX52.H>//2023.8.3
#include "delay.h"
#include "uart.h"

void main()
{
	Uart_Init();

	while(1)
	{
		;
	}
}

void Uart_routine() interrupt 4
{
	if(RI==1)
	{
		P2=SBUF;
		RI=0;
	}
}