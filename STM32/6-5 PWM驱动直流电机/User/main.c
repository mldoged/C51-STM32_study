#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "KEY.h"
//A2Îª¿ØÖÆÐÅºÅ
uint8_t KeyNUm;
int8_t Speed;

int main(void)
{
	OLED_Init();
	Motor_Init();
	Key_Init();
	OLED_ShowString(1,1,"Speed:");
	//OLED_Clear();
	while(1)
	{
		KeyNUm=Key_GetNum();
		if(KeyNUm==1)
		{
			Speed += 20;
			if(Speed>100)
			{
				Speed = 0;
				Delay_ms(100);
				Speed = -100;
			}	
		}
		Motor_SetSpeed(Speed);
		OLED_ShowSignedNum(1,7,Speed,3);
	}
}
