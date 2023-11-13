#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
//#include "Timer.h"
#include "Encoder.h"

//uint16_t num;
int main(void)
{
	OLED_Init();
	//Timer_Init(); 
	Encoder_Init();
	OLED_ShowString(1,1,"CNT:");
	//OLED_Clear();
	while(1)
	{
		OLED_ShowSignedNum(1,7,Encoder_Get(),5);
		
	}
}

//void TIM2_IRQHandler(void)
//{
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update) == SET)
//	{
//		num++;
//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//	}
//}
