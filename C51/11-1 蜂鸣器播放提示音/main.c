#include <REGX52.H>
#include "key.h"
#include "nixie.h"
#include "Buzzer.h"

unsigned char Keynum=0;

void main()
{
	nixie(1,0);
	while(1)
	{
		Keynum=key();
		if(Keynum)
		{
			Buzzer_Time(100);
			nixie(1,Keynum);
		}
	}
}