#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Delay.h"
#include "Timer0.h"
#include "Key.h"

unsigned char Keynum,MODE=0,Timesetselect,TimeSetFlashTag;
unsigned char second,minute;

void TimeShow(void)
{
	DS1302_ReadTime();
	LCD_ShowNum(1,1,DS1302_Time[0],2);
	LCD_ShowNum(1,4,DS1302_Time[1],2);
	LCD_ShowNum(1,7,DS1302_Time[2],2);
	LCD_ShowNum(2,1,DS1302_Time[3],2);
	LCD_ShowNum(2,4,DS1302_Time[4],2);
	LCD_ShowNum(2,7,DS1302_Time[5],2);
}

void TimeSet(void)
{
	if(Keynum==2)
	{
		Timesetselect++;
		Timesetselect%=6;//越位判断
	}
	if(Keynum==3)
	{
		DS1302_Time[Timesetselect]++;
		if(DS1302_Time[0]>99){DS1302_Time[0]=0;}//判断年
		if(DS1302_Time[1]>12){DS1302_Time[1]=1;}//判断月
		
		if(DS1302_Time[1]==1 || DS1302_Time[1]==3 || DS1302_Time[1]==5 || //大月
		   DS1302_Time[1]==7 || DS1302_Time[1]==8 || 
		   DS1302_Time[1]==10 || DS1302_Time[1]==12)//判断日
		{
			if(DS1302_Time[2]>31){DS1302_Time[2]=1;}		
		}
		else if(DS1302_Time[1]==4 || DS1302_Time[1]==6 || 				  //小月
		   DS1302_Time[1]==9 || DS1302_Time[1]==11)//判断日
		{
			if(DS1302_Time[2]>30){DS1302_Time[2]=1;}		
		}
		else if(DS1302_Time[1]==2)
		{
			if(DS1302_Time[0]%4==0)
			{
				if(DS1302_Time[2]>29){DS1302_Time[2]=1;}			
			}
			else
				if(DS1302_Time[2]>28){DS1302_Time[2]=1;}
		}
		
		if(DS1302_Time[3]>23){DS1302_Time[3]=0;}//判断时
		if(DS1302_Time[4]>59){DS1302_Time[4]=0;}//判断分
		if(DS1302_Time[5]>59){DS1302_Time[5]=0;}//判断秒
	}
	if(Keynum==4)
	{
		DS1302_Time[Timesetselect]--;
		if(DS1302_Time[0]<0){DS1302_Time[0]=99;}//判断年
		if(DS1302_Time[1]<1){DS1302_Time[1]=12;}//判断月
		
		if(DS1302_Time[1]==1 || DS1302_Time[1]==3 || DS1302_Time[1]==5 || //大月
		   DS1302_Time[1]==7 || DS1302_Time[1]==8 || 
		   DS1302_Time[1]==10 || DS1302_Time[1]==12)//判断日
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=31;}
			if(DS1302_Time[2]>31){DS1302_Time[2]=1;}	
		}
		else if(DS1302_Time[1]==4 || DS1302_Time[1]==6 || 				  //小月
		   DS1302_Time[1]==9 || DS1302_Time[1]==11)//判断日
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=30;}
			if(DS1302_Time[2]>30){DS1302_Time[2]=1;}
		}
		else if(DS1302_Time[1]==2)
		{
			if(DS1302_Time[0]%4==0)
			{
				if(DS1302_Time[2]<1){DS1302_Time[2]=29;}
				if(DS1302_Time[2]>29){DS1302_Time[2]=1;}
			}
			else
				if(DS1302_Time[2]<1){DS1302_Time[2]=28;}
				if(DS1302_Time[2]>28){DS1302_Time[2]=1;}
		}
		
		if(DS1302_Time[3]<0){DS1302_Time[3]=23;}//判断时
		if(DS1302_Time[4]<0){DS1302_Time[4]=59;}//判断分
		if(DS1302_Time[5]<0){DS1302_Time[5]=59;}//判断秒
	}
	
	if(TimeSetFlashTag==0 && Timesetselect==0){LCD_ShowString(1,1,"  ");}
	else	LCD_ShowNum(1,1,DS1302_Time[0],2);
	if(TimeSetFlashTag==0 && Timesetselect==1){LCD_ShowString(1,4,"  ");}
	else	LCD_ShowNum(1,4,DS1302_Time[1],2);
	if(TimeSetFlashTag==0 && Timesetselect==2){LCD_ShowString(1,7,"  ");}
	else	LCD_ShowNum(1,7,DS1302_Time[2],2);
	if(TimeSetFlashTag==0 && Timesetselect==3){LCD_ShowString(2,1,"  ");}
	else	LCD_ShowNum(2,1,DS1302_Time[3],2);
	if(TimeSetFlashTag==0 && Timesetselect==4){LCD_ShowString(2,4,"  ");}
	else	LCD_ShowNum(2,4,DS1302_Time[4],2);
	if(TimeSetFlashTag==0 && Timesetselect==5){LCD_ShowString(2,7,"  ");}
	else	LCD_ShowNum(2,7,DS1302_Time[5],2);
	
	//LCD_ShowNum(2,10,TimeSetFlashTag,2);//中断闪烁
	
}

void main()
{
	LCD_Init();
	DS1302_Init();
	timer0_init();
	DS1302_SetTime();
	LCD_ShowString(1,1,"  -  -  ");
	LCD_ShowString(2,1,"  :  :  ");	
	while(1)
	{
		Keynum=key();
		if(Keynum==1)
		{
			if(MODE==0)
				MODE=1;
			else if(MODE==1)
			{
				MODE=0;
				DS1302_SetTime();
			}
		}
		switch(MODE)
		{
			case 0:TimeShow();break;
			case 1:TimeSet();break;
		}
		
	}
}

void t0_rountine() interrupt 1
{
	static unsigned int t0count = 0;
	TL0 = 0x66;				
	TH0 = 0xFC;	
	t0count++;
	if(t0count>=500)
	{
		t0count=0;
		TimeSetFlashTag = !TimeSetFlashTag;
	}
}