#ifndef __HX711_H
#define __HX711_H

#define CPU_CLOCK       8000000
#define delay_us1(us)    __delay_cycles(CPU_CLOCK/1000000*(us))
#define delay_ms1(ms)    __delay_cycles(CPU_CLOCK/1000*(ms))

#define SCK_L       P4OUT   &= ~BIT0
#define SCK_H       P4OUT   |= BIT0
#define SDA_IN      (P4IN & BIT1)
#define ulong unsigned long
#define uint unsigned int
#define uchar unsigned char
extern unsigned long HX711_Buffer;
extern unsigned long maopia;
extern unsigned int Weight_Shiwu;

void init_hx711port(void);
unsigned long read_hx711_24bit(void);
void get_maopi(void);
unsigned long get_weight(void);
void show_zl(void);
#endif