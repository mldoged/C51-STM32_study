#include <REGX52.H>
#include "delay.h"
#include "key.h"
#include "nixie.h"
#include "timer0.h"

sbit Motor=P1^0;

unsigned char Counter,Compare;
unsigned char Speed=0;

void main()
{
	timer0_init();
	while(1)
	{
		if(key()==1)
		{
			Speed++;
			Speed%=4;
			if(Speed==0){Compare=0;}
			if(Speed==1){Compare=50;}
			if(Speed==2){Compare=75;}
			if(Speed==3){Compare=100;}
		}
		
		nixie(1,Speed);
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
		Motor=1;
	}
	else
	{
		Motor=0;	
	}
}