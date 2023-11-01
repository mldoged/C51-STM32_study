#include <REGX52.H>
#include "delay.h"

unsigned char Nixie_Buffer[9]={0,10,10,10,10,10,10,10,10};
unsigned char Nixie_Numnum[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0x40};

void Nixie_SetBuf(unsigned char location,num)//修改Buffer中的值
{
	Nixie_Buffer[location]=num;
}

void Nixie_Scan(unsigned char location,num)//扫描显示
{
	P0=0x00;//消隐
	switch(location)
	{
		case 1:
			P2_4=1;P2_3=1;P2_2=1;break;
		case 2:
			P2_4=1;P2_3=1;P2_2=0;break;
		case 3:
			P2_4=1;P2_3=0;P2_2=1;break;
		case 4:
			P2_4=1;P2_3=0;P2_2=0;break;
		case 5:
			P2_4=0;P2_3=1;P2_2=1;break;
		case 6:
			P2_4=0;P2_3=1;P2_2=0;break;
		case 7:
			P2_4=0;P2_3=0;P2_2=1;break;
		case 8:
			P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0=Nixie_Numnum[num];
}

void Nixie_Loop(void)
{
	static unsigned char i=1;
	Nixie_Scan(i,Nixie_Buffer[i]);
	i++;
	if(i>9){i=1;}
}