#include "msp430f5529.h"
#include "keyboard.h"
#include "oled.h"
#include "bmp.h"
void keyboard_init()
{

    //设置行管脚为输入

    P3DIR &= ~BIT5; //P3.5端口设为输入
    P3REN |= BIT5;  //使3.5能上拉/下拉电阻   
    P3OUT &=~ BIT5;  //置P3.5为下拉电阻模式
    P3SEL &= ~BIT5; //P3.5为I/O接口
    
    P6DIR &= ~BIT5; //P6.4端口设为输入
    P6REN |= BIT5;  //使P6.4能上拉/下拉电阻
    P6OUT &=~ BIT5;  //置P6.4为下拉电阻模式
    P6SEL &=~ BIT5; //P6.4为I/O接口
    
    P6DIR &= ~BIT6; //P3.6端口设为输入
    P6REN |= BIT6;  //使P3.6能上拉/下拉电阻
    P6OUT &=~ BIT6;  //置P3.6为下拉电阻模式
    P6SEL &= ~BIT6; //P3.6为I/O接口
    
    P7DIR &= ~BIT0; //P7.0端口设为输入
    P7REN |= BIT0;  //使P7.0能上拉/下拉电阻
    P7OUT &=~ BIT0;  //置P7.0为下拉电阻模式
    P7SEL &= ~BIT0; //P7.0为I/O接口

    //设置列管脚为输出
    P3DIR |= BIT0+BIT1+BIT2+BIT7; //P3.7,2,1,0端口设为输出
    P3OUT &=~(BIT0+BIT1+BIT2+BIT7);

}

void scanKey()
{
    //扫描列
    char key_value=0;
    unsigned char state=0;
    do{
        key_value=0;
        if(state==0){

            P3OUT |= BIT0;
            P3OUT &=~ (BIT1+BIT2+BIT7);

        }else if(state==1){

            P3OUT |= BIT1;
            P3OUT &=~ (BIT0+BIT2+BIT7);

        }else if(state==2){

            P3OUT |= BIT2;
            P3OUT &=~ (BIT0+BIT1+BIT7);

        }else if(state==3){

            P3OUT |= BIT7;
            P3OUT &=~ (BIT0+BIT1+BIT2);

        }



        if(++state==4) state=0;


        if(P3OUT & BIT0)
            key_value = BIT4;

        if(P3OUT & BIT1)
            key_value = BIT5;

        if(P3OUT & BIT2)
            key_value = BIT6;

        if(P3OUT & BIT7)
            key_value = BIT7;


        if(P3IN & BIT5) key_value |= BIT0;
        else key_value &=~ BIT0;

        if(P6IN & BIT5) key_value |= BIT1;
        else key_value &=~ BIT1;

        if(P6IN & BIT6) key_value |= BIT2;
        else key_value &=~ BIT2;

        if(P7IN & BIT0) key_value |= BIT3;
        else key_value &=~ BIT3;
    }
    
    while((key_value&0x0f)==0);//直到有行被按下

    switch(key_value){//返回按下的字符
        case 17:   OLED_ShowCHinese(0,0,0);break;
        case 18:   OLED_ShowCHinese(18,0,1);break;
        case 20:   OLED_ShowCHinese(36,0,2);break;
        case 24:   OLED_ShowCHinese(54,0,3);break;
        case 33:  OLED_ShowCHinese(72,0,4);break;
        case 34:  OLED_ShowCHinese(90,0,5);break;
        case 36:  OLED_ShowCHinese(108,0,6);break;
        case 40: OLED_ShowCHinese(0,2,7);break;
        case 65: OLED_ShowCHinese(18,2,8);break;
        case 66:  OLED_ShowCHinese(36,2,9);break;
        case 68:  OLED_ShowCHinese(54,2,10);break;
        case 72:  OLED_ShowCHinese(72,2,11);break;
        case 129: OLED_ShowCHinese(90,2,12);break;
        case 130: OLED_ShowCHinese(108,2,13);break;
        case 132: OLED_ShowString(0,6,"hello world");break;
        case 136: OLED_Clear();;break;
        default: OLED_ShowCHinese(0,4,14);break;
    }
}

//char scanKey(){
//    //扫描列
//    char key_value=0;
//    unsigned char state=0;
//    do{
//        key_value=0;
//        if(state==0){
//
//            P6OUT |= BIT0;
//            P6OUT &=~ (BIT1+BIT2+BIT3);
//
//        }else if(state==1){
//
//            P6OUT |= BIT1;
//            P6OUT &=~ (BIT0+BIT2+BIT3);
//
//        }else if(state==2){
//
//            P6OUT |= BIT2;
//            P6OUT &=~ (BIT0+BIT1+BIT3);
//
//        }else if(state==3){
//
//            P6OUT |= BIT3;
//            P6OUT &=~ (BIT0+BIT1+BIT2);
//
//        }
//
//
//
//        if(++state==4) state=0;
//
//
//        if(P6OUT & BIT0)
//            key_value = BIT4;
//
//        if(P6OUT & BIT1)
//            key_value = BIT5;
//
//        if(P6OUT & BIT2)
//            key_value = BIT6;
//
//        if(P6OUT & BIT3)
//            key_value = BIT7;
//
//
//        if(P3IN & BIT5) key_value |= BIT0;
//        else key_value &=~ BIT0;
//
//        if(P3IN & BIT6) key_value |= BIT1;
//        else key_value &=~ BIT1;
//
//        if(P7IN & BIT0) key_value |= BIT2;
//        else key_value &=~ BIT2;
//
//        if(P6IN & BIT4) key_value |= BIT3;
//        else key_value &=~ BIT3;
//
//
//
//    }while((key_value&0x0f)==0);//直到有行被按下
//
//    switch(key_value){//返回按下的字符
//        case 129: return '1';
//        case 65: return '4';
//        case 33: return '7';
//        case 17: return '*';
//        case 130: return '2';
//        case 66: return '5';
//        case 34: return '8';
//        case 18: return '0';
//        case 132: return '3';
//        case 68: return '6';
//        case 36: return '9';
//        case 20: return '#';
//        case 136: return 'A';
//        case 72: return 'B';
//        case 40: return 'C';
//        case 24: return 'D';
//        default: return 0;
//    }
//}

