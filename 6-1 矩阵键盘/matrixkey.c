#include <REGX52.H>
#include "delay.h"

/**
  * @brief  矩阵键盘读取按键键码
  * @param  无
  * @retval keynumber:按下按下按键的键码值
  如果按键按下不放，程序会停留在子函数，松手瞬间返回按键键码
没有按键按下时返回0
  */
unsigned char matrixkey()
{
	unsigned char keynumber=0;
	P1=0XFF;
	P1_3=0;
	if(P1_7==0){delay(20);while(P1_7==0);delay(20);keynumber=1;}
	if(P1_6==0){delay(20);while(P1_6==0);delay(20);keynumber=5;}
	if(P1_5==0){delay(20);while(P1_5==0);delay(20);keynumber=9;}
	if(P1_4==0){delay(20);while(P1_4==0);delay(20);keynumber=13;}	
	
	P1=0XFF;
	P1_2=0;
	if(P1_7==0){delay(20);while(P1_7==0);delay(20);keynumber=2;}
	if(P1_6==0){delay(20);while(P1_6==0);delay(20);keynumber=6;}
	if(P1_5==0){delay(20);while(P1_5==0);delay(20);keynumber=10;}
	if(P1_4==0){delay(20);while(P1_4==0);delay(20);keynumber=14;}	
	
	P1=0XFF;
	P1_1=0;
	if(P1_7==0){delay(20);while(P1_7==0);delay(20);keynumber=3;}
	if(P1_6==0){delay(20);while(P1_6==0);delay(20);keynumber=7;}
	if(P1_5==0){delay(20);while(P1_5==0);delay(20);keynumber=11;}
	if(P1_4==0){delay(20);while(P1_4==0);delay(20);keynumber=15;}	
	
	P1=0XFF;
	P1_0=0;
	if(P1_7==0){delay(20);while(P1_7==0);delay(20);keynumber=4;}
	if(P1_6==0){delay(20);while(P1_6==0);delay(20);keynumber=8;}
	if(P1_5==0){delay(20);while(P1_5==0);delay(20);keynumber=12;}
	if(P1_4==0){delay(20);while(P1_4==0);delay(20);keynumber=16;}	
	
	return keynumber;
}