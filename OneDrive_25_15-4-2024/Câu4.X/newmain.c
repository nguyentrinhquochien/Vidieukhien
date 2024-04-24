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
const char dat_line1[] = {0x4C,0x01,' ',0x53,0x02,' ',0x48,0x6F,0x00,0x6E,0x67};
const char dat_line2[] = {"DTVT15B-19524251"};
const char cgram_dat[] = 
     {
    0x02,0x01,0x00,0x0E,0x0A,0x0A,0x0F,0x00,//af
    0x04,0x0A,0x00,0x0E,0x0A,0x0E,0x08,0x0E,//ee
    0x05,0x0A,0x00,0x0A,0x0E,0x02,0x02,0x0E,//yx
    0X04,0X02,0X01,0X02,0X01,0X0A,0X0A,0X0E,//uwf
    0X00,0X00,0X00,0X02,0X01,0X0E,0X0A,0X0E,//ow
    0x99
    };
void setup_ccp2(void) 
{
TRISC1 = 1;
TMR2 = 0;
PR2 = 99;
CCPR2L = 40;
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
        lcd_puts("Thi ket thuc mon\n good luck " );
        setup_ccp2();
       
        while(!RB1);
       
        }}
    }}
