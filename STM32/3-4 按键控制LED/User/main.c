#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "KEY.h"

uint8_t keynum;

int main(void)
{
	LED_Init();
	Key_Init();
	while(1)
	{
		keynum=Key_GetNum();
		if(keynum==1)
		{
			LED1_Turn();
		}	
		if(keynum==2)
		{
			LED2_Turn();
		}
	}
}
