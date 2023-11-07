#include <REGX52.H>

#define LCD1602_DataPort P0
sbit LCD1602_RS=P2^6;
sbit LCD1602_RW=P2^5;
sbit LCD1602_EN=P2^7;

void LCD1602_Delay1ms()		//@11.0592MHz
{
	unsigned char data i, j;
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void LCD1602_WriteCommand(unsigned char Command)
{
	LCD1602_RS=0;
	LCD1602_RW=0;
	LCD1602_DataPort=Command;
	LCD1602_EN=1;
	LCD1602_Delay1ms();//延迟1ms，给指令执行时间
	LCD1602_EN=0; 
	LCD1602_Delay1ms();
}

void LCD1602_WriteData(unsigned char Data)
{
	LCD1602_RS=1;
	LCD1602_RW=0;
	LCD1602_DataPort=Data;
	LCD1602_EN=1;
	LCD1602_Delay1ms();//延迟1ms，给指令执行时间
	LCD1602_EN=0; 
	LCD1602_Delay1ms();
}

void LCD1602_Init(void)
{
	LCD1602_WriteCommand(0x38);
	LCD1602_WriteCommand(0x0c);
	LCD1602_WriteCommand(0x06);
	LCD1602_WriteCommand(0x01);
}

/**
  * @brief  设置光标位置
  * @param  Line:行 colume:列
  * @retval 无
  */
void LCD1602_SetCursor(unsigned char Line,unsigned char column)
{
	if(Line==1)
	{
		LCD1602_WriteCommand(0x80|(column-1));//设置光标位置
	}
	else
		LCD1602_WriteCommand(0x80|(column-1)+0x40);//设置光标位置
}

void LCD1602_ShowChar(unsigned char Line,unsigned char column,unsigned char Char)
{
	LCD1602_SetCursor(Line,column);
	LCD1602_WriteData(Char);
}

void LCD1602_ShowString(unsigned char Line,unsigned char column,unsigned char String[])
{
	unsigned char i;
	LCD1602_SetCursor(Line,column);
	for(i=0;String[i]!='\0';i++)
	{
		LCD1602_WriteData(String[i]);		
	}
}

/**
  * @brief  幂函数
  * @param  x,y
  * @retval 
  */
int LCD1602_Power(int x,int y)
{
	unsigned char i;
	int result=1;
	for(i=0;i<y;i++)
	{
		result=x*result;
	}
	return result;
}

void LCD1602_ShowNum(unsigned char Line,unsigned char column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	LCD1602_SetCursor(Line,column);
	for(i=Length;i>0;i--)
	{
		int temp;
		temp=(Number/LCD1602_Power(10,i-1))%10;
		LCD1602_WriteData(temp+'0');
	}
}

void LCD1602_ShowSignedNum(unsigned char Line,unsigned char column,int Number,unsigned char Length)
{
	unsigned char i;
	unsigned int Number1;
	LCD1602_SetCursor(Line,column);
	if(Number>=0)
	{
		LCD1602_WriteData('+');
		Number1=Number;
	}
	else
	{
		LCD1602_WriteData('-');
		Number1=-Number;
	}
	for(i=Length;i>0;i--)
	{
		int temp;
		temp=(Number1/LCD1602_Power(10,i-1))%10;
		LCD1602_WriteData(temp+'0');
	}
}

void LCD1602_ShowHexNum(unsigned char Line,unsigned char column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	LCD1602_SetCursor(Line,column);
	for(i=Length;i>0;i--)
	{
		int temp;
		temp=(Number/LCD1602_Power(16,i-1))%16;
		if(temp<10)
		{
			LCD1602_WriteData(temp+'0');
		}
		else
		{
			LCD1602_WriteData(temp+'A'-10);
		}
	}
}

void LCD1602_ShowBinNum(unsigned char Line,unsigned char column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	LCD1602_SetCursor(Line,column);
	for(i=Length;i>0;i--)
	{
		int temp;
		temp=(Number/LCD1602_Power(2,i-1))%2;
		LCD1602_WriteData(temp+'0');
	}
}