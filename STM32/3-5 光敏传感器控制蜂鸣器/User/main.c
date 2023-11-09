#include "stm32f10x.h"                  // Device header
#include "Buzzer.h"
#include "LightSensor.h"

//����������DO����˽�PB13������������˽�PB12��
//���ⲿ���ȵ�����ֵʱ��������������ߵ�ƽ����Ƭ����������
//����⵽PB13����ߵ�ƽʱ����������

int main(void)
{
	LightSensor_Init();
	Buzzer_Init();
	while(1)
	{
		if(LightSensor_Get()==1)
		{
			Buzzer_ON();
		}
		else
			Buzzer_0FF();
	}
}
