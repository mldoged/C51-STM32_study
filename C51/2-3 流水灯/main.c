#include <REGX52.H>
#include <INTRINS.H>
void Delay500ms()		//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
void main()
{
		while(1)
		{
			P2=0xfe;//11111110 fe
			Delay500ms();
			P2=0xfd;//11111101 fd
			Delay500ms();
			P2=0xfb;//11111011 fb
			Delay500ms();
			P2=0xf7;//11110111 f7
			Delay500ms();
			P2=0xef;//11101111 ef
			Delay500ms();
			P2=0xdf;//11011111 df
			Delay500ms();
			P2=0xbf;//10111111 bf
			Delay500ms();
			P2=0x7f;//01111111 7f
			Delay500ms();
		}
}



