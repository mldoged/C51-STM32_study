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
