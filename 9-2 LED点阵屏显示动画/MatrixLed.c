#include <REGX52.H>
#include "delay.h"
//��̸���
//��ʼ
//9.16
//9.17
//9.20 ����
//9.21 �����ɶ�
//9.27 �����ɶ�
//9.28 ��������ɱ
//9.30 ��������ɱ
//10.2 Ӣ������
//10.5 Ӣ������
//10.17 ��ҹ����
//10.18 ��ҹ����
//10.19 ��ҹ����
//10.20 ��ҹ����
//10.21 ��Ϣ
//10.22 ȥ����
//10.24 ����
#define matrix_led_port P0
sbit SER=P3^4;	
sbit SCK=P3^6;	//SRCLK
sbit RCK=P3^5;	//RCLK
sbit RCK=P3^5;


/**
  * @brief  ��������ʼ��
  * @param  
  * @retval 
  */
void MatrixLedInit()
{
	SCK=0;
	RCK=0;
}


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