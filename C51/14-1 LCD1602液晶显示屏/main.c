#include <REGX52.H>
#include "LCD1602.h"
#include "delay.h"


void main()
{
	LCD1602_Init();
	LCD1602_ShowChar(1,1,'\'');
	LCD1602_ShowString(1,3,"hs\\");
	LCD1602_ShowNum(1,7,1826,3);
	LCD1602_ShowSignedNum(1,11,1826,4);
	LCD1602_ShowHexNum(2,1,0xA5,2);
	LCD1602_ShowBinNum(2,4,0xA5,8);
	LCD1602_ShowChar(2,13,0xdf);
	LCD1602_ShowChar(2,13,'C');
	LCD1602_ShowString(1,3,"I am too sad>-<");
	while(1)
	{
		LCD1602_WriteCommand(0x18);//ÒÆÆÁÖ¸Áî
		delay(500);
	}
}