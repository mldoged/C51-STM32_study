#include <REGX52.H>
#include <INTRINS.H>//NOP

sbit Buzzer=P2^5;//蜂鸣器端口

/**
  * @brief  蜂鸣器私有延时函数
  * @param  无
  * @retval 无
  */
void Buzzer_Delay500us()		//@11.0592MHz,500us
{
	unsigned char data i;

	_nop_();
	i = 227;
	while (--i);
}

/**
  * @brief  蜂鸣器发声函数
  * @param  ms 发声的时长
  * @retval 无
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
