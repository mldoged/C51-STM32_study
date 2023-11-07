#include <REGX52.H>
#include "delay.h"
#include "timer0.h"

sbit DA=P2^1;

unsigned char Counter,Compare;
unsigned char i;

void main()
{
	timer0_init();
	while(1)
	{
		for(i=0;i<100;i++)
		{
			Compare=i;
			delay(10);
		}
		for(i=100;i>0;i--)
		{
			Compare=i;
			delay(10);
		}
	}
}

void t0_rountine() interrupt 1 //100us
{
	TL0 = 0xA4;				
	TH0 = 0xFF;	
	Counter++;//µç»ú
	Counter%=100;
	if(Counter<Compare)
	{
		DA=1;
	}
	else
	{
		DA=0;	
	}
}