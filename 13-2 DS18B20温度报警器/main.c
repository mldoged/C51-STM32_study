#include <REGX52.H>
#include "LCD1602.h"
#include "AT24C02.h"
#include "delay.h"
#include "DS18B20.h"
#include "key.h"
#include "timer0.h"

float T,TShow;
char TLow,THigh;
unsigned char keynum;

void main()
{
	THigh=AT24C02_ReadByte(0);
	TLow=AT24C02_ReadByte(1);
	if(THigh>125 || TLow<-55 ||THigh<=TLow)
	{
		THigh=20;
		TLow=10;
	}
	
	LCD_Init();
	timer0_init();
	DS18B20_ConvertTempera();
	delay(1000);
	LCD_ShowString(1,1,"T:");
	LCD_ShowString(2,1,"TH:");
	LCD_ShowString(2,9,"TL:");
	
	LCD_ShowSignedNum(2,3,THigh,3);
	LCD_ShowSignedNum(2,12,TLow,3);
	
	while(1)
	{
		keynum=key();
		//温度读取及显示
		DS18B20_ConvertTempera();
		T=DS18B20_Read_Tempera();
		if(T<0)
		{
			LCD_ShowChar(1,3,'-');
			TShow=-T;
		}
		else
		{
			TShow=T;
			LCD_ShowChar(1,3,'+');
		}	
		LCD_ShowNum(1,4,T,3);
		LCD_ShowChar(1,7,'.');
		LCD_ShowNum(1,8,(unsigned long)(TShow*100)%100,2);
		
		//温度阈值判断与显示
		if(keynum)
		{
			if(keynum==1)
			{
				THigh++;
				if(THigh>125){THigh=125;}
			}
			if(keynum==2)
			{
				THigh--;
				if(THigh<TLow){THigh++;}
			}	
			if(keynum==3)
			{
				TLow++;
				if(TLow>=THigh){TLow--;}
			}	
			if(keynum==4)
			{
				TLow--;
				if(TLow<-55){TLow=-55;}
			}
			LCD_ShowSignedNum(2,3,THigh,3);
			LCD_ShowSignedNum(2,12,TLow,3);
			
			AT24C02_WriteByte(0,THigh);
			delay(5);
			AT24C02_WriteByte(1,TLow);
			delay(5);
		}
		if(T>THigh)        	 {LCD_ShowString(1,12,"OV:H");}
		else if(T<TLow)      {LCD_ShowString(1,12,"OV:L");}
		else		    	 {LCD_ShowString(1,12,"    ");}
	}
}

void t0_rountine() interrupt 1
{
	static unsigned int t0count = 0;
	TL0 = 0x66;				
	TH0 = 0xFC;	
	t0count++;
	if(t0count>=20)
	{
		t0count=0;
		Key_Loop(); 
	}
}