#include "shift_reg.h"
void latch(void)
{
    LATCH = 0u;
    __delay_us(2);
    LATCH = 1u;
    __delay_us(2);
    LATCH = 0u;
}
void shift_data(unsigned char n)
{
    unsigned char i;
    CLK = 0;
    for(i = 0; i < 8; i++)
    {
        DATA = ((n & 0x80) == 0x80);
        __delay_us(2u);
        n = n << 1u;
        CLK = 1;
        __delay_us(2u);
        CLK = 0;
    }
}
