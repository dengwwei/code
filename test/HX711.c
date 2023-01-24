#include "MSP430F5529.h"
#include "HX711.h"
#include "oled.h"
uchar zl[]={'0','0','0','0','\0'};
unsigned long HX711_Buffer=0;
unsigned long maopia=0;
unsigned int Weight_Shiwu=0;
unsigned long Weight_Maopi; /* 毛皮重，上电后就读取出这个变量 */
#define GapValue   407 /* 读取出的HX711为一个寄存器数值单位并不是g，除以这个GapValue值就是换算成g单位 */

/*
 * 初始化HX711端口
 *  3.3V供电
 *  4.0接SCK
 *  4.1接DT
 * */
void init_hx711port(void)
{
    P4DIR |= BIT0; /* 单片机P4.0引脚输出 */
    P4OUT &= ~BIT0; /* 单片机P4.0引脚输出低电平 */

    P4DIR &= ~BIT1; /* 单片机P4.1引脚输入 */
    /* P4REN |= BIT1;   //单片机P4.1引脚输入上拉使能 F149单片机这里没内部上拉 */
    //P4OUT |= BIT1; /* 单片机P4.1引脚输入上拉电阻 */
}

/* 读取HX711内部的数据 */
unsigned long read_hx711_24bit(void)
{
    unsigned long Count = 0;
    unsigned char i;
    SCK_L; /* SCL=0;使能AD（PD_SCL 置低） */
    while ( SDA_IN)
        ;
    /* AD转换未结束则等待，否则开始读取 循环读取24次 */
    for (i = 0; i < 24; i++)
    {
        SCK_H; /* SCL = 1; PD_SCL 置高（发送脉冲） */
        Count = Count << 1; /*下降沿来时变量Count左移一位，右侧补零 */
        delay_us1(2);
        SCK_L; /* SCL=0; PD_SCL 置低 */
        if ( SDA_IN)
            Count++; /* if(SDA) Count++; */
        delay_us1(2);
    }
    SCK_H; /* SCL=1; */
    Count = Count ^ 0x800000; /* 第25个脉冲下降沿来时，转换数据 */
    delay_us1(1);
    SCK_L; /* SCL=0; */
    return (Count);
}

/*
 *
 * 获取毛皮重量
 * 上电初始化时候执行
 *
 */
void get_maopi(void)
{
    delay_ms(100);
    Weight_Maopi = read_hx711_24bit();
    Weight_Maopi = read_hx711_24bit(); /* 多读一次确保稳定 */
}

/* 获取重量 返回g单位的重量 */
unsigned long get_weight(void)
{
    HX711_Buffer = read_hx711_24bit();
    maopia = (ulong) ((float) Weight_Maopi / GapValue); /* 毛皮重量转换成g */
    HX711_Buffer = (ulong) ((float) HX711_Buffer / GapValue); /* 此时称重转换成g */
    if (HX711_Buffer > maopia)
    {
        Weight_Shiwu = HX711_Buffer - maopia; /* 计算实物的实际重量 */
        return (Weight_Shiwu); /* 测量正确返回g单位的重量数值 */
    }
    return (0); /* 称重不符合规范(HX711_Buffer > Weight_Maopi) 返回2 */
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








