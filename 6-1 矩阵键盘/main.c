#include <REGX52.H>
#include "delay.h"
#include "lcd1602.h"
#include "matricxkey.h"
unsigned char keynum;

void main()
{	
	LCD_Init();
	LCD_ShowString(1,1,"Matrix key");
	while(1)
	{
		keynum=matrixkey();
		if(keynum)
		{
			LCD_ShowNum(2,1,keynum,2);
			
		}
	}
}