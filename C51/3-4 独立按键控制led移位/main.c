#include <REGX52.H>
#include <intrins.h>
char lednum=-1;
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
int main()
{
	while(1)
	{
		if(P3_1==0)
		{
			delay(20);
			while(P3_1==0);
			delay(20);
			lednum++;
			if(lednum>=8)
				lednum=0;
			P2=~(0x01<<lednum);
		}
		
		if(P3_0==0)
		{
			delay(20);
			while(P3_0==0);
			delay(20);
			if(lednum<=0)
				lednum=7; 
			else
				lednum--;
			P2=~(0x01<<lednum);

		}
	}
}