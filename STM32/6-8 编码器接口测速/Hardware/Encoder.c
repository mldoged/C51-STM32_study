#include "stm32f10x.h"                  // Device header

void Encoder_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//使用TIM3的通道一
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_IPU;//输出控制权给片上外设（定时器） 
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;//输入模式下无用
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//TIM_InternalClockConfig(TIM3);//编码器接口会托管时钟	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 65536-1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 1-1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
	
	TIM_ICInitTypeDef TIM_ICInitStructure;
	TIM_ICStructInit(&TIM_ICInitStructure);
	
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
	TIM_ICInitStructure.TIM_ICFilter = 0x0A;
	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInit(TIM3,&TIM_ICInitStructure);//将配置写入通道一
	
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;
	TIM_ICInitStructure.TIM_ICFilter = 0x0A;
	//TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;//下方已配置
	TIM_ICInit(TIM3,&TIM_ICInitStructure);//将配置写入通道二
	
	TIM_EncoderInterfaceConfig(TIM3,TIM_EncoderMode_TI12,
							  TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);
							  
	TIM_Cmd(TIM3,ENABLE);
}

int16_t Encoder_Get(void)
{
	return TIM_GetCounter(TIM3);
}
