/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author
  * @version V1.0
  * @date    2019-08-04
  * @brief   ledӦ�ú����ӿ�
  ******************************************************************************
  */

#include "Black_USART.h"
#include "Black_DELAY.h"

void USART0_Config(void)
{
    //���ڳ�ʼ��
     P3SEL    |=  BIT3+BIT4 ;                        // P5.6,7 = USCI_A1 TXD/RXD
     UCA0CTL1 |=  UCSWRST;                      // **Put state machine in reset**
     UCA0CTL1 |=  UCSSEL_1;                     // ACLK
     UCA0BR0   =  0x03;                         // 32768Hz 9600 ������Ϊ9600
     UCA0BR1   =  0x00;                             // 32768Hz 9600
     UCA0MCTL |=  UCBRS_3 + UCBRF_0;           // Modulation UCBRSx=1, UCBRFx=0
     UCA0CTL1 &= ~UCSWRST;                   // **Initialize USCI state machine**
     UCA0IE   |=  UCRXIE;                       // Enable USCI_A1 RX interrupt ʹ���ж�
}


void USART1_Config(void)
{
    //���ڳ�ʼ��
     P4SEL    |=  BIT4+BIT5 ;                        // P5.6,7 = USCI_A1 TXD/RXD
     UCA1CTL1 |=  UCSWRST;                      // **Put state machine in reset**
     UCA1CTL1 |=  UCSSEL_1;                     // ACLK
     UCA1BR0   =  0x03;                         // 32768Hz 9600 ������Ϊ9600
     UCA1BR1   =  0x00;                             // 32768Hz 9600
     UCA1MCTL |=  UCBRS_3 + UCBRF_0;           // Modulation UCBRSx=1, UCBRFx=0
     UCA1CTL1 &= ~UCSWRST;                   // **Initialize USCI state machine**
     UCA1IE   |=  UCRXIE;                       // Enable USCI_A1 RX interrupt ʹ���ж�
}

void send0_buf(unsigned char *ptr)    //�����ַ���
{
    while(*ptr != '\0')
    {
        while(!(UCA0IFG & UCTXIFG));
        UCA0TXBUF = *ptr;
        ptr++;
        delay(10);
    }
}
void senf0char(char s)
{
    UCA0TXBUF=s;
    while(!(UCA0IFG&UCTXIFG));
}
void send1_buf(unsigned char *ptr)    //�����ַ���
{
    while(*ptr != '\0')
    {
        while(!(UCA1IFG & UCTXIFG));
        UCA1TXBUF = *ptr;
        ptr++;
        delay(10);
    }
}
void senf1char(char s)
{
    UCA1TXBUF=s;
    while(!(UCA1IFG&UCTXIFG));
}

char A0recive()
{
  while(!(UCA0IFG&UCRXIFG))
    return UCA0RXBUF; 
}
