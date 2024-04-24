
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
#include <math.h>
#include <htc.h>
#define _XTAL_FREQ 4000000

void khaibaoport ()
{
    ANSEL=ANSELH=0;   
    TRISE=0;
    TRISD=0;
    TRISB0=1;
    nRBPU=0;
    WPUB0=1;         
    PORTE=0x00;
    INTF=0;
    GIE=1; INTE=1; INTEDG=0;
}

void main(void)
{
    khaibaoport();
    while(1)
    {
      //  PORTE=0x06;
        unsigned char i,temp;
        PORTD =0;
        __delay_ms(300);
        temp = 0x80;
        for(i=0;i<8;i++)
        {
            PORTD =temp;
            __delay_ms(300);
            temp=temp>>1;
        }
        
        
    }
}
void interrupt isr()
{
    if(INTF&&INTF)
    {
    INTF=0;
    __delay_ms(300);
       unsigned char i,temp;
       // PORTD =0;
        __delay_ms(300);
        temp = 0x80;
        for(i=0;i<8;i++)
        {
            PORTD =temp;
            PORTE=0x07;
            __delay_ms(300);
            temp=temp>>1;
        }
        PORTE=0x00;
    }
}
