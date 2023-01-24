 // PWM波控制程序库
#ifndef __MSP430F5529_PWM_H__
#define __MSP430F5529_PWM_H__

// 包含C标准库
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// 包含C标准库
#include <stdint.h>

// 包含430系统库
#include "msp430f5529.h"                   // MSP430F5529寄存器库
#include <intrinsics.h>                    // MSP430F5529系统函数库

// 定义PWM函数
extern char TimerA0_PWM_Init();
extern void TimerA0_PWM_SetPeriod(unsigned int Period);
extern void TimerA0_PWM_SetDuty(char Channel,unsigned int Duty);
extern void TimerA0_PWM_SetPermill(char Channel,unsigned int Percent);
extern char TimerA2_PWM_Init();
extern void TimerA2_PWM_SetPeriod(unsigned int Period);
extern void TimerA2_PWM_SetDuty(char Channel,unsigned int Duty);
extern void TimerA2_PWM_SetPermill(char Channel,unsigned int Percent);
#endif // __MSP430F5529_PWM_H__