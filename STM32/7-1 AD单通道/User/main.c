#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"

uint16_t AD_Value;
float Volatge;

int main(void)
{
	OLED_Init();
	AD_Init();
	OLED_ShowString(1,1,"ADValue:");
	OLED_ShowString(2,1,"Volatge:0.00V");
	//OLED_Clear();
	while(1)
	{
		AD_Value = AD_GetValue();
		OLED_ShowNum(1,9,AD_Value,4);
		Volatge = (float)AD_Value/4095*3.3;
		OLED_ShowNum(2,9,Volatge,1);
		OLED_ShowNum(2,11,(uint16_t)(Volatge*100)%100,2);//浮点数不能取余
		Delay_ms(100);
	}
}
