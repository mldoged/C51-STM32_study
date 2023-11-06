#ifndef __XPT2046_H__
#define __XPT2046_H__

#define XPT2046_XP8 0X9C
#define XPT2046_YP8 0XDC
#define XPT2046_VBAT8 0XAC
#define XPT2046_AUX8 0XEC

#define XPT2046_XP12 0X94
#define XPT2046_YP12 0XD4
#define XPT2046_VBAT12 0XA4
#define XPT2046_AUX12 0XE4


//用户调用函数：
unsigned int XPT2046_ReadValue(unsigned char Command);

#endif
