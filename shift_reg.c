#include "shift_reg.h"
void latch(void)
{
    LATCH=0;
    __delay_us(2);
    LATCH=1;
    LATCH=0;
}
void shift_data(unsigned char n)
{
    unsigned char i;
    CLK=0;
    for(i=0;i<8;i++)
    {
        if((n & 0x80) == 0x80)
            DATA=1;
        else
            DATA=0;
        __delay_us(2);
        n=n<<1;
        CLK=1;
        CLK=0;
    }
}
