#include <REGX52.H>

void Int0_Init()
{	
	IT0=1;//下降沿触发为1，低电平触发为0
	IE0=0;
	EX0=1;
	PX0=1;
	EA=1;
}

//void Int0_Routine(void) interrupt 0
//{
//	number++;
//}