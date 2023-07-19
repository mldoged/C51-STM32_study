#include <REGX52.H>
#include "delay.h"
#include "timer0.h"
#include "lcd1602.h"
unsigned char sec=55,min=59,hour=23;
void main() 
{	
	LCD_Init();
	timer0_init();
	LCD_ShowString(1,1,"Clock:");
	LCD_ShowString(2,3,":");
	LCD_ShowString(2,6,":");
	while(1)
	{
		LCD_ShowNum(2,1,hour,2);
		LCD_ShowNum(2,4,min,2);
		LCD_ShowNum(2,7,sec,2);
		
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
		sec++;
		if(sec>=60)
		{
			sec=0;
			min++;
			if(min>=60)
			{
				hour++;
				min=0;
				if(hour>=24)hour=0;
			}
		}
	}
}