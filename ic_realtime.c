#include <xc.h>
#include "i2c_sw.h"
#include "ic_realtime.h"
// MCU SPEED
#define _XTAL_FREQ 8000000

// read time from ic 
// must declare hour, minute, second
void Read_time(unsigned char *hour, unsigned char *minute, unsigned char *second)
{
    i2c_Start();
    i2c_Write(WrCmd);
    i2c_Ack();
    i2c_Write(SecondAddressRegister);
    i2c_Ack();
    i2c_Start();
    i2c_Write(RdCmd);
    i2c_Ack();
    *second = i2c_Read();
    i2c_Ack();
    *minute = i2c_Read();
    i2c_Ack();
    *hour = i2c_Read();
    i2c_NAck();
    i2c_Stop();
}

void Write_time(unsigned char hour, unsigned char minute, unsigned char second)
{
    i2c_Start();
    i2c_Write(WrCmd);
    i2c_Ack();
    i2c_Write(SecondAddressRegister);
    i2c_Ack();
    i2c_Write(second);
    i2c_Ack();
    i2c_Write(minute);
    i2c_Ack();
    i2c_Write(hour);
    i2c_Ack();
    i2c_Stop();
}
// must declare day, date, month, year
void Read_date(unsigned char *day, unsigned char *date, unsigned char *month, unsigned char *year)
{
    i2c_Start();
    i2c_Write(WrCmd);
    i2c_Ack();
    i2c_Write(DayAddressRegister);
    i2c_Ack();
    i2c_Start();
    i2c_Write(RdCmd);
    i2c_Ack();
    *day = i2c_Read();
    i2c_Ack();
    *date = i2c_Read();
    i2c_Ack();
    *month = i2c_Read();
    i2c_Ack();
    *year = i2c_Read();
    i2c_NAck();
    i2c_Stop();
}

void Write_date(unsigned char day, unsigned char date, unsigned char month, unsigned char year)
{
    i2c_Start();
    i2c_Write(WrCmd);
    i2c_Ack();
    i2c_Write(DayAddressRegister);
    i2c_Ack();
    i2c_Write(day);
    i2c_Ack();
    i2c_Write(date);
    i2c_Ack();
    i2c_Write(month);
    i2c_Ack();
    i2c_Write(year);
    i2c_Ack();
    i2c_Stop();
}
// convert BCD2DEC
unsigned char bcd2dec(unsigned char num)
{
    unsigned char i = 0;
    i = ((num & 0xF0) >> 4u);
    i *= 10;
    i = i | (num & 0x0F);
    return i;
}
//convert DEC2BCD
unsigned char dec2bcd(unsigned char num)
{
    unsigned char i = 0;
    i = (num / 10u);
    i = (i << 4);
    i = i | (num & 0x0f);
    return i;
}
