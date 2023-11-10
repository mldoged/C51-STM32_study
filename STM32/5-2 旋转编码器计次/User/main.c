#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.h"
//编码器A口接B0，B口接B1。正转OLED加一，反转OLED减一
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
