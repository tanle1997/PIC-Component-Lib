#include"IC595.h"
#include<xc.h>
#define DATA LATC1
#define LATCH LATC2
#define CLK LATC0
////////////////////////////

void output(int x){
    unsigned int i,a;
    a=x;
    for(i=0;i<8;i++){
    if ((a & 0x80)== 0x80)
        DIN=1;
    else
        DIN=0;
    a=a<<1;
    SCLK=1;
    SCLK=0;
    }
}
////////////////////////////
void enable(){
    LAT=1;
    LAT=0;
}