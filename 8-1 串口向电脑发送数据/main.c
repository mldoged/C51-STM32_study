#include <REGX52.H>
#include "delay.h"

void Uart_Init()
{
	SCON=0X40;
	PCON=0;
	TMOD &= 0X0F;
	TMOD |= 0X20;
	TL1 = 0X18;
	TH1 = OXFC;
	TF1 = 0;
	TR1 = 1;
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}

void UartInit(void)		//9600bps@11.0592MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	AUXR &= 0xBF;		//定时器时钟12T模式
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xFD;			//设置定时初始值
	TH1 = 0xFD;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
}


void main()
{
	while(1)
	{
		
	}
}