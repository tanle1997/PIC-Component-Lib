#ifndef I2C_SW
  #define I2C_SW

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
unsigned char i2c_IsAck(void);

#endif
