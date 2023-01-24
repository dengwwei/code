#ifndef _ELEM_H_
#define _ELEM_H_

#include "MSP430F5529.h"
#include <intrinsics.h>
#include <stdint.h>				  
#define TRIGGER_PIN BIT0     //P2.0f.
#define ECHO_PIN BIT3  // P1.3  
#define LED_PIN BIT0   // P1.0
#define DISTANCE_THRESHOLD 18  // cm
#define MEASURE_INTERVAL 2048  // ~250 ms
typedef  unsigned int ui;  
typedef unsigned char uc;
#define  R_ZH P3OUT|=BIT1;                  //8.2/3.7ÓÒ±ß
#define  R_FH P2OUT|=BIT6;
#define  L_ZH P2OUT|=BIT2;
#define  L_FH P3OUT|=BIT0;
#define  R_ZD P3OUT&=~BIT1;
#define  R_FD P2OUT&=~BIT6;
#define  L_ZD P2OUT&=~BIT2;
#define  L_FD P3OUT&=~BIT0;
#define CPU_CLOCK       1050000


#define delay_us(us)    __delay_cycles(CPU_CLOCK/1000000*(us))
#define delay_ms(ms)    __delay_cycles(CPU_CLOCK/1000*(ms))
void TLeft(int p1,int p2,int p3 );
void stop();
void triggerMeasurement() ;
void forward(ui k1,ui k2,ui k3);
void PWMInit(ui M0,ui M2,ui M3,ui M4,ui M5);
void check1();
void check2();
void TRight(int p1,int p2,int p3);
void tarck();
void one();
void two();
int ju();
//extern int duty=1000;//pwm
//extern  int cycle= 1000;//ÖÜÆÚ
//extern int kop=5;
#endif
