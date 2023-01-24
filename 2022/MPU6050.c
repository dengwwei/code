/********************************************
*********************************************************/
#include "MPU6050.h"

/**********  �Ĵ�����ַ   *************/
#define	SMPLRT_DIV		0x19	//�����ǲ����ʣ�����ֵ��0x07(125Hz)
#define	CONFIG			0x1A	//��ͨ�˲�Ƶ�ʣ�����ֵ��0x06(5Hz)
#define	GYRO_CONFIG		0x1B	//�������Լ켰������Χ������ֵ��0x18(���Լ죬2000deg/s)
#define	ACCEL_CONFIG	0x1C	//���ټ��Լ졢������Χ����ͨ�˲�Ƶ�ʣ�����ֵ��0x01(���Լ죬2G��5Hz)
#define	ACCEL_XOUT_H	0x3B
#define	ACCEL_XOUT_L	0x3C
#define	ACCEL_YOUT_H	0x3D
#define	ACCEL_YOUT_L	0x3E
#define	ACCEL_ZOUT_H	0x3F
#define	ACCEL_ZOUT_L	0x40
#define	TEMP_OUT_H		0x41
#define	TEMP_OUT_L		0x42
#define	GYRO_XOUT_H		0x43
#define	GYRO_XOUT_L		0x44
#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46
#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48
#define	PWR_MGMT_1		0x6B	//��Դ��������ֵ��0x00(��������)
#define	WHO_AM_I		  0x75	//IIC��ַ�Ĵ���(Ĭ����ֵ0x68��ֻ��)
#define	SlaveAddress	0xD0	//IICд��ʱ�ĵ�ַ�ֽ����ݣ�+1Ϊ��ȡ
#define IICSPEED      0x24
/*------------------------------------------------------------------*/

//I^Cʱ������ʱ���ã�����μ���оƬ�������ֲ�  6050�Ƽ���С1.3us ���ǻ�����⣬������ʱʵ��1.9us����
void Delay2us(void)
{
	u8 i;
	i = 11;		// @24MHZ, 6 + 33 = 39T, 1.625us
	while (--i){_nop();}
}

//**************************************
//I2C��ʼ�ź�
//**************************************
void I2C_Start(void)
{
	Delay2us();                 //��ʱ
	Delay2us();                 //��ʱ
	GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN2);
	//SDA = 1;                    //����������
	GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN1);
	//SCL = 1;                    //����ʱ����
	Delay2us();                 //��ʱ
	Delay2us();                 //��ʱ
	//SDA = 0;                    //�����½���
	GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN2);
	Delay2us();                 //��ʱ
	GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN1);
	//SCL = 0;                    //����ʱ����
	Delay2us();                 //��ʱ
}

//**************************************
//I2Cֹͣ�ź�
//**************************************
void I2C_Stop(void)
{
    Delay2us();                 //��ʱ
    //SDA = 0;                    //����������
    GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN2);
    //SCL = 1;                    //����ʱ����
    GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN1);
	Delay2us();                 //��ʱ
    //SDA = 1;                    //����������
    GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN2);
	Delay2us();                 //��ʱ
}

//**************************************
//I2C����Ӧ���ź�
//**************************************
uint8_t I2C_RecvACK(void)
{
    uint8_t CY;
	//SDA = 1;
	GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN2);
	Delay2us();                 //��ʱ
    //SCL = 1;                    //����ʱ����
    GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN1);
    Delay2us();                 //��ʱ
    GPIO_setAsInputPin(GPIO_PORT_P4, GPIO_PIN2);
    CY = GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN2);                  //��Ӧ���ź�
    GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN2);
    //SCL = 0;                    //����ʱ����
    GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN1);
    Delay2us();                 //��ʱ
    return CY;
}

