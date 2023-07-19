#include <REGX52.H>
#include <intrins.h>
void delay(unsigned int time)		//@11.0592MHz
{
	unsigned char data i, j;
	while(time--)
	{	
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

unsigned char numnum[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void nixie(unsigned char location,num)
{
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
	P0=numnum[num];
	delay(1);
	P0=0x00;//数码管消影
}

void main()
{
	while(1)
	{
		nixie(1,1);
		nixie(2,9);
		nixie(3,9);
		nixie(4,5);
		nixie(5,0);
		nixie(6,7);
		nixie(7,2);
		nixie(8,6);
	}
}