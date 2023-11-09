#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "CountSensor.h"

int main(void)
{
	OLED_Init();
	OLED_ShowString(1,3,"Hello World");
	//OLED_Clear();
	while(1)
	{
	
		
	}
}
