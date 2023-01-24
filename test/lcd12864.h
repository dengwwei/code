#ifndef lcd12864_H_
#define lcd12864_H_
#include "msp430f5529.h"
#define uchar unsigned char
#define uint unsigned int

#define rw_out P2DIR|=BIT1
#define rw_h P2OUT|=BIT1
#define rw_l P2OUT&=~BIT1
#define en_out P2DIR|=BIT2
#define en_h P2OUT|=BIT2
#define en_l P2OUT&=~BIT2
//
void PortConfig(void);
uint Strlen(uchar *p);
void WriteBytes(uchar *p);
void SerialWriteData(uchar send);
void SerialWriteCmd(uchar send);
void delay_1ms(void);
void delay_nms(unsigned int n);
extern void init_lcd();
extern void display_12864(uchar hang, uchar lie, uchar *p);
extern void Write_CGRAM(uchar *p,uchar cg,uchar y,uchar x);
#endif