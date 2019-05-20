// FOR IC 74HC595
#define _XTAL_FREQ 8000000
#include <xc.h>
#define DATA    LATC0
#define CLK     LATC1
#define LATCH   LATC2

void latch(void);
void shift_data(unsigned char n);
