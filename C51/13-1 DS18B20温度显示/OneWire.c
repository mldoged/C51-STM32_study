#include <REGX52.H>
#include <INTRINS.H>


sbit OneWire_DQ=P3^7;

unsigned char OneWire_Init(void)
{
	unsigned char AskBit;
	unsigned char i;
	//��������
	OneWire_DQ=1;
	OneWire_DQ=0;
	//�ӳ�500us��������ʼ��
	i = 227;while (--i);
	//�ͷ�����
	OneWire_DQ=1;
	//�ӳ�70us��ʹ�ôӻ���ȡ����
	i = 29;while (--i);
	AskBit=OneWire_DQ;
	//�ӳ�500us
	i = 227;while (--i);
	return AskBit;
}

void OneWire_SendBit(unsigned char Bit)
{
	unsigned char i;
	OneWire_DQ=0;
	//�ӳ�10us
	i = 2;while (--i);
	OneWire_DQ=Bit;
	//�ӳ�50us
	i = 22;while (--i);
	OneWire_DQ=1;
}

unsigned char OneWire_ReceiveBit(void)
{
	unsigned char i;
	unsigned char Bit;
	
	OneWire_DQ=0;
	//�ӳ�6us
	i = 2;while (--i);
	OneWire_DQ=1;
	//�ӳ�6us
	i = 2;while (--i);
	Bit=OneWire_DQ;
	//�ӳ�50us
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
	for(i=0;i<8;i++)//��λ��ǰ���ȳ�
	{
		if(OneWire_ReceiveBit())
		{
			Byte|=(0x01<<i);
		}
	}
	return Byte;
}