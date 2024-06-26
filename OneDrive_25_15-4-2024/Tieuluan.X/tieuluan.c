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
#define _XTAL_FREQ 4000000
#include <xc.h>
#define timeTest 30// declare time delay 
void declarePort() { // khai bao port
    ANSEL = ANSELH = 0;
    TRISD = 0;
    TRISC = 0;
    TRISB = WPUB = 0x03;
    PORTC = 0;
    PORTD = 0;
    nRBPU = 0;
    GIE = 1;
    //RBIF = 0;
    RBIE = 1;
    IOCB = 0x03;
}
unsigned int state = 1;
int sangDanInAndOut(unsigned int n) {
    while(n > 0) {
        
        unsigned char index = 0;
        unsigned char holdC = 0x80;
        unsigned char holdD = 0x01;
        PORTC = 0;
        PORTD = 0;
        __delay_ms(timeTest);
        while(index < 1) {
            if(!state) {
                PORTC = 0;
                PORTD = 0;
                return 0;
            }
            PORTC = holdC;
            PORTD = holdD;
            __delay_ms(timeTest);
            holdC = (holdC >> 1) | holdC;
            holdD = (holdD << 1) | holdD;
            index++;
        }
        holdC = 0x80;
        holdD = 0x01;
        n--;
    }
}
void main()
{
    declarePort();
    if(!RB0) {
        __delay_ms(50);
        while(!RB0);
        while(1) {
            if(!state) {
                PORTC = 0;
                PORTD = 0;
                break;
            }
            sangDanInAndOut(1);
        }
    }
}
void __interrupt() myIsr() {
    if(RBIF) {
        if(!RB1) {
            __delay_ms(50);
            while(!RB1);
            state = 0;
        }
        RBIF = 0;
    }
}