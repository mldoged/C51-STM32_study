#include <REGX52.H>
#include "delay.h"
#include "nixie.h"
#include "Motor.h"
#include "IR.h"

unsigned char Speed,Command;

void main()
{
	Motor_Init();
	IR_Init();
	while(1)
	{
		if(IR_GetDataFlag())
		{
			Command=IR_GetCommand();
			if(Command==0x16){Speed=0;Motor_SetSpeed(0);}
			if(Command==0x0c){Speed=1;Motor_SetSpeed(50);}
			if(Command==0x18){Speed=2;Motor_SetSpeed(75);}
			if(Command==0x5e){Speed=3;Motor_SetSpeed(100);}
		}
		
		nixie(1,Speed);
	}
}

