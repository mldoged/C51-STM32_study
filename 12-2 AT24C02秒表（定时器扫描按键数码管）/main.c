#include <REGX52.H>
#include "timer0.h"
#include "nixie.h"
#include "delay.h"
#include "key.h"

void main()
{
	timer0_init();
	while(1)
	{
		
	}
}

void t0_rountine() interrupt 1
{
	static unsigned int t0count = 0;
	TL0 = 0x66;				
	TH0 = 0xFC;	
	t0count++;
	if(t0count>=1000)
	{
		t0count=0;
		Key_Loop();
	}
}