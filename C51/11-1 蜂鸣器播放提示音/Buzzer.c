#include <REGX52.H>
#include <INTRINS.H>//NOP

sbit Buzzer=P2^5;//�������˿�

/**
  * @brief  ������˽����ʱ����
  * @param  ��
  * @retval ��
  */
void Buzzer_Delay500us()		//@11.0592MHz,500us
{
	unsigned char data i;

	_nop_();
	i = 227;
	while (--i);
}

/**
  * @brief  ��������������
  * @param  ms ������ʱ��
  * @retval ��
  */
void Buzzer_Time(unsigned int ms)
{
	unsigned int i;
	for(i=0;i<ms;i++)
	{
		Buzzer=!Buzzer;
		Buzzer_Delay500us();
	}
}
