// PWM�����ó���
#include "msp430f5529_PWM.h"

/*************************************************************
*�������ƣ�TimerA0_PWM_Init
*�������ã�TImerA0��ʱ������PWM��
*�������̣�TimerA0_PWM_Init('A',1,1,1);
*          ѡ��ACLKʱ��  1��Ƶ  CCR3 �ߵ�ƽ CCR4 �ߵ�ƽ
*ע�����TA0.3�ܽ� P1.4     TA0.4�ܽ�P1.5
*************************************************************/
char TimerA0_PWM_Init()
{
    TA0CTL = 0;                  //�����ǰ����
    TA0CTL |= MC_1;              //��ʱ��TA��Ϊ������ģʽ
    P1DIR |= BIT4+BIT5;          // P1.4 P1.5 ����Ϊ���
    P1SEL |= BIT4+BIT5;          // P1.4 P1.5 �����ʽ����
    TA0CTL|=TASSEL_2;  //SMCLK
        TA0CCTL3 = OUTMOD_7;     // PWMΪ�ߵ�ƽ���
       TA0CCTL4 = OUTMOD_7;     // PWMΪ�ߵ�ƽ���

}

/*************************************************************
*�������ƣ�TimerA2_PWM_Init
*�������ã�TImerA2��ʱ������PWM��
*�������̣�TimerA2_PWM_Init('A',1,1,1);
*          ѡ��ACLKʱ��  1��Ƶ  CCR3 �ߵ�ƽ CCR4 �ߵ�ƽ
*ע�����TA2.1�ܽ� P2.4     TA2.2�ܽ�P2.5
*************************************************************/
char TimerA2_PWM_Init()
{
    TA2CTL = 0;                  //�����ǰ����
    TA2CTL |= MC_1;              //��ʱ��TA��Ϊ������ģʽ
    TA2CTL|=TASSEL_2;     //SMCLK
        P2DIR |= BIT4;           // P2.4 ����Ϊ���
        P2SEL |= BIT4;
        P2DIR |= BIT5;           // P2.5 ����Ϊ���
        P2SEL |= BIT5;           // P2.4 �����ʽ����
        TA2CCTL1 = OUTMOD_7;     // PWMΪ�ߵ�ƽ���      case 1:
                   // P2.5 �����ʽ����
        TA2CCTL2 = OUTMOD_7;     // PWMΪ�ߵ�ƽ���
                // �ɹ����� K
}

/*************************************************************
*�������ƣ�TimerA0_PWM_SetPeriod
*�������ã�PWM����������
*�������̣�TimerA0_PWM_SetPeriod(500);
*          ����TA0��PWM������Ϊ500
*ע�����
*************************************************************/
void TimerA0_PWM_SetPeriod(unsigned int Period)
{
    TA0CCR0 = Period;
}

/*************************************************************
*�������ƣ�TimerA2_PWM_SetPeriod
*�������ã�PWM����������
*�������̣�TimerA2_PWM_SetPeriod(500);
*          ����TA2��PWM������Ϊ500
*ע�����
*************************************************************/
void TimerA2_PWM_SetPeriod(unsigned int Period)
{
    TA2CCR0 = Period;
}

/*************************************************************
*�������ƣ�TimerA0_PWM_SetDuty
*�������ã�PWM��ռ�ձ�����
*�������̣�TimerA0_PWM_SetDuty(1,200);
*          ����TA0CCR3��ռ�ձ�Ϊ200
*ע�����ռ�ձȲ��ܴ���PWM�������õ���ֵ
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
*�������ƣ�TimerA2_PWM_SetDuty
*�������ã�PWM��ռ�ձ�����
*�������̣�TimerA2_PWM_SetDuty(1,200);
*          ����TA2CCR1��ռ�ձ�Ϊ200
*ע�����ռ�ձȲ��ܴ���PWM�������õ���ֵ
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
*�������ƣ�TimerA0_PWM_SetPermill
*�������ã�PWM��ռ�ձ�Ϊǧ��ֵ
*�������̣�TimerA0_PWM_SetPermill(1,200);
*          ����TA0CCR3��ռ�ձ�Ϊ20.0%
*ע�����ռ�ձȲ��ܴ���1000
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
*�������ƣ�TimerA2_PWM_SetPermill
*�������ã�PWM��ռ�ձ�Ϊǧ��ֵ
*�������̣�TimerA2_PWM_SetPermill(1,200);
*          ����TA2CCR1��ռ�ձ�Ϊ20.0%
*ע�����ռ�ձȲ��ܴ���1000
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
#include "msp430x16x.h"     //430�Ĵ���ͷ�ļ�
#include "TAPwm.h"          //TA PWM��������ͷ�ļ�

void main()
{
    // Stop watchdog timer to prevent time out reset
    WDTCTL = WDTPW + WDTHOLD;
    ClkInit();
   TimerA2_PWM_Init('A',1,1,1);
  TimerA2_PWM_SetPeriod(500);
  TimerA2_PWM_SetDuty(1,200);
  TimerA2_PWM_SetPermill(2,100);
    TAPwmInit('A',1,'P','P');   //����ʱ��TA��ʼ����ΪPWM������
                  //ʱ��Դ=ACLK ; �޷�Ƶ;  ͨ��1��ͨ��2����Ϊ�ߵ�ƽģʽ��
    TAPwmSetPeriod(500);        //ͨ��1/2��PWM�������ھ���Ϊ500��ʱ������
    TAPwmSetDuty(1,200);        //1ͨ�� ��Ч200��ʱ������
    TAPwmSetPermill(2,200);     //2ͨ�� 20.0%

    LPM0;
}

void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // �رտ��Ź�
// get_clk();
P1DIR |= 0x01; // ��P1.0��Ϊ���
TA0CCTL0 = CCIE; // CCR0�ж�����
TB0CCR0 = 50000;
TA0CTL = TASSEL_2 + MC_1 + TACLR; // �ο�ʱ��ѡ��SMCLK, ������ģʽ, ���TAR������
__bis_SR_register(LPM0_bits + GIE); // ����LPM0��ʹ��ȫ���ж�
}
//TA0�жϷ������
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void)
{
P1OUT ^= 0x01; // ��תP1.0�˿�״̬
}
*/