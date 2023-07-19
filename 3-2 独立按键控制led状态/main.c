#include <REGX52.H>
//°´¼üÏû¶¶
void Delay(unsigned int delay)		//@11.0592MHz
{
	unsigned char data i, j;
	while(delay--)
	{
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
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			P2_1=~P2_1;
		}
	}
	
}