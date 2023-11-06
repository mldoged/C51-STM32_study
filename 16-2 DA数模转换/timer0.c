#include <REGX52.H>
void timer0_init(void)
{
	//TMOD=0X01;//0000 0001,TMOD?
	TMOD&=0XF0;//
	TMOD|=0X01;
	TF0=0;//TCON
	TR0=1;
	TL0 = 0xA4;				//设置定时初始值100us
	TH0 = 0xFF;				//设置定时初始值
	//TL0=64535%256+1;//0x18
	//TH0=64535/256;//0xfc
	ET0=1;//允许中断
	EA=1;//
	PT0=0;
}

	//TL0 = 0xA4;				//设置定时初始值100us
	//TH0 = 0xFF;	
//定时器中断函数模板
//void t0_rountine() interrupt 1
//{
//	static unsigned int t0count = 0;
//	TL0 = 0xA4;				
//	TH0 = 0xFF;	
//	t0count++;
//	if(t0count>=1000)
//	{
//		t0count=0;
//		P2_0=~P2_0; 
//	}
//}