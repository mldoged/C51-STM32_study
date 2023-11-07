#include <REGX52.H>

#include "I2C.h"
#define AT24C02_ADDRESS 0XA0

/**
  * @brief  AT24C02д��һ���ֽ�
  * @param  WordAddressҪд���ֽڵĵ�ַ��DataҪд���ֽڵ�����
  * @retval ��
  */
void AT24C02_WriteByte(unsigned char WordAddress,Data)
{
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS); 
	I2C_ReceiveAck();
	I2C_SendByte(WordAddress); 
	I2C_ReceiveAck();
	I2C_SendByte(Data); 
	I2C_ReceiveAck();
	I2C_Stop();
}

/**
  * @brief  AT24C02��ȡһ���ֽ�
  * @param  WordAddressҪ�����ֽڵĵ�ַ
  * @retval ������ַ�ڵ�����
  */
unsigned char AT24C02_ReadByte(unsigned char WordAddress)
{
	unsigned Data;
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS); 
	I2C_ReceiveAck();
	I2C_SendByte(WordAddress); 
	I2C_ReceiveAck();
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS|0x01); 
	I2C_ReceiveAck();
	Data=I2C_ReceiveByte();
	I2C_SendAck(1);
	I2C_Stop();
	return Data;
}