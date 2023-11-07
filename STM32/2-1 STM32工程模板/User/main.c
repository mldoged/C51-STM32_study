#include "stm32f10x.h"                  // Device header

int main(void)
{
//	RCC->APB2ENR= 0X00000010;//直接配置寄存器点P13口LED
//	GPIOC->CRH= 0X00300000;
//	GPIOC->ODR= 0X00002000;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//打开时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;//配置寄存器
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	//GPIO_SetBits(GPIOC,GPIO_Pin_13);//置高电平//配置寄存器输出
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);//置低电平
	while(1)
	{
		
	}
}
