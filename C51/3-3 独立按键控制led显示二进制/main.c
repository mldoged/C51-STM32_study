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

void main()
{
	unsigned char lednum=0;
	while(1)
	{
		if(P3_1==0)
		{
			delay(20);
			while(P3_1==0);
			delay(20);
			//1111 1110
			lednum++;
			P2=~lednum;
		}
	}
	
}