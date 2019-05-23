#include "i2c_sw.h"

void i2c_Init(void)
{
    SCL=0;
    SCL_TRIS = 0;
    SDA=0;
    SDA_TRIS = 0;
    SDA=1;
    __delay_us(2);
    SCL=1;
    __delay_us(2);
}

void i2c_Write(unsigned char n)
{
    unsigned char i;
    SCL=0;
    __delay_us(2);
    SDA_TRIS = 0;
    for(i=0;i<8;i++)
    {
        SCL=0;
        __delay_us(2);
        SDA=((n & 0x80)==0x80);
        __delay_us(2);
        n=n<<1;
        SCL=1;
        __delay_us(2);
    }
}

unsigned char i2c_Read(void)
{
    unsigned char n = 0,i;
    SCL=0;
    __delay_us(2);
    SDA_TRIS = 1;
    __delay_us(2);
    for(i=0;i<8;i++)
    {
        n=n<<1;
        SCL=1;
        __delay_us(2);
        n|=SDA;
        SCL=0;
        __delay_us(2);
    }
    return n;
}

void i2c_Ack(void)
{
    SCL=0;
    __delay_us(2);
    SDA=0;
    SDA_TRIS=0;
    __delay_us(2);
    SCL=1;
    __delay_us(2);
    SCL=0;
    __delay_us(2);
    SDA=1;
    __delay_us(2);
}

void i2c_NAck(void){
    SCL=0;
    SDA=1;
    SDA_TRIS=0;
    __delay_us(2);
    SCL=1;
}

void i2c_Stop(void)
{
    SCL=0;
    SDA_TRIS = 0;
    SDA=0;
    __delay_us(2);
    SCL=1;
    __delay_us(2);
    SDA=1;
}
void i2c_Start(void)
{
    SCL=1;
    __delay_us(2);
    SDA=1;
    SDA_TRIS = 0;
    __delay_us(2);
    SDA=0;
    __delay_us(2);
    SCL = 0;
    __delay_us(2);
}
