/********************************************
*********************************************************/
#include "SR04.h"

/**********  �Ĵ�����ַ   *************/
//P64 SCL P70 SDA
#define	SlaveAddress	0xAE	//IICд��ʱ�ĵ�ַ�ֽ����ݣ�+1Ϊ��ȡ
/*------------------------------------------------------------------*/

//I^Cʱ������ʱ���ã�����μ���оƬ�������ֲ�  6050�Ƽ���С1.3us ���ǻ�����⣬������ʱʵ��1.9us����
void SRDelay2us(void)
{
	u8 i;
	i = 11;		// @24MHZ, 6 + 33 = 39T, 1.625us
	while (--i){_nop();}
}

//**************************************
//I2C��ʼ�ź�
//**************************************
void SRI2C_Start(void)
{
	SRDelay2us();                 //��ʱ
	SRDelay2us();                 //��ʱ
	GPIO_setOutputHighOnPin(GPIO_PORT_P7, GPIO_PIN0);
	//SDA = 1;                    //����������
	GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN4);
	//SCL = 1;                    //����ʱ����
	SRDelay2us();                 //��ʱ
	SRDelay2us();                 //��ʱ
	//SDA = 0;                    //�����½���
	GPIO_setOutputLowOnPin(GPIO_PORT_P7, GPIO_PIN0);
	SRDelay2us();                 //��ʱ
	GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN4);
	//SCL = 0;                    //����ʱ����
	SRDelay2us();                 //��ʱ
}

//**************************************
//I2Cֹͣ�ź�
//**************************************
void SRI2C_Stop(void)
{
    SRDelay2us();                 //��ʱ
    //SDA = 0;                    //����������
    GPIO_setOutputLowOnPin(GPIO_PORT_P7, GPIO_PIN0);
    //SCL = 1;                    //����ʱ����
    GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN4);
	SRDelay2us();                 //��ʱ
    //SDA = 1;                    //����������
    GPIO_setOutputHighOnPin(GPIO_PORT_P7, GPIO_PIN0);
	SRDelay2us();                 //��ʱ
}

//**************************************
//I2C����Ӧ���ź�
//**************************************
uint8_t SRI2C_RecvACK(void)
{
    uint8_t CY;
	//SDA = 1;
	GPIO_setOutputHighOnPin(GPIO_PORT_P7, GPIO_PIN0);
	SRDelay2us();                 //��ʱ
    //SCL = 1;                    //����ʱ����
    GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN4);
    SRDelay2us();                 //��ʱ
    GPIO_setAsInputPin(GPIO_PORT_P7, GPIO_PIN0);
    CY = GPIO_getInputPinValue(GPIO_PORT_P7, GPIO_PIN0);                  //��Ӧ���ź�
    GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN0);
    //SCL = 0;                    //����ʱ����
    GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN4);
    SRDelay2us();                 //��ʱ
    return CY;
}

//**************************************
//��I2C���߷���һ���ֽ�����
//**************************************
void SRI2C_SendByte(u8 dat)
{
    u8 i,CY;
    for (i=0; i<8; i++)         //8λ������
    {
        CY = dat & 0x80;
        dat <<= 1;              //�Ƴ����ݵ����λ
       // SDA = CY;               //�����ݿ�
        if(CY){
            GPIO_setOutputHighOnPin(GPIO_PORT_P7, GPIO_PIN0);
        }else{
            GPIO_setOutputLowOnPin(GPIO_PORT_P7, GPIO_PIN0);
        }
        //SCL = 1;                //����ʱ����
        GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN4);
        SRDelay2us();             //��ʱ
        //SCL = 0;                //����ʱ����
        GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN4);
        SRDelay2us();             //��ʱ
    }
    SRI2C_RecvACK();
}

//**************************************
//��I2C���߽���һ���ֽ�����
//**************************************
u8 SRI2C_RecvByte(void)
{
    u8 i;
    u8 dat = 0;
    //SDA = 1;                    //ʹ���ڲ�����,׼����ȡ����,
    GPIO_setOutputHighOnPin(GPIO_PORT_P7, GPIO_PIN0);
    for (i=0; i<8; i++)         //8λ������
    {
        dat <<= 1;
        //SCL = 1;                //����ʱ����
        GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN4);
        SRDelay2us();             //��ʱ
        GPIO_setAsInputPin(GPIO_PORT_P7, GPIO_PIN0);
        dat |= GPIO_getInputPinValue(GPIO_PORT_P7, GPIO_PIN0);                  //��Ӧ���ź�
        GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN0);
       // dat |= SDA;             //������
        //SCL = 0;                //����ʱ����
        GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN4);
        SRDelay2us();             //��ʱ
    }
    return dat;
}

