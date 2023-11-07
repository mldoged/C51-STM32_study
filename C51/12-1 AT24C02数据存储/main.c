#include <REGX52.H>
#include "LCD1602.h"
#include "delay.h"
#include "key.h"
#include "AT24C02.h"

unsigned char keynum;
unsigned int num=65522;

void main()
{
	LCD_Init();	
	LCD_ShowNum(1,1,num,5);//程序开始时就显示数值
	while(1)
	{
		keynum=key();
		if(keynum==1)
		{
			num++;
			LCD_ShowNum(1,1,num,5);
		}
		if(keynum==2)
		{
			num--;
			LCD_ShowNum(1,1,num,5);
		}
		if(keynum==3)
		{
			AT24C02_WriteByte(0,num%256);
			delay(5);
			AT24C02_WriteByte(1,num/256);
			delay(5);
			LCD_ShowString(2,1,"save success");
			delay(1000);
			LCD_ShowString(2,1,"            ");
		}
		if(keynum==4)
		{
			num=AT24C02_ReadByte(0);
			num|=AT24C02_ReadByte(1)<<8;
			LCD_ShowNum(1,1,num,5);
			LCD_ShowString(2,1,"loading success");
			delay(1000);
			LCD_ShowString(2,1,"               ");
		}
	}
}