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
#define timeTest 300 // declare time delay 

void declarePort();
void hien1(unsigned int times);
void hien2(unsigned int times);
void hien3(unsigned int times);

void main(void){
    declarePort();
    while(1)
    {
       if(!RB0)
       {
          // do something
          hien1(4);
       }else if(!RB1) { 
          // do something
           hien2(2);
       }else if(!RB2) {
           hien3(2);
       }
    }
}

void hien2(unsigned int times) {
    while(times--) {
        PORTD = 0b01010101;
        __delay_ms(1000);
        PORTD=0;
    }
}


void hien3(unsigned int times) {
    while(times--) {
            PORTD = 0xFF;
            __delay_ms(100);
            __delay_ms(100);
            __delay_ms(100);
            PORTD = 0x00;
            __delay_ms(100);
            __delay_ms(100);
            __delay_ms(100);
            PORTD = 0xFF;
            __delay_ms(100);
            __delay_ms(100);
            __delay_ms(100);
            PORTD = 0xFF;
            __delay_ms(100);
            __delay_ms(100);
            __delay_ms(100);
            
            PORTD = 0xFF;
            __delay_ms(100);
            __delay_ms(100);
            __delay_ms(100);
          
        PORTD = 0;  
}
}     
        
        

void hien1(unsigned int times) {
    while(times--) {
        PORTD = 0b10101010;
        __delay_ms(1000);
        PORTD=0;
    }
}

void declarePort() { // declare port
    ANSEL = ANSELH = 0;
    TRISD = 0;
    PORTD = 0;
    TRISC = 0;
    PORTC = 0;
    // declare Pin RB0 - RB2 is input
    TRISB0 = 1;
    TRISB1 = 1;
    TRISB2 = 1;
    // declare resistance pull-up
    nRBPU = 0; // set permit all PORTB have resistance pull-up
    WPUB = 0x07; // set only pin RB0 - RB2 have resistance pull-up