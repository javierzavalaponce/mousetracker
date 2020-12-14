#include<18f4550.h>

//LCD module connections
#define LCD_RS_PIN PIN_D0
#define LCD_RW_PIN PIN_D1
#define LCD_ENABLE_PIN PIN_D2
#define LCD_DATA4 PIN_D3
#define LCD_DATA5 PIN_D4
#define LCD_DATA6 PIN_D5
#define LCD_DATA7 PIN_D6
#device ADC = 10
#fuses 
#fuses NOMCLR INTRC_IO,NOWDT,NOPROTECT,NOLVP,NODEBUG,CPUDIV1,VREGEN
#use delay(clock=8000000)
#use rs232(baud = 9600, xmit = PIN_C6, rcv = PIN_C7)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lcd.c"
#include "sensores.c"


void funcion(void);

//Initializing the RTOS Program
#use rtos(timer = 0, minor_cycle = 100ms)

//Task Called after every 200msec
#task(rate = 200ms, max = 1ms)
void Live()
{
 output_toggle(PIN_B0);        //Toggle the State of LED after 200msec
}

#task(rate = 2s, max = 100ms)
void Send_To_RS232()
{ 
    static volatile unsigned char j = 0;
    //Display Converted Voltage at Serial Port at a Baud Rate of 9600bps
    printf("[data] = %03d \n\r",j++);
}


#task(rate = 1s, max = 100ms)
void Send_To_lcd()
{ 
    funcion();
}

/*---------------------*/
void lcd_puts(unsigned char * ptr)
{
   while(*ptr != 0){
     lcd_putc(*ptr);
     ptr++;
   }
}

void funcion(void)
{ 
  static char buffer[50];
  static int j = 0;
  j = read();
  sprintf(buffer,"j = %u",j);
  lcd_gotoxy(2, 1);                 // Go to column 2 row 1
  lcd_puts(buffer);
  lcd_gotoxy(1, 2);                 // Go to column 1 row 2
  lcd_putc("test!");
}

void main()
{
 lcd_init();
 adc_init();
 set_tris_d(0x00);
 output_d(0x00);
 delay_us(10);
 rtos_run();	
}