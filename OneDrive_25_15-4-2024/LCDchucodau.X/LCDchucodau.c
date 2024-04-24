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
// Khai bao du lieu hien thi.
const char dat_line1[] = "     KHOA "; // Noi dung can hien thi - Hang 1.
const char dat_line2[] = {0x43,0X4E,' ',0x00,0X69,0X01,0X6E,' ',0X54,0X02}; 
// Noi dung can hien thi - Hang 2.
const char cgram_dat[] =
    {
    0X0E,0X09,0X09,0X1D,0X09,0X09,0X0E,0X00, 
    0x0C,0x12,0x0C,0x1E,0X10,0x1E,0x04,0x00,
    0X0C,0X02,0X05,0X12,0X12,0X12,0X0C,0X00,0x99
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
lcd_gotoxy(0,0); 
lcd_putc('\f'); 
lcd_puts(dat_line1); 
lcd_gotoxy(2,1);
for(i=0;i<=9;i++)
    {
        lcd_putc(dat_line2[i]);
    }
while(1);
}
