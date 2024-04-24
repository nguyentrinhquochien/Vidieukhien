// CONFIG1
#pragma config FOSC = HS 
#pragma config WDTE = OFF 
#pragma config PWRTE = OFF 
#pragma config MCLRE = ON 
#pragma config CP = OFF 
#pragma config CPD = OFF 
#pragma config BOREN = OFF 
#pragma config IESO = OFF 

#pragma config FCMEN = OFF 
#pragma config LVP = OFF 
// CONFIG2
#pragma config BOR4V = BOR40V 
#pragma config WRT = OFF 

#include <xc.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "lcd.h" // Cau hinh ket noi va khai bao lenh dung cho LCD.
#define _XTAL_FREQ 4000000
void setup_ccp(void)
{
TRISC1 = 1;
TMR2 = 0;
PR2 = 89;
CCPR2L = 58;
CCP2CON = 0x0C;
DC2B1=0;DC2B0=0;
TRISC1 = 0;
T2CON = 0X00;
TMR2ON =1;
TRISE0=0;
RE0=1;
}

    void main(void)
    {
        lcd_init();
        lcd_putc('\f');
        lcd_puts("\fFreq=11 KHz\n D=65% Modul=1");
        setup_ccp();
        while(1);
    }
