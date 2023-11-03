#ifndef ___LCD1602_H__
#define ___LCD1602_H__

void LCD1602_Init(void);
void LCD1602_WriteCommand(unsigned char Command);
void LCD1602_ShowChar(unsigned char Line,unsigned char column,char Char);
void LCD1602_ShowString(unsigned char Line,unsigned char column,unsigned char String[]);
void LCD1602_ShowNum(unsigned char Line,unsigned char column,unsigned int Number,unsigned char Length);
void LCD1602_ShowSignedNum(unsigned char Line,unsigned char column,int Number,unsigned char Length);
void LCD1602_ShowHexNum(unsigned char Line,unsigned char column,unsigned int Number,unsigned char Length);
void LCD1602_ShowBinNum(unsigned char Line,unsigned char column,unsigned int Number,unsigned char Length);


#endif
