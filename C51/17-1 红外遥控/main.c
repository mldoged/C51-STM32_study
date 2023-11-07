#include <REGX52.H>
#include "LCD1602.h"
#include "delay.h"
#include "IR.h"

unsigned char Num;
unsigned char Address;
unsigned char Command;
unsigned char Num;

void main()
{
	LCD_Init();
	IR_Init();
	LCD_ShowString(1,1,"ADD  COM  NUM");
	LCD_ShowString(2,1,"00   00   000");
	while(1)
	{
		if(IR_GetDataFlag() || IR_GetRepeatFlag())
		{
			Address=IR_GetAddress();
			Command=IR_GetCommand();
			
			LCD_ShowHexNum(2,1,Address,2);
			LCD_ShowHexNum(2,6,Command,2);
			
			if(Command==0x18)//2
			{
				Num--;
			}
			else if(Command==0x5E)//3
			{
				Num++;
			}
			LCD_ShowHexNum(2,11,Num,3);
		}
	}
}


