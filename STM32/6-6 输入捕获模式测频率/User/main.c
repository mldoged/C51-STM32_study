#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"
//A15Êä³ö²¨ÐÎ£¬A6²âÊÔÆµÂÊ
uint8_t i;

int main(void)
{
	OLED_Init();
	PWM_Init();
	IC_Init();
	PWM_SetPrescaler(720-1);//freq= 72M/(PSC+1)/(ARR+1)
	PWM_SetCompare1(50);
	
	OLED_ShowString(1,1,"Freq:00000Hz");
	while(1)
	{
		OLED_ShowNum(1,6,IC_GetFreq(),5);
	}
}
