#include "UART_sw.h"
#include <xc.h>

void UARTInit(void)
{
    TX=1;
    TRISB5=0;
    TRISB6=1;
}

void UART_SendByte(unsigned char data)
{
    unsigned char i;
    TX=0;
    __delay_us(timeslot-3);
    for(i=0;i<8;i++)
    {
        TX=((data&0x01)==0x01);
        __delay_us(timeslot-3);
        data=data>>1;
    }
    TX=1;
    __delay_us(timeslot);
}

void UART_SendStr(unsigned char *data)
{
    while(*data)
    {
        UART_SendByte(*data);
        data++;
    }
}
