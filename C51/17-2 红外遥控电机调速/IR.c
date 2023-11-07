#include <REGX52.H>
#include "Int0.h"
#include "timer0.h"

unsigned int IR_Time;
unsigned char IR_Start;

unsigned char IR_Data[4];
unsigned char IR_pData;

unsigned char IR_DataFlag;
unsigned char IR_RepeatFlag;
unsigned char IR_Address;
unsigned char IR_Command;

void IR_Init(void)
{
	Int0_Init();
	timer0_init();
}

unsigned char IR_GetDataFlag(void)
{
	if(IR_DataFlag)
	{
		IR_DataFlag=0;
		return 1;
	}
	return 0;
}

unsigned char IR_GetRepeatFlag(void)
{
	if(IR_RepeatFlag)
	{
		IR_RepeatFlag=0;
		return 1;
	}
	return 0;
}

unsigned char IR_GetAddress(void)
{
	return IR_Address;
}

unsigned char IR_GetCommand(void)
{
	return IR_Command;
}

void Int0_Routine(void) interrupt 0     //下降沿触发
{
	if(IR_Start==0)//IR_Start==0为空闲状态，等待开始或重发
	{
		Time0_SetCounter(0);
		Time0_Run(1);
		IR_Start=1;
	}
	else if(IR_Start==1)//IR_Start==1时搜寻起始信号
	{
		IR_Time=Time0_GetCounter();
		Time0_SetCounter(0);
		if(IR_Time>13500/1.08-500 && IR_Time<13500/1.08+500)//搜寻到开始状态，进入数据发送
		{
			IR_Start=2;
		}
		else if(IR_Time>11250/1.08-500 && IR_Time<11250/1.08+500)//搜寻到重复状态，进入空闲
		{
			Time0_Run(0);
			IR_Start=0;
			IR_RepeatFlag=1;
		}
		else
			IR_Start=1;
	}
	else if(IR_Start==2)
	{
		IR_Time=Time0_GetCounter();
		Time0_SetCounter(0);
		if(IR_Time>1120/1.08-200 && IR_Time<1120/1.08+200)//开始状态
		{
			IR_Data[IR_pData/8]&= ~(0x01<<(IR_pData%8));
			IR_pData++;
		}
		else if(IR_Time>2250/1.08-200 && IR_Time<2250/1.08+200)//开始状态
		{
			IR_Data[IR_pData/8] |= (0x01<<(IR_pData%8));
			IR_pData++;
		}
		else
		{
			IR_pData=0;
			IR_Start=1;
		}
		if(IR_pData>=32)//已搜寻完信号
		{
			IR_pData=0;
			if((IR_Data[0]==~IR_Data[1]) && (IR_Data[2]==~IR_Data[3]))
			{
				IR_Address=IR_Data[0];
				IR_Command=IR_Data[2];
				IR_DataFlag=1;
			}
			Time0_Run(0);
			IR_Start=0;
		}
	}
}