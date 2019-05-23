#include "shift_reg.h"
void latch(void)
{
    LATCH=0;
    __delay_us(2);
    LATCH=1;
    __delay_us(2);
    LATCH=0;
}
void shift_data(unsigned char n)
{
    unsigned char i;
    CLK=0;
    for(i=0;i<8;i++)
    {
        DATA=((n & 0x80)==0x80);
        __delay_us(2);
        n=n<<1;
        CLK=1;
        __delay_us(2);
        CLK=0;
    }
}
