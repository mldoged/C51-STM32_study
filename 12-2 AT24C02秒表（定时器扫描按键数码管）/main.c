#include <REGX52.H>
#include "timer0.h"
#include "nixie.h"
#include "delay.h"
#include "key.h"
#include "AT24C02.h"

unsigned char keynum;
unsigned char Min,Sec,MiniSec;
unsigned char RunFlag=0;

void Sec_Loop(void)
{
	if(RunFlag)
	{
		MiniSec++;
		if(MiniSec>=100)
		{
			Sec++;
			MiniSec=0;
			if(Sec>=60)
			{
				Min++;
				Sec=0;
				if(Min>=60)
				{
					Min=0;
				}
			}
		}
	}
}

void main()
{
	timer0_init();
	while(1)
	{
		keynum=key();
		if(keynum==1)//开始计时
		{
			RunFlag=!RunFlag; 
		}
		if(keynum==2)//计时清零
		{
			Min=0;
			Sec=0;
			MiniSec=0;
		}
		if(keynum==3)//计时数值写入内存
		{
			AT24C02_WriteByte(0,Min);
			delay(5);
			AT24C02_WriteByte(1,Sec);
			delay(5);
			AT24C02_WriteByte(2,MiniSec);
			delay(5);
		}
		if(keynum==4)//读出内存中计时数值
		{
			Min=AT24C02_ReadByte(0);
			Sec=AT24C02_ReadByte(1);
			MiniSec=AT24C02_ReadByte(2);
		}
		Nixie_SetBuf(1,Min/10);
		Nixie_SetBuf(2,Min%10);
		Nixie_SetBuf(3,11);
		Nixie_SetBuf(4,Sec/10);
		Nixie_SetBuf(5,Sec%10);
		Nixie_SetBuf(6,11);
		Nixie_SetBuf(7,MiniSec/10);
		Nixie_SetBuf(8,MiniSec%10);
	}
}

void t0_rountine() interrupt 1
{
	static unsigned int t0count1 = 0;//按键扫描
	static unsigned int t0count2 = 0;//数码管扫描
	static unsigned int t0count3 = 0;//秒表计时
	TL0 = 0x66;				
	TH0 = 0xFC;	
	t0count1++;
	t0count2++;
	t0count3++;
	if(t0count1>=20)
	{
		t0count1=0;
		Key_Loop();
	}
	if(t0count2>=2)
	{
		t0count2=0;
		Nixie_Loop();
	}
	if(t0count3>=10)
	{
		t0count3=0;
		Sec_Loop();
	}
}