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
			if(keynum<=10&&count<4)//���S1-S10������������������
			{	
				count++;//�ƴμ�һ
				password*=10;//��������һλ
				password+=keynum%10;//���һλ����
				LCD_ShowNum(2,1,password,4);
			}			
		}
		if(keynum==11)
		{
			if(password==cuspass)
			{
				LCD_ShowString(1,14,"OK ");//��ʾok
				password=0;
				count=0;
				LCD_ShowNum(2,1,password,4);
			}
			else
			{
				LCD_ShowString(1,14,"ERR");//��ʾok
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