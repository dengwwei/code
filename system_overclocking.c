

// ����430ϵͳ��
#include "msp430f5529.h"                   // MSP430F5529�Ĵ�����

// ��Ƶ��ʼ������ ��������ָ����Ƶ��
// ���۲����� 1~ 40+ ������ ���鲻Ҫ����45  ���������ܻ�Ҫ��������оƬ���ʣ�������
//ʵ��ʹ���н����������5  ������С��5�Ժ�ᵼ��Ƶ�ʿ���3.5MHz��ԭ��δ֪
/**********************************************
* @�������ƣ�System_overclocking
* @�������ܣ���Ƶ��ʼ������ ��������ָ����Ƶ��
* @��ڲ�����Fre  Ҫ���õ�Ƶ��
*           ���۲����� 1~ 40+ ������ ���鲻Ҫ����45
*           (�������ܻ�Ҫ��������оƬ���ʣ�����)
* @���ڲ�������
* @����˵����ʵ��ʹ���н����������5
*           ������С��5�Ժ�ᵼ��Ƶ�ʿ���3.5MHz
*           ԭ��δ֪
***********************************************/
void System_overclocking(unsigned char Fre)
{
  P5SEL |= BIT2|BIT3|BIT4|BIT5;//�����ⲿ����ʱ��

  UCSCTL6 |= XCAP_3|XT1OFF;          // XT1 ��� ����
  UCSCTL6 |= XT2DRIVE_0 |XT2OFF;     // XT2 ��� ����
  //�������������ĵ�ѹ���ֵĴ���
  PMMCTL0_H = 0xA5;                                         //��PMM��Դ����
  SVSMLCTL |= SVSMLRRL_1 + SVMLE;                            //����SVML��ѹ
  PMMCTL0 =  PMMPW + PMMCOREV_3;                             //�����ں˵�ѹ
  while((PMMIFG & SVSMLDLYIFG ) == 0);                       //�ȴ��������
  PMMIFG &= ~(SVMLVLRIFG + SVMLIFG + SVSMLDLYIFG);
  if((PMMIFG & SVMLIFG) == 1)                                //�ж��ں˵�ѹ�Ƿ�������VSVML
    while((PMMIFG & SVMLVLRIFG) == 0);                    //���û�еȴ�
  SVSMLCTL &= ~SVMLE;                                        //�ص�SVMLģ��
  PMMCTL0_H = 0X00;

  __bis_SR_register(SCG0);                 //���﷨Ϊ�̶���ʽ����Ϊ�������ڵı�����λ��SCG0��ϵͳ����ģʽ�йأ���ʱ MCLK ��ͣ����
  UCSCTL0 = 0;                             //�����㣬FLL ����ʱ���üĴ���ϵͳ���Զ����ã����ù�
  UCSCTL6 = (UCSCTL6&(~(XT2OFF|XT1OFF))|XCAP_3|XT2DRIVE_0);
  UCSCTL3 = (5<<4)|(2<<0);                 // ѡ�� XTAL2 ��ʱ���ź���Ϊ�ο��ź� ���ҷ�Ƶ��1MHz
  if(Fre < 5)
    UCSCTL1 = DCORSEL_2;
  else if(Fre<15)
    UCSCTL1 = DCORSEL_4;
  else
    UCSCTL1 = DCORSEL_7;
  UCSCTL2 = (Fre-1);
  __bic_SR_register(SCG0);
  __delay_cycles(782000);
  while (SFRIFG1 & OFIFG) {                               // Check OFIFG fault flag
    UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);           // Clear OSC flaut Flags
    SFRIFG1 &= ~OFIFG;                                    // Clear OFIFG fault flag
  }
  UCSCTL4 = UCSCTL4&(~(SELS_7|SELM_7))|SELS_3|SELM_3;

//  P2DIR |= BIT2;  // ����P2.2Ϊ���ģʽ
//  P2SEL |= BIT2;  // ���ܸ���:SMCLK��� ����ϵͳ��ʱ�ӣ�
//  P7DIR |= BIT7;  // ����P7.7Ϊ���ģʽ
//  P7SEL |= BIT7;  // ���ܸ���:MCLK���    ����ϵͳʱ�ӣ�
  //P1DIR |= BIT0;  // ����P1.0Ϊ���ģʽ
}



