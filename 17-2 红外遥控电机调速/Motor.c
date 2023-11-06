#include <REGX52.H>
#include "timer1.h"

unsigned char Counter,Compare;

sbit Motor=P1^0;

void Motor_Init(void)
{
	timer1_init();
}

void Motor_SetSpeed(unsigned char Speed)
{
	Compare=Speed;
}

void t1_rountine() interrupt 3 //100us
{
	TL1 = 0xA4;				
	TH1 = 0xFF;	
	Counter++;//µç»ú
	Counter%=100;
	if(Counter<Compare)
	{
		Motor=1;
	}
	else
	{
		Motor=0;	
	}
}