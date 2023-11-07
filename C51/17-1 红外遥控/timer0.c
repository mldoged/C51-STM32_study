#include <REGX52.H>
void timer0_init(void)
{
	TMOD&=0XF0;
	TMOD|=0X01;
	TF0=0;
	TL0 = 0;				
	TH0 = 0;				
	TR0=0;
}

void Time0_SetCounter(unsigned int Value)
{
	TH0=Value/256;
	TL0=Value%256;
}

unsigned int Time0_GetCounter(void)
{
	return (TH0<<8)|TL0;
}

void Time0_Run(unsigned char flag)
{
	TR0=flag;
}
