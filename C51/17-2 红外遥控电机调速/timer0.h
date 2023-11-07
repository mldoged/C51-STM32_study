#ifndef __TIMER0_H__
#define __TIMER0_H__

void timer0_init(void);
void Time0_SetCounter(unsigned int Value);
unsigned int Time0_GetCounter(void);
void Time0_Run(unsigned char flag);
#endif
