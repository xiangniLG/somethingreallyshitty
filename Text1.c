#include<c8051f320.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void Init320();
//Send a char on UART0
void Send_RS(unsigned char ch)
{
    SBUF0=ch;
    while((SCON0&2)==0);
    SCON0&=0xfd;
}

void main(void)
{
unsigned char i=0;
Init320();  //��ʼ��
do{
Send_RS(i);
i++;
}while(1);//�ȴ��ж�
}

/////////// SYSTEM INIT //////
//Init C8051F320 as a MCS51 MPU
void Init320()
{
PCA0MD=0;       //���Ź���ֹ
OSCICN=0X83;    //�ڲ�12M����ʹ�ܣ�����Ƶ��Ϊϵͳʱ��
CLKSEL=0;       //Select inside OSC as USB��SYSCLK
XBR0=0X5;       //Ƭ������ URT0 �� SMBUS ���ӵ����ţ�
//�ֱ�ռ��P0.4(TX0)��P0.5(RX0)/P0.0(SDA)��P0.1(SCL)
XBR1=0X40;      //���濪��ʹ��, ������ʹ��
P0MDOUT=0X0F;   //P0.0-P0.3Ϊ�����죩���
P1MDOUT=0XFF;   //P1Ϊ�����죩���
P2MDOUT=0XFC;   //P2.2-P2.7Ϊ�����죩���
P2MDIN=0XFC;     //P2.0��P2.1����Ϊģ������

TCON=0x50;    //T0 T1 ENABLE
TMOD=0X22;   //T0 ��T1 WORK IN MODEL_2��8bits timer
CKCON=0X0A; //T0 WORK IN SYSTEM_CLK/48, T1 WORK IN SYSTEM_CLK=12M
TH0=100;       //T0=4KHz Timer
TL0=100;
 //UART0 INIT
TH1=-52;        //T1,115200,256-12000000/2/115200
TL1=-52;
SCON0=0X10;     //8 BITs
}

