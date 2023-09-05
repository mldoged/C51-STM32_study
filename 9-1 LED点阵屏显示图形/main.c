#include <REGX52.H>
#include "delay.h"
#define matrix_led_port P0
sbit SER=P3^4;	
sbit SCK=P3^6;	//SRCLK
sbit RCK=P3^5;	//RCLK

/**
  * @brief  74HC595д��һ���ֽ�
  * @param  Ҫд����ֽ�
  * @retval ��
  */
void _74HC595_writebyte(unsigned char byte)
{
	unsigned char i;
	//P2=~byte;
	for(i=0;i<8;i++)
	{
		SER=byte&(0x80>>i);//λ��ֵ������0��1������0��0
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;

} 

/**
  * @brief  LED������ѡ��һ����ʾ����
  * @param  column��ѡ����У���Χ��0-7��0������� 
  * @param  da��ѡ������ʾ�����ݣ���λ���ϣ�1Ϊ����0Ϊ��
  * @retval ��
  */
void matrixled_showcolumn(unsigned char column,da)
{
	_74HC595_writebyte(da);
	matrix_led_port=~(0x80>>column);//��column��Ϊ�͵�ƽ
	delay(1);
	matrix_led_port=0xff;//λ���㣬����Ӱ
}

void main()
{
	SCK=0;
	RCK=0;
	while(1)
	{
		matrixled_showcolumn(0,0x3c);
		matrixled_showcolumn(1,0x42);
		matrixled_showcolumn(2,0xa9);
		matrixled_showcolumn(3,0x85);
		matrixled_showcolumn(4,0x85);
		matrixled_showcolumn(5,0xa9);
		matrixled_showcolumn(6,0x42);
		matrixled_showcolumn(7,0x3c);
	}
}