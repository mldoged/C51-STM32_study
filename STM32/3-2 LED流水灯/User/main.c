#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//开启GPIOA时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;//初始化端口
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_Out_PP; 
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	while(1)
	{
		GPIO_Write(GPIOA,~0X0001);//0000 0000 0000 0001
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0002);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0004);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0008);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0010);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0020);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0040);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0080);
		Delay_ms(100);
	}
}
