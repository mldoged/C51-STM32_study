#include <REGX52.H>//在安装目录寻找.h
#include "delay.h"//在项目目录寻找.h
#include "nixie.h"
void main()
{
	while(1)
	{
		nixie(1,1);
		nixie(2,9);
		nixie(3,9);
	}
}