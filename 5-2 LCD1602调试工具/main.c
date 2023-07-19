#include <REGX52.H>
#include "LCD1602.h"
#include "delay.h"

void main()
{
	int result=0;
	LCD_Init();

//	LCD_ShowChar(1,1,'A');
//	LCD_ShowString(1,3,"hello");
//	LCD_ShowNum(1,9,123,4);
//	LCD_ShowSignedNum(1,14,-66,2);
//	LCD_ShowHexNum(2,1,0xa8,2);
//	LCD_ShowBinNum(2,4,0xaa,8);
	while(1)
	{
		result++;
		LCD_ShowNum(1,1,result,3);
		delay(1000);
	}
}