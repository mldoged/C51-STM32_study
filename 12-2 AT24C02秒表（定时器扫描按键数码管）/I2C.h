#ifndef __I2C_h__
#define __I2C_h__

void I2C_Start(void);
void I2C_Stop(void);
void I2C_SendByte(unsigned char Byte);	
unsigned char I2C_ReceiveByte(void);
void I2C_SendAck(bit AckBit);
bit I2C_ReceiveAck(void);

#endif 