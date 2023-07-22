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
	PCON &= 0x7F;		//�����ʲ�����
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR &= 0xBF;		//��ʱ��ʱ��12Tģʽ
	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xFD;			//���ö�ʱ��ʼֵ
	TH1 = 0xFD;			//���ö�ʱ����ֵ
	ET1 = 0;			//��ֹ��ʱ���ж�
	TR1 = 1;			//��ʱ��1��ʼ��ʱ
}


void main()
{
	while(1)
	{
		
	}
}