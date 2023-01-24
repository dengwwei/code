#include "msp430f5529.h"
#include "HC-SR04.h"
#include "OLED.h"
unsigned int  temp = 0 ,  i = 0, Cycle[2] = {0,0};
unsigned char llong[7] = {0};
float         time = 0,distance = 0,sum = 0;

void delay(unsigned int i)
{
  while(i--);
}
void SZ_Init(void)
{
  P2DIR &= ~BIT0;
  P2SEL |= BIT0;
  TA1CTL = TASSEL_2 + MC_2 + TACLR;
  TA1CCTL1 = CM_1 + SCS + CAP + CCIE;    //UP  上升沿 + 同步捕捉 + 捕捉模式1，比较模式0 + 允许中断
}
void Trig(void)
  {
        P1DIR |= BIT3;
        P1OUT |= BIT3;
        delay(3);
        P1OUT &= ~BIT3;
        delay(3);
  }

#pragma vector = TIMER1_A1_VECTOR
__interrupt void TIMER1_A1_ISR(void)
{
    static int aver = 0;
    int u = 0;
    Cycle[i] = TA1CCR1;
    i++;
    if(i == 1)
    {
      TA1CCTL1 = CM_2 + SCS + CAP + CCIE;   //down  下降沿
    }
//    if(TA1CCTL1&COV==0x0002)// 溢出一次
//    {
//      TA1CCTL1 &=~COV;// 清除 COV
//      time=(65535-Cycle[0] + Cycle[1]) * (0.95234);
//      P1DIR |= BIT0;
//      P1OUT |= BIT0;
//
//    }
    if(i == 2)         // 捕获完成；无溢出；
    {
      aver++;
      temp = abs(Cycle[1] - Cycle[0]);
      time = temp * (0.9524);// us 1/MSCLK;  (1.05MHZ)
      distance =  time / 58 ;
      sum += distance;
      if(aver == 12)
      {
          u = (int)(sum / 0.10);
          SH_juli(u);
 //         OLED_DispStringAt(FONT_ASCII_6X8,0,0,llong);
          OLED_ShowString(0,0,llong),
           u = 0;
          sum = 0;
          aver = 0;
      }
      i = 0;
      temp = 0;
      TA1CCTL1 = CM_1 + SCS + CAP + CCIE; //  up
    }
    TA1CCTL1 &= ~CCIFG;//清楚标志位
}
void SH_juli(int sum)
{
  llong[0] = (int)(sum / 10000) + '0';
  llong[1] = (int)(sum % 10000 / 1000) + '0';
  llong[2] = (int)(sum % 1000 / 100) + '0';
  llong[3] = '.';
  llong[4] = (int)(sum % 100 / 10) + '0';
  llong[5] = (int)(sum % 10) + '0';
}

//void main()
//{
//  WDTCTL = WDTPW + WDTHOLD;
//  SZ_Init();
//  OLED_Init();
//  _EINT();
//  while(1)
//  {
//    Trig();
//  }
//}