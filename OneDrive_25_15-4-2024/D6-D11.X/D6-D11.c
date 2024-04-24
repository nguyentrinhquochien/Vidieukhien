// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _XTAL_FREQ 4000000
void delay_ms(unsigned int ms)
    {
        {
        unsigned int i;
        for(i=0; i<=ms; i++)
        TMR1H=255;TMR1L=231;
        TMR1IF=0;
        TMR1CS=0;
        GIE=0;PEIE=0;TMR1IF=0;
        T1CKPS1 =1;T1CKPS0=0;
        T1SYNC=0;
        TMR1ON=1;
        while(TMR1IF==0);
        }
    }

void main (void)
{
    ANSEL=ANSELH=0X00;
    TRISE=0;
    TRISB=0x01;
    while(1)
    {
       
        PORTE=0x00;
        TRISB=0x21; 
        PORTB=0x08;//d6
        __delay_ms(300);
        unsigned int a,b;
        for(b=0;b<3000;b++) //d79
    {
        TRISB=0x21;     
        PORTB=0x08;//d6
        delay_ms(3000);
        TRISB=0x21;
        PORTB=0x10; //d7
        delay_ms(3000);
        TRISB=0x09;
        TRISB=0x09;   
        PORTB=0x10;//d8
        delay_ms(3000);
        PORTB=0x20;//d9
        delay_ms(3000);
        TRISB=0x11;
        PORTB=0x20;//d10
        delay_ms(3000);
        TRISB=0x11;
        PORTB=0x08;//d11
        delay_ms(3000);
    }
        while(1)
        {
            PORTB=0;
            PORTE=0; 
        }
    }
}
