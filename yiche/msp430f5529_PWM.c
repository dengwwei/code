// PWM波调用程序
#include "msp430f5529_PWM.h"

/*************************************************************
*函数名称：TimerA0_PWM_Init
*函数作用：TImerA0定时器产生PWM波
*函数例程：TimerA0_PWM_Init('A',1,1,1);
*          选择ACLK时钟  1分频  CCR3 高电平 CCR4 高电平
*注意事项：TA0.3管脚 P1.4     TA0.4管脚P1.5
*************************************************************/
char TimerA0_PWM_Init()
{
    TA0CTL = 0;                  //清除以前设置
    TA0CTL |= MC_1;              //定时器TA设为增计数模式
    P1DIR |= BIT4+BIT5;          // P1.4 P1.5 设置为输出
    P1SEL |= BIT4+BIT5;          // P1.4 P1.5 输出方式设置
    TA0CTL|=TASSEL_2;  //SMCLK
        TA0CCTL3 = OUTMOD_7;     // PWM为高电平输出
       TA0CCTL4 = OUTMOD_7;     // PWM为高电平输出

}

/*************************************************************
*函数名称：TimerA2_PWM_Init
*函数作用：TImerA2定时器产生PWM波
*函数例程：TimerA2_PWM_Init('A',1,1,1);
*          选择ACLK时钟  1分频  CCR3 高电平 CCR4 高电平
*注意事项：TA2.1管脚 P2.4     TA2.2管脚P2.5
*************************************************************/
char TimerA2_PWM_Init()
{
    TA2CTL = 0;                  //清除以前设置
    TA2CTL |= MC_1;              //定时器TA设为增计数模式
    TA2CTL|=TASSEL_2;     //SMCLK
        P2DIR |= BIT4;           // P2.4 设置为输出
        P2SEL |= BIT4;
        P2DIR |= BIT5;           // P2.5 设置为输出
        P2SEL |= BIT5;           // P2.4 输出方式设置
        TA2CCTL1 = OUTMOD_7;     // PWM为高电平输出      case 1:
                   // P2.5 输出方式设置
        TA2CCTL2 = OUTMOD_7;     // PWM为高电平输出
                // 成功返回 K
}

/*************************************************************
*函数名称：TimerA0_PWM_SetPeriod
*函数作用：PWM波周期设置
*函数例程：TimerA0_PWM_SetPeriod(500);
*          设置TA0的PWM波周期为500
*注意事项：
*************************************************************/
void TimerA0_PWM_SetPeriod(unsigned int Period)
{
    TA0CCR0 = Period;
}

/*************************************************************
*函数名称：TimerA2_PWM_SetPeriod
*函数作用：PWM波周期设置
*函数例程：TimerA2_PWM_SetPeriod(500);
*          设置TA2的PWM波周期为500
*注意事项：
*************************************************************/
void TimerA2_PWM_SetPeriod(unsigned int Period)
{
    TA2CCR0 = Period;
}

/*************************************************************
*函数名称：TimerA0_PWM_SetDuty
*函数作用：PWM波占空比设置
*函数例程：TimerA0_PWM_SetDuty(1,200);
*          设置TA0CCR3的占空比为200
*注意事项：占空比不能大于PWM周期设置的数值
*************************************************************/
void TimerA0_PWM_SetDuty(char Channel,unsigned int Duty)
{
    switch(Channel)
    {
        case 1: TA0CCR3=Duty; break;
        case 2: TA0CCR4=Duty; break;
    }
}

/*************************************************************
*函数名称：TimerA2_PWM_SetDuty
*函数作用：PWM波占空比设置
*函数例程：TimerA2_PWM_SetDuty(1,200);
*          设置TA2CCR1的占空比为200
*注意事项：占空比不能大于PWM周期设置的数值
*************************************************************/
void TimerA2_PWM_SetDuty(char Channel,unsigned int Duty)
{
    switch(Channel)
    {
        case 1: TA2CCR1=Duty; break;
        case 2: TA2CCR2=Duty; break;
    }
}

/*************************************************************
*函数名称：TimerA0_PWM_SetPermill
*函数作用：PWM波占空比为千分值
*函数例程：TimerA0_PWM_SetPermill(1,200);
*          设置TA0CCR3的占空比为20.0%
*注意事项：占空比不能大于1000
*************************************************************/
void TimerA0_PWM_SetPermill(char Channel,unsigned int Percent)
{
    unsigned long int Period;
    unsigned int Duty;
    Period = TA0CCR0;
    Duty = Period * Percent / 1000;
    TimerA0_PWM_SetDuty(Channel,Duty);
}

/*************************************************************
*函数名称：TimerA2_PWM_SetPermill
*函数作用：PWM波占空比为千分值
*函数例程：TimerA2_PWM_SetPermill(1,200);
*          设置TA2CCR1的占空比为20.0%
*注意事项：占空比不能大于1000
*************************************************************/
void TimerA2_PWM_SetPermill(char Channel,unsigned int Percent)
{
    unsigned long int Period;
    unsigned int Duty;
    Period = TA2CCR0;
    Duty = Period * Percent / 1000;
    TimerA2_PWM_SetDuty(Channel,Duty);
}

/*
#include "msp430x16x.h"     //430寄存器头文件
#include "TAPwm.h"          //TA PWM输出程序库头文件

void main()
{
    // Stop watchdog timer to prevent time out reset
    WDTCTL = WDTPW + WDTHOLD;
    ClkInit();
   TimerA2_PWM_Init('A',1,1,1);
  TimerA2_PWM_SetPeriod(500);
  TimerA2_PWM_SetDuty(1,200);
  TimerA2_PWM_SetPermill(2,100);
    TAPwmInit('A',1,'P','P');   //将定时器TA初始化成为PWM发生器
                  //时钟源=ACLK ; 无分频;  通道1和通道2均设为高电平模式。
    TAPwmSetPeriod(500);        //通道1/2的PWM方波周期均设为500个时钟周期
    TAPwmSetDuty(1,200);        //1通道 有效200个时钟周期
    TAPwmSetPermill(2,200);     //2通道 20.0%

    LPM0;
}

void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // 关闭看门狗
// get_clk();
P1DIR |= 0x01; // 将P1.0设为输出
TA0CCTL0 = CCIE; // CCR0中断允许
TB0CCR0 = 50000;
TA0CTL = TASSEL_2 + MC_1 + TACLR; // 参考时钟选择SMCLK, 增计数模式, 清除TAR计数器
__bis_SR_register(LPM0_bits + GIE); // 进入LPM0并使能全局中断
}
//TA0中断服务程序
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void)
{
P1OUT ^= 0x01; // 反转P1.0端口状态
}
*/