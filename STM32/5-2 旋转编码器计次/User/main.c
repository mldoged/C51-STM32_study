#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.h"
//������A�ڽ�B0��B�ڽ�B1����תOLED��һ����תOLED��һ
int16_t num;

int main(void)
{
	OLED_Init();
	Encoder_Init();
	OLED_ShowString(1,1,"num:");
	//OLED_Clear();
	while(1)
	{
		num = num+Encoder_Get();
		OLED_ShowSignedNum(1,5,num,5);
	}
}
