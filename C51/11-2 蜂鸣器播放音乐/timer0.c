#include <REGX52.H>
void timer0_init(void)
{
	//TMOD=0X01;//0000 0001,TMOD?
	TMOD&=0XF0;//
	TMOD|=0X01;
	TF0=0;//TCON
	TR0=1;
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	//TL0=64535%256+1;//0x18
	//TH0=64535/256;//0xfc
	ET0=1;//允许中断
	EA=1;//
	PT0=0;
}

//定时器中断函数模板
//void t0_rountine() interrupt 1
//{
//	static unsigned int t0count = 0;
//	TL0 = 0x66;				
//	TH0 = 0xFC;	
//	t0count++;
//	if(t0count>=1000)
//	{
//		t0count=0;
//		//定时后行为
//		P2_0=~P2_0; 
//	}
//}