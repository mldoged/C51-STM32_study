#include <REGX52.H>
void timer1_init(void)
{
	//TMOD=0X01;//0000 0001,TMOD?
	TMOD&=0X0F;//
	TMOD|=0X10;
	TF1=0;//TCON
	TR1=1;
	TL1 = 0xA4;				//���ö�ʱ��ʼֵ100us
	TH1 = 0xFF;				//���ö�ʱ��ʼֵ
	//TL0=64535%256+1;//0x18
	//TH0=64535/256;//0xfc
	ET1=1;//�����ж�
	EA=1;//
	PT1=0;
}

	//TL1 = 0xA4;				//���ö�ʱ��ʼֵ100us
	//TH1 = 0xFF;	
//��ʱ���жϺ���ģ��
//void t1_rountine() interrupt 3
//{
//	static unsigned int t1count = 0;
//	TL1 = 0xA4;				
//	TH1 = 0xFF;	
//	t1count++;
//	if(t1count>=1000)
//	{
//		t1count=0;
//		P2_0=~P2_0; 
//	}
//}