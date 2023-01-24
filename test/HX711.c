#include "MSP430F5529.h"
#include "HX711.h"
#include "oled.h"
uchar zl[]={'0','0','0','0','\0'};
unsigned long HX711_Buffer=0;
unsigned long maopia=0;
unsigned int Weight_Shiwu=0;
unsigned long Weight_Maopi; /* ëƤ�أ��ϵ��Ͷ�ȡ��������� */
#define GapValue   407 /* ��ȡ����HX711Ϊһ���Ĵ�����ֵ��λ������g���������GapValueֵ���ǻ����g��λ */

/*
 * ��ʼ��HX711�˿�
 *  3.3V����
 *  4.0��SCK
 *  4.1��DT
 * */
void init_hx711port(void)
{
    P4DIR |= BIT0; /* ��Ƭ��P4.0������� */
    P4OUT &= ~BIT0; /* ��Ƭ��P4.0��������͵�ƽ */

    P4DIR &= ~BIT1; /* ��Ƭ��P4.1�������� */
    /* P4REN |= BIT1;   //��Ƭ��P4.1������������ʹ�� F149��Ƭ������û�ڲ����� */
    //P4OUT |= BIT1; /* ��Ƭ��P4.1���������������� */
}

/* ��ȡHX711�ڲ������� */
unsigned long read_hx711_24bit(void)
{
    unsigned long Count = 0;
    unsigned char i;
    SCK_L; /* SCL=0;ʹ��AD��PD_SCL �õͣ� */
    while ( SDA_IN)
        ;
    /* ADת��δ������ȴ�������ʼ��ȡ ѭ����ȡ24�� */
    for (i = 0; i < 24; i++)
    {
        SCK_H; /* SCL = 1; PD_SCL �øߣ��������壩 */
        Count = Count << 1; /*�½�����ʱ����Count����һλ���Ҳಹ�� */
        delay_us1(2);
        SCK_L; /* SCL=0; PD_SCL �õ� */
        if ( SDA_IN)
            Count++; /* if(SDA) Count++; */
        delay_us1(2);
    }
    SCK_H; /* SCL=1; */
    Count = Count ^ 0x800000; /* ��25�������½�����ʱ��ת������ */
    delay_us1(1);
    SCK_L; /* SCL=0; */
    return (Count);
}

/*
 *
 * ��ȡëƤ����
 * �ϵ��ʼ��ʱ��ִ��
 *
 */
void get_maopi(void)
{
    delay_ms(100);
    Weight_Maopi = read_hx711_24bit();
    Weight_Maopi = read_hx711_24bit(); /* ���һ��ȷ���ȶ� */
}

/* ��ȡ���� ����g��λ������ */
unsigned long get_weight(void)
{
    HX711_Buffer = read_hx711_24bit();
    maopia = (ulong) ((float) Weight_Maopi / GapValue); /* ëƤ����ת����g */
    HX711_Buffer = (ulong) ((float) HX711_Buffer / GapValue); /* ��ʱ����ת����g */
    if (HX711_Buffer > maopia)
    {
        Weight_Shiwu = HX711_Buffer - maopia; /* ����ʵ���ʵ������ */
        return (Weight_Shiwu); /* ������ȷ����g��λ��������ֵ */
    }
    return (0); /* ���ز����Ϲ淶(HX711_Buffer > Weight_Maopi) ����2 */
}
void show_zl(void)
{
  zl[0]=(uint)(Weight_Shiwu/1000)+'0';
  zl[1]=(uint)((Weight_Shiwu%1000)/100)+'0';
  zl[2]=(uint)((Weight_Shiwu%100)/10)+'0';
  zl[3]=(uint)(Weight_Shiwu%10)+'0';
  OLED_ShowCHinese(0,0,23);
  OLED_ShowCHinese(0,2,24);
  OLED_ShowString(0,4,zl);
}








