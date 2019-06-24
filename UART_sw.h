#include <xc.h>

#define _XTAL_FREQ 8000000

//Declare Pins
#define TX LATB5
#define RX PORTBbits.RB6
//Declare Speed
//#define BAUDRATE 9600
/////////////////////////
#ifndef BAUDRATE
    #define BAUDRATE 9600
    #define timeslot 104
#else
#if BAUDRATE==4800
    #define timeslot 208
#else
#if BAUDRATE==19200
    #define timeslot 72
#else
#if BAUDRATE==38400
    #define timeslot 37
#else
#if BAUDRATE==57600
    #define timeslot 17
#else
#if BAUDRATE==115200
    #define timeslot 8
#endif
#endif
#endif
#endif
#endif
#endif
/////////////////////////////////    
void UARTInit(void);
void UART_SendByte(unsigned char data);
void UART_SendStr(unsigned char *data);
unsigned char UART_ReadByte(void);
unsigned char* UART_ReadStr(void);
/////////////////////////////////
