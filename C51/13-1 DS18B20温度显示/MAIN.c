#include <REGX52.H>
#include "LCD1602.h"
#include "delay.h"
#include "DS18B20.h"

float T;

void main()
{
	LCD_Init();
	DS18B20_ConvertTempera();
	delay(1000);
	LCD_ShowString(1,1,"Temperature:");
	while(1)
	{
		DS18B20_ConvertTempera();
		T=DS18B20_Read_Tempera();
		if(T<0)
		{
			LCD_ShowChar(2,1,'-');
			T=-T;
		}
		else
		{
			LCD_ShowChar(2,1,'+');
		}
		LCD_ShowNum(2,2,T,3);
		LCD_ShowChar(2,5,'.');
		LCD_ShowNum(2,6,(unsigned long)(T*10000)%10000,4);
		
	}
}
