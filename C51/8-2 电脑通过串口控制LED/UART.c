#include <REGX52.H>
/**
  * @brief  串口初始化
  * @param  无
  * @retval 无
  */
void Uart_Init()		//4800bps@11.0592MHz
{
	SCON = 0x50;		//8位数据,可变波特率；打开使能端
	PCON |= 0x80;		//使能波特率倍速位SMOD
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xF4;			//设置定时初始值
	TH1 = 0xF4;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
	EA=1;				//打开中断
	ES=1;				//打开中断
}
/**
  * @brief  串口发送一个字节数据
  * @param  byte 
  * @retval 无
  */
void Uart_sendbyte(unsigned char byte)
{
	SBUF=byte;
	while(TI==0);
	TI=0;
}

//串口中断函数模板
/*
void Uart_routine() interrupt 4
{
	if(RI==1)
	{
		RI=0;
	}
}
*/