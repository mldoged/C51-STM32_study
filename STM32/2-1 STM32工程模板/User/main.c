#include "stm32f10x.h"                  // Device header

int main(void)
{
//	RCC->APB2ENR= 0X00000010;//ֱ�����üĴ�����P13��LED
//	GPIOC->CRH= 0X00300000;
//	GPIOC->ODR= 0X00002000;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//��ʱ��
	
	GPIO_InitTypeDef GPIO_InitStructure;//���üĴ���
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	//GPIO_SetBits(GPIOC,GPIO_Pin_13);//�øߵ�ƽ//���üĴ������
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);//�õ͵�ƽ
	while(1)
	{
		
	}
}
