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
const char dat_line1[] ={0x48,0x69,0xe1,0xbb,0x81,0x6e};
const char dat_line2[] = {" 19476081 "};
const char dat_line3[] = {110,0xE0,0x6D,0x20,0x76,0x103,0x6E,0x20,0x6B,0x68,0x61,0x6E,0x67};
const char dat_line4[] = {" 17054241 " };


const char cgram_dat[] = 
    {
    0x02,0x01,0x00,0x0E,0x0A,0x0A,0x0F,0x00,//af
    0x04,0x0A,0x00,0x0E,0x0A,0x0E,0x08,0x0E,
    0x05,0x0A,0x00,0x0A,0x0E,0x02,0x02,0x0E,
    0X04,0X02,0X01,0X02,0X01,0X0A,0X0A,0X0E,
    0X00,0X00,0X00,0X02,0X01,0X0E,0X0A,0X0E,
    0x99
    };
void main()
{ 
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
lcd_gotoxy(0,1); 
lcd_puts(dat_line2); 
lcd_gotoxy(0,0);
for(i=0;i<=11;i++)
    {
        lcd_putc(dat_line1[i]);
    }
__delay_ms(2000);
lcd_putc('\f'); 
lcd_gotoxy(0,1); 
lcd_puts(dat_line4); 
lcd_gotoxy(0,0);
for(i=0;i<=11;i++)
    {
        lcd_putc(dat_line3[i]);
    }
__delay_ms(2000);
while(1);
}