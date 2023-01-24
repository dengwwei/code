#include "elem.h"
#include "Black_USART.h"
#include "msp430f5529_PWM.h"
ui task=0;
char m='1';
extern int  duty =1000;//pwm
extern int  cycle= 1000;//周期
extern int kop=5;
ui sign=0;
void PWMInit(ui M0,ui M2,ui M3,ui M4,ui M5)
{
  TimerA0_PWM_SetPeriod(M0);
  TimerA2_PWM_SetPeriod(M0);
  TimerA0_PWM_SetDuty(1,M2);
  TimerA0_PWM_SetDuty(2,M3);
  TimerA2_PWM_SetDuty(1,M4);
  TimerA2_PWM_SetDuty(2,M5);
} 


  
void allinit()
{
  P3DIR |= (BIT0+BIT1);
  P2DIR |= BIT2;
  P2DIR |= BIT6;
  P2DIR &= ~BIT1;
    P2REN |= BIT1;
    P2OUT |= BIT1; 
    P6DIR |= BIT1;
    P6OUT |= BIT1;
  TimerA0_PWM_Init();
  TimerA2_PWM_Init();
  OLED_Init();	
  //初始化OLED  
  //LED_Clr();
  USART0_Config();
  OLED_ShowChinese(0,0,2,16);
  OLED_ShowChinese(17,0,3,16);
  OLED_ShowChinese(34,0,6,16);
  OLED_ShowChinese(51,0,7,16);
//  USART1_Config();//openmv
  _EINT();
}

void forward(ui k1,ui k2,ui k3)
{
  R_ZH;
  L_ZH;
  R_FD;
  L_FD;
  PWMInit(k1,k2,k2,k3,k3);
  if(!(P3IN & BIT2)){
  if((P4IN & BIT1)||(P6IN & BIT6))
  {
    PWMInit(k1,k2,k2,k3-200,k3-200);
  }
  if((P4IN & BIT2)||(P2IN & BIT7))
  {
    PWMInit(k1,k2-200,k2-200,k3,k3);
  }
  }
 
}

void TLeft(int p1,int p2,int p3 )
{
  PWMInit(0,0,0,0,0);
  R_ZH;
  L_ZD;
  R_FD;
  L_FH;
  PWMInit(p1,p2,p2,p3,p3);
 
}

void TRight(int p1,int p2,int p3)
{
  R_ZD;
  L_ZH;
  R_FH;
  L_FD;
  PWMInit(p1,p2,p2,p3,p3);
}

void stop()
{
  P6OUT&=~BIT1;
  L_FH;
  L_ZD;
  R_ZD;
  R_FH;
  PWMInit(1000,-300,-300,-300,-300);
  delay_ms(20);
  L_FD;
  L_ZD;
  R_ZD;
  R_FD;
  PWMInit(0,0,0,0,0);
  P6OUT |= BIT1;
}
extern ui count=0;
void start1()
{
  
    if(P4IN & BIT1)
    {
      delay_ms(20);
    if(P4IN & BIT1)
    {
      stop();
      delay_ms(2000);
      ++count;
      TLeft(cycle,duty-360,duty-360);
      delay_ms(5000);
    }
    if(count==4){
          forward(cycle,duty-360,duty-360);
          while((P4IN & BIT1)&&(P4IN & BIT2)){
        stop();
         PWMInit(0,0,0,0,0);
          }
    } 
    }
    else
      forward(cycle,duty-360,duty-360);
  }

void check()
{
  if(P3IN & BIT2)
    forward(cycle,duty-440,duty-440);
  if(P3IN & BIT2)
  {
    if(P4IN & BIT1)
      forward(cycle,duty-440,duty-440);
  }
  if(P3IN & BIT2)
  {
    if(P6IN & BIT6)
      forward(cycle,duty-440,duty-440);
  }
 if(P4IN & BIT1)
   TLeft(cycle,duty-1050,duty-800);
 if(P6IN & BIT6)
    TLeft(cycle,duty-1050,duty-800);
 if(P4IN & BIT2)
   TRight(cycle,duty-800,duty-1050);
 if(P2IN & BIT7)
   TRight(cycle,duty-800,duty-1050);
   if(P4IN & BIT2)
    if(P4IN & BIT1)
    {
      forward(cycle,duty-200,duty-200);
      delay_ms(100);
    }
      if((P4IN & BIT1)&&(P4IN & BIT2)&&(P3IN & BIT2))
      { 
       forward(cycle,duty-200,duty-200);
       delay_ms(150);
        count++;
      }
}
 
void tarck()
{

  
   while(task){
  check();
  if(count>=10)
  {
    if(((P4IN & BIT2)&&(P4IN & BIT1))&&(P3IN & BIT2))
    {
    senf0char('G');
  stop();
  count++;
  task=0;
  
  break;
    }
  }
  }

  
}

void one()
{
  if(!(P2IN & BIT1))
    if(!(P2IN & BIT1))
      {
        count=0;
        senf0char('K');
        task=1;
        tarck();  
        
      }
}



