#include <REGX52.H>
#include "OneWire.h"
#include "LCD1602.h"

#define DS18B20_Skip_ROM 0xCC
#define DS18B20_Convert_Tempera 0x44
#define DS18B20_Read_Scratchpad 0xBE

void DS18B20_ConvertTempera(void)
{
	OneWire_Init();
	OneWire_SendByte(DS18B20_Skip_ROM);
	OneWire_SendByte(DS18B20_Convert_Tempera);	
}

float DS18B20_Read_Tempera(void)
{
	unsigned char TLSB,TMSB;
	int temp;
	float T;
	OneWire_Init();
	OneWire_SendByte(DS18B20_Skip_ROM);
	OneWire_SendByte(DS18B20_Read_Scratchpad);	
	TLSB=OneWire_ReceiveByte();
	TMSB=OneWire_ReceiveByte();
	
//	LCD_ShowBinNum(1,1,TMSB,8);温度数据二进制测试
//	LCD_ShowBinNum(1,9,TLSB,8);	
	
	temp=(TMSB<<8)|TLSB;
	T=temp/16.0;
	return T;
}
