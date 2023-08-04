#include <REGX52.H>

sbit SER=P3^4;	
sbit SCK=P3^6;	//SRCLK
sbit RCK=P3^5;	//RCLK

void _74HC595_writebyte(unsigned char byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER=byte&(0x80>>i);//位赋值，大于0则赋1，等于0赋0
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;
} 

void main()
{
	P0=0;
	SCK=0;
	RCK=0;
	_74HC595_writebyte(0xaa);
	while(1)
	{
		
	}
}