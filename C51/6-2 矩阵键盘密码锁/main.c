#include <REGX52.H>
#include "delay.h"
#include "lcd1602.h"
#include "matrixkey.h"

unsigned char keynum;
unsigned int password,count=0;
unsigned int cuspass=2345;
void main()
{	
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
//		if(keynum)
//			LCD_ShowString(1,14,"   ");
		keynum=matrixkey();
		if(keynum)
		{	
			if(keynum<=10&&count<4)//如果S1-S10按键按下则输入密码
			{	
				count++;//计次加一
				password*=10;//密码左移一位
				password+=keynum%10;//获得一位密码
				LCD_ShowNum(2,1,password,4);
			}			
		}
		if(keynum==11)
		{
			if(password==cuspass)
			{
				LCD_ShowString(1,14,"OK ");//显示ok
				password=0;
				count=0;
				LCD_ShowNum(2,1,password,4);
			}
			else
			{
				LCD_ShowString(1,14,"ERR");//显示ok
				password=0;
				count=0;
				LCD_ShowNum(2,1,password,4);
			}
		}	
		if(keynum==12)
		{
			password=0;
			count=0;
			LCD_ShowNum(2,1,password,4);
		}
	}
}