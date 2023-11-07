#include <REGX52.H>

sbit LED=P2^0;

void delay(unsigned int i)
{
	while(i--);
}
void main()
{
	unsigned int T_High,A;
	while(1)
	{
		for(T_High=0;T_High<100;T_High++)
		{
			for(A=0;A<20;A++)
			{
				LED=0;
				delay(T_High);
				LED=1;
				delay(100-T_High);
			}
		}
		for(T_High=100;T_High>0;T_High--)
		{
			for(A=0;A<20;A++)
			{
				LED=0;
				delay(T_High);
				LED=1;
				delay(100-T_High);
			}
		}
	}
}