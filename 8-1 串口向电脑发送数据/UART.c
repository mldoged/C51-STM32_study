#include <REGX52.H>
/**
  * @brief  ���ڳ�ʼ��
  * @param  ��
  * @retval ��
  */
void Uart_Init()		//4800bps@11.0592MHz
{
	SCON = 0x40;		//8λ����,�ɱ䲨����
	PCON |= 0x80;		//ʹ�ܲ����ʱ���λSMOD
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xF4;			//���ö�ʱ��ʼֵ
	TH1 = 0xF4;			//���ö�ʱ����ֵ
	ET1 = 0;			//��ֹ��ʱ���ж�
	TR1 = 1;			//��ʱ��1��ʼ��ʱ
}
/**
  * @brief  ���ڷ���һ���ֽ�����
  * @param  byte 
  * @retval ��
  */
void Uart_sendbyte(unsigned char byte)
{
	SBUF=byte;
	while(TI==0);
	TI=0;
}