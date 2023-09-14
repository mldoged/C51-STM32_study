#include <REGX52.H>
#include "delay.h"
//怪谈玩家
#define matrix_led_port P0
sbit SER=P3^4;	
sbit SCK=P3^6;	//SRCLK
sbit RCK=P3^5;	//RCLK


/**
  * @brief  点阵屏初始化
  * @param  
  * @retval 
  */
void MatrixLedInit()
{
	SCK=0;
	RCK=0;
}


/**
  * @brief  74HC595写入一个字节
  * @param  要写入的字节
  * @retval 无
  */
void _74HC595_writebyte(unsigned char byte)
{
	unsigned char i;
	//P2=~byte;
	for(i=0;i<8;i++)
	{
		SER=byte&(0x80>>i);//位赋值，大于0则赋1，等于0赋0
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;

} 


/**
  * @brief  LED点阵屏选择一列显示数据
  * @param  column：选择的列；范围：0-7；0在最左边 
  * @param  da：选择列显示的数据，高位在上，1为亮，0为灭
  * @retval 无
  */
void matrixled_showcolumn(unsigned char column,da)
{
	_74HC595_writebyte(da);
	matrix_led_port=~(0x80>>column);//第column列为低电平
	delay(1);
	matrix_led_port=0xff;//位清零，防残影
}