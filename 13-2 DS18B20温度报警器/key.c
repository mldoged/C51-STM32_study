#include <REGX52.H>
#include "delay.h"

unsigned char Key_KeyNumber=0;

unsigned char key_GetState()
{
	unsigned char keynumber=0;
	if(P3_1==0){keynumber=1;}
	if(P3_0==0){keynumber=2;}
	if(P3_2==0){keynumber=3;}
	if(P3_3==0){keynumber=4;}
	return keynumber;
}

void Key_Loop(void)
{
	static unsigned char NowNumber,BeforeNumber;
	BeforeNumber=NowNumber;
	NowNumber=key_GetState();
	if(BeforeNumber==1 && NowNumber==0)//ËÉ¿ª°´¼ü
	{
		Key_KeyNumber=1;
	}
	if(BeforeNumber==2 && NowNumber==0)
	{
		Key_KeyNumber=2;
	}
	if(BeforeNumber==3 && NowNumber==0)
	{
		Key_KeyNumber=3;
	}
	if(BeforeNumber==4 && NowNumber==0)
	{
		Key_KeyNumber=4;
	}
}

unsigned char key(void)
{
	unsigned char temp;
	temp=Key_KeyNumber;
	Key_KeyNumber=0;
	return temp;
}