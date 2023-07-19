#include <REGX52.H>
#include <intrins.H>
#include "timer0.h"
#include "key.h"
unsigned char keynum,ledmode;
void main()
{
	P2=0xfe;
	timer0_init();
	while(1)
	{
		keynum=key();
		if(keynum)
		{
			if(keynum==1){ledmode++;if(ledmode>=2)ledmode=0;}
			if(keynum==2)P2_2=~P2_2;
			if(keynum==3)P2_3=~P2_3;
			if(keynum==4)P2_4=~P2_4;
		}
	}
}
void t0_rountine() interrupt 1
{
	static unsigned int t0count;
	TL0 = 0x66;				
	TH0 = 0xFC;	
	t0count++;
	if(t0count>=500)
	{
		t0count=0;
		if(ledmode==0)P2=_crol_(P2,1);
		if(ledmode==1)P2=_cror_(P2,1);
	}
}