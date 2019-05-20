#include <xc.h>
#define _XTAL_FREQ 8000000

#define SDA_TRIS TRISC4
#define SCL_TRIS TRISC3
#define SDA PORTCbits.RC4
#define SCL PORTCbits.RC3

void i2c_Init(void);
void i2c_Write(unsigned char n);
unsigned char i2c_Read(void);
void i2c_Ack(void);
void i2c_NAck(void);
void i2c_Stop(void);
void i2c_Start(void);