//**************************************
//��I2C�豸д��һ���ֽ�����
//**************************************
void SRSingle_WriteI2C(u8 REG_Address,u8 REG_data)
{
    SRI2C_Start();                  //��ʼ�ź�
    SRI2C_SendByte(SlaveAddress);   //�����豸��ַ+д�ź�
    //I2C_SendByte(REG_Address);    //�ڲ��Ĵ�����ַ��
    SRI2C_SendByte(REG_data);       //�ڲ��Ĵ������ݣ�
    SRI2C_Stop();                   //����ֹͣ�ź�
}
//**************************************
//��I2C�豸��ȡһ���ֽ�����
//**************************************
/*
u8 Single_ReadI2C(u8 REG_Address)
{
	u8 REG_data;
	I2C_Start();                   //��ʼ�ź�
	I2C_SendByte(SlaveAddress);    //�����豸��ַ+д�ź�
	I2C_SendByte(REG_Address);     //���ʹ洢��Ԫ��ַ����0��ʼ
	I2C_Start();                   //��ʼ�ź�
	I2C_SendByte(SlaveAddress+1);  //�����豸��ַ+���ź�
	REG_data=I2C_RecvByte();       //�����Ĵ�������
	
	SDA = 1;                    //дӦ���ź�
	SCL = 1;                    //����ʱ����
	Delay2us();                 //��ʱ
	SCL = 0;                    //����ʱ����
	Delay2us();                 //��ʱ
	
	I2C_Stop();                    //ֹͣ�ź�
	return REG_data;
}
*/

//**************************************
//��ʼ��SR04
//**************************************
void InitSR04(void)
{
	//P2n_open_drain(0x30);	//P2.4 -- SDA,   P2.5 -- SCL
    GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN0);
    GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN4);
	SRDelay2us();
	SRDelay2us();
	SRDelay2us();
	SRDelay2us();
	SRSingle_WriteI2C(SlaveAddress,0x01);//����һ�β���;
}

void SR04Start(void)
{
    //P2n_open_drain(0x30); //P2.4 -- SDA,   P2.5 -- SCL
    GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN0);
    GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN4);
    SRDelay2us();
    SRDelay2us();
    SRDelay2us();
    SRDelay2us();
    SRSingle_WriteI2C(SlaveAddress,0x01);//����һ�β���;
}

void SR04Read(u8 *buf)
{
	u8	i;
	
	SRI2C_Start();                  //��ʼ�ź�
	//SRI2C_SendByte(SlaveAddress);   //�����豸��ַ+д�ź�
	//SRI2C_SendByte(ACCEL_XOUT_H);    //�ڲ��Ĵ�����ַ��
	//I2C_SendByte(WHO_AM_I);    //�ڲ��Ĵ�����ַ��
	//I2C_Start();                   //��ʼ�ź�
	SRI2C_SendByte(SlaveAddress+1);  //�����豸��ַ+���ź�
	for(i=0; i<2; i++)
	//for(i=0; i<1; i++)
	{
		buf[i] = SRI2C_RecvByte();       //�����Ĵ�������
		//SDA = 0;                    //дӦ���ź�
		GPIO_setOutputLowOnPin(GPIO_PORT_P7, GPIO_PIN0);
		//SCL = 1;                    //����ʱ����
		GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN4);
		SRDelay2us();                 //��ʱ
		//SCL = 0;                    //����ʱ����
		GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN4);
		SRDelay2us();                 //��ʱ
	}
		buf[i] = SRI2C_RecvByte();	//���һ���ֽ�
		//SDA = 1;                    //д��Ӧ���ź�
		GPIO_setOutputHighOnPin(GPIO_PORT_P7, GPIO_PIN0);
		//SCL = 1;                    //����ʱ����
		GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN4);
		SRDelay2us();                 //��ʱ
		//SCL = 0;                    //����ʱ����
		GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN4);
		SRDelay2us();                 //��ʱ
	SRI2C_Stop();                    //ֹͣ�ź�
}

unsigned long SR04Cal(u8 *buf){
    return ((unsigned long)buf[0]*65536+(unsigned long)buf[1]*256+(unsigned long)buf[2])/1000;
}
