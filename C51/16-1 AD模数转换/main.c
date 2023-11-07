#include <REGX52.H>
#include "LCD1602.h"
#include "delay.h"
#include "XPT2046.h"

unsigned int ADValue;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"ADJ  NTC   RG");
	while(1)
	{
		ADValue=XPT2046_ReadValue(XPT2046_XP8);
		LCD_ShowNum(2,1,ADValue,4);
		ADValue=XPT2046_ReadValue(XPT2046_YP8);
		LCD_ShowNum(2,6,ADValue,3);
		ADValue=XPT2046_ReadValue(XPT2046_VBAT8);
		LCD_ShowNum(2,11,ADValue,3);
		delay(10);
	}
}