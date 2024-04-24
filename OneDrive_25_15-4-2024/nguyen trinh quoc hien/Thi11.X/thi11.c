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
const char dat_line2[] = " 19476081 ";
const char dat_line1[] = {0x4E,0x67,0x75,0x79,0x1EC5,0x6E,0x20,0x54,0x20,0x51,0x75,0x1ED1,0x63,0x20,0x48,0x69,0x1EC1,0x6E };
const char cgram_dat[] = {
    0x00,0x00,0x03,0x12,0x12,0x12,0x0C,0x00,
    0x00,0x00,0x03,0x0E,0x11,0x11,0x0E,0x00,
    0X0E,0X09,0X09,0X1D,0X09,0X09,0X0E,0X00,
    0x04,0x08,0x03,0x12,0x12,0x12,0x0C,0x00,    
    0x04,0x02,0x0E,0x01,0x0F,0x11,0x0F,0x00,
    0x99};
void setup_ccp2(void) 
{
TRISC1 = 1;
TMR2 = 0;
PR2 = 82;
CCPR2L = 58;
CCP2CON = 0x0C;
DC2B1=0;DC2B0=0;
TRISC1 = 0;
T2CON = 0X00;
TMR2ON =1;
TRISE0=0;RE0=1;
}
void main(void)
{
    ANSEL=ANSELH=0;
    TRISB=0X07;
    nRBPU=0;
    WPUB=0X07;
    while(1){
   
    if(!RB0)
    {__delay_ms(5);TRISB=0X07;
    nRBPU=0;
    WPUB=0X07;
    TRISC1=TRISC2=1;
    TRISE0=0;RE0=0;
    while(!RB0){
        
    
    
        unsigned char i;
        lcd_init(); 
        i = 0;  
        lcd_put_byte(0,0x40); 
        while(lcd_busy()); 
        while(cgram_dat[i]!=0x99) 
        { 
       lcd_put_byte(1,cgram_dat[i]); 
        while(lcd_busy()); 
        i++;
        }  
        lcd_putc('\f');
        lcd_gotoxy(0,0);
       for(i=0;i<=20;i++)
       lcd_putc(dat_line1[i]); 
      
       lcd_gotoxy(2,1); 
       lcd_puts(dat_line2);
       while(!RB0);
         }}
    if(!RB1)
    {__delay_ms(5);
    
        
        while(!RB1){
            TRISB=0X07;
    nRBPU=0;
    WPUB=0X07;
        lcd_init();
        lcd_gotoxy(1,0);
        lcd_puts("Freq=8KHz D=70% \n    ModulCCP2 " );
        setup_ccp2();
       
        while(!RB1);
       
        }}
    if (!RB2)
    
    {__delay_ms(5); TRISC1=TRISC2=1;
    TRISE0=1;RE0=0;
            TRISB=0X07;
            
           
            nRBPU=0;
            WPUB=0X07;
        
        
        while(!RB2){
           
        lcd_init();
        lcd_putc('\f');
        lcd_gotoxy(1,0);
        
        lcd_puts("N.Sinh:12-10-01 \n     +++++  " );
       
        while(!RB2);
    }
    }}}