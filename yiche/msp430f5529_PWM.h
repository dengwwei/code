 // PWM�����Ƴ����
#ifndef __MSP430F5529_PWM_H__
#define __MSP430F5529_PWM_H__

// ����C��׼��
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// ����C��׼��
#include <stdint.h>

// ����430ϵͳ��
#include "msp430f5529.h"                   // MSP430F5529�Ĵ�����
#include <intrinsics.h>                    // MSP430F5529ϵͳ������

// ����PWM����
extern char TimerA0_PWM_Init();
extern void TimerA0_PWM_SetPeriod(unsigned int Period);
extern void TimerA0_PWM_SetDuty(char Channel,unsigned int Duty);
extern void TimerA0_PWM_SetPermill(char Channel,unsigned int Percent);
extern char TimerA2_PWM_Init();
extern void TimerA2_PWM_SetPeriod(unsigned int Period);
extern void TimerA2_PWM_SetDuty(char Channel,unsigned int Duty);
extern void TimerA2_PWM_SetPermill(char Channel,unsigned int Percent);
#endif // __MSP430F5529_PWM_H__