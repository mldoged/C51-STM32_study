#include <REGX52.H>

#define DS1302_Second 0x80
#define DS1302_Minute 0x82
#define DS1302_Hour 0x84
#define DS1302_Date 0x86
#define DS1302_Month 0x88
#define DS1302_Day 0x8a
#define DS1302_Year 0x8c
#define DS1302_WP 0x8e

sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;
char DS1302_Time[]={23,10,30,02,04,18,1};

void DS1302_Init(void)
{
	DS1302_CE=0;
	DS1302_SCLK=0;
}

void DS1302_WriteByte(unsigned char Command,Data)
{
	unsigned char i;
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=1;
		//根据1302芯片手册，确定SCLK变化的最小间隔，来决定是否需要加延迟函数
		DS1302_SCLK=0;
	}
	for(i=0;i<8;i++)
	{
		DS1302_IO=Data&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	DS1302_CE=0;
}

unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i;
	unsigned char Data=0x00;
	Command|=0x01;
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=0;	//先给下降沿，读指令为下降沿读
		DS1302_SCLK=1;
	}
	DS1302_IO=0;
	for(i=0;i<8;i++)
	{
		DS1302_SCLK=1;
		DS1302_SCLK=0;
		if(DS1302_IO)
		{
			Data=Data|(0x01<<i);//先进低位
		}
	}
	DS1302_CE=0;
	DS1302_IO=0;//此处置零解决读出数据闪烁问题，否则全为0
	return Data;
}

void DS1302_SetTime(void)
{
	DS1302_WriteByte(DS1302_WP,0x00);//关闭写保护
	DS1302_WriteByte(DS1302_Year,DS1302_Time[0]/10*16+DS1302_Time[0]%10);//进制转换
	DS1302_WriteByte(DS1302_Month,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
	DS1302_WriteByte(DS1302_Date,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
	DS1302_WriteByte(DS1302_Hour,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
	DS1302_WriteByte(DS1302_Minute,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
	DS1302_WriteByte(DS1302_Second,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
	DS1302_WriteByte(DS1302_Day,DS1302_Time[6]/10*16+DS1302_Time[6]%10);
	DS1302_WriteByte(DS1302_WP,0x00);//打开写保护
}

void DS1302_ReadTime(void)
{
	unsigned char temp;
	temp=DS1302_ReadByte(DS1302_Year);
	DS1302_Time[0]=temp/16*10+temp%16;
	temp=DS1302_ReadByte(DS1302_Month);
	DS1302_Time[1]=temp/16*10+temp%16;
	temp=DS1302_ReadByte(DS1302_Date);
	DS1302_Time[2]=temp/16*10+temp%16;
	temp=DS1302_ReadByte(DS1302_Hour);
	DS1302_Time[3]=temp/16*10+temp%16;
	temp=DS1302_ReadByte(DS1302_Minute);
	DS1302_Time[4]=temp/16*10+temp%16;
	temp=DS1302_ReadByte(DS1302_Second); 
	DS1302_Time[5]=temp/16*10+temp%16;
	//星期范围1-7，可不进制转换
	DS1302_Time[6]=DS1302_ReadByte(DS1302_Day);
}