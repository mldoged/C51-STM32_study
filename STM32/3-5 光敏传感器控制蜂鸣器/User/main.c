#include "stm32f10x.h"                  // Device header
#include "Buzzer.h"
#include "LightSensor.h"

//光敏传感器DO输出端接PB13，蜂鸣器输入端接PB12，
//当外部亮度低于阈值时光敏传感器输出高电平，单片机上拉输入
//当检测到PB13输入高电平时，蜂鸣器响

int main(void)
{
	LightSensor_Init();
	Buzzer_Init();
	while(1)
	{
		if(LightSensor_Get()==1)
		{
			Buzzer_ON();
		}
		else
			Buzzer_0FF();
	}
}