//**************************************
//��I2C���߷���һ���ֽ�����
//**************************************
void I2C_SendByte(u8 dat)
{
    u8 i,CY;
    for (i=0; i<8; i++)         //8λ������
    {
        CY = dat & 0x80;
        dat <<= 1;              //�Ƴ����ݵ����λ
       // SDA = CY;               //�����ݿ�
        if(CY){
            GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN2);
        }else{
            GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN2);
        }
        //SCL = 1;                //����ʱ����
        GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN1);
        Delay2us();             //��ʱ
        //SCL = 0;                //����ʱ����
        GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN1);
        Delay2us();             //��ʱ
    }
    I2C_RecvACK();
}

//**************************************
//��I2C���߽���һ���ֽ�����
//**************************************
u8 I2C_RecvByte(void)
{
    u8 i;
    u8 dat = 0;
    //SDA = 1;                    //ʹ���ڲ�����,׼����ȡ����,
    GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN2);
    for (i=0; i<8; i++)         //8λ������
    {
        dat <<= 1;
        //SCL = 1;                //����ʱ����
        GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN1);
        Delay2us();             //��ʱ
        GPIO_setAsInputPin(GPIO_PORT_P4, GPIO_PIN2);
        dat |= GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN2);                  //��Ӧ���ź�
        GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN2);
       // dat |= SDA;             //������
        //SCL = 0;                //����ʱ����
        GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN1);
        Delay2us();             //��ʱ
    }
    return dat;
}

//**************************************
//��I2C�豸д��һ���ֽ�����
//**************************************
void Single_WriteI2C(u8 REG_Address,u8 REG_data)
{
    I2C_Start();                  //��ʼ�ź�
    I2C_SendByte(SlaveAddress);   //�����豸��ַ+д�ź�
    I2C_SendByte(REG_Address);    //�ڲ��Ĵ�����ַ��
    I2C_SendByte(REG_data);       //�ڲ��Ĵ������ݣ�
    I2C_Stop();                   //����ֹͣ�ź�
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
//��ʼ��MPU6050
//**************************************
void InitMPU6050(void)
{
	//P2n_open_drain(0x30);	//P2.4 -- SDA,   P2.5 -- SCL
    GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN1+GPIO_PIN2);
	Delay2us();
	Delay2us();
	Delay2us();
	Delay2us();

	Single_WriteI2C(PWR_MGMT_1, 0x00);	//�������״̬
	Single_WriteI2C(SMPLRT_DIV, 0x07);  //������125hz
	Single_WriteI2C(CONFIG, 0x04);      //21HZ�˲� ��ʱA8.5ms G8.3ms  �˴�ȡֵӦ�൱ע�⣬��ʱ��ϵͳ�������Ϊ��
	Single_WriteI2C(GYRO_CONFIG, 0x08); //������500��/S 65.5LSB/g
	Single_WriteI2C(ACCEL_CONFIG, 0x08);//���ٶ�+-4g  8192LSB/g
}

void Read_MPU6050(u8 *buf)
{
	u8	i;
	
	I2C_Start();                  //��ʼ�ź�
	I2C_SendByte(SlaveAddress);   //�����豸��ַ+д�ź�
	I2C_SendByte(ACCEL_XOUT_H);    //�ڲ��Ĵ�����ַ��
	//I2C_SendByte(WHO_AM_I);    //�ڲ��Ĵ�����ַ��
	I2C_Start();                   //��ʼ�ź�
	I2C_SendByte(SlaveAddress+1);  //�����豸��ַ+���ź�
	for(i=0; i<13; i++)
	//for(i=0; i<1; i++)
	{
		buf[i] = I2C_RecvByte();       //�����Ĵ�������
		//SDA = 0;                    //дӦ���ź�
		GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN2);
		//SCL = 1;                    //����ʱ����
		GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN1);
		Delay2us();                 //��ʱ
		//SCL = 0;                    //����ʱ����
		GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN1);
		Delay2us();                 //��ʱ
	}
		buf[i] = I2C_RecvByte();	//���һ���ֽ�
		//SDA = 1;                    //д��Ӧ���ź�
		GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN2);
		//SCL = 1;                    //����ʱ����
		GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN1);
		Delay2us();                 //��ʱ
		//SCL = 0;                    //����ʱ����
		GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN1);
		Delay2us();                 //��ʱ
	I2C_Stop();                    //ֹͣ�ź�
}
