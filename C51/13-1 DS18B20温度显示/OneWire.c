#include <REGX52.H>
#include <INTRINS.H>


sbit OneWire_DQ=P3^7;

unsigned char OneWire_Init(void)
{
	unsigned char AskBit;
	unsigned char i;
	//拉低总线
	OneWire_DQ=1;
	OneWire_DQ=0;
	//延迟500us，主机初始化
	i = 227;while (--i);
	//释放总线
	OneWire_DQ=1;
	//延迟70us，使得从机读取数据
	i = 29;while (--i);
	AskBit=OneWire_DQ;
	//延迟500us
	i = 227;while (--i);
	return AskBit;
}

void OneWire_SendBit(unsigned char Bit)
{
	unsigned char i;
	OneWire_DQ=0;
	//延迟10us
	i = 2;while (--i);
	OneWire_DQ=Bit;
	//延迟50us
	i = 22;while (--i);
	OneWire_DQ=1;
}

unsigned char OneWire_ReceiveBit(void)
{
	unsigned char i;
	unsigned char Bit;
	
	OneWire_DQ=0;
	//延迟6us
	i = 2;while (--i);
	OneWire_DQ=1;
	//延迟6us
	i = 2;while (--i);
	Bit=OneWire_DQ;
	//延迟50us
	i = 22;while (--i);
	return Bit;
}

void OneWire_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		OneWire_SendBit(Byte&0x01<<i);
	}
}

unsigned char OneWire_ReceiveByte(void)
{
	unsigned char i,Byte=0x00;
	for(i=0;i<8;i++)//低位在前，先出
	{
		if(OneWire_ReceiveBit())
		{
			Byte|=(0x01<<i);
		}
	}
	return Byte;
}