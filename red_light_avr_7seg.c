/*
 * red_light_avr_7seg.c
 *
 * Created: 05-05-2020 14:44:41
 *  Author: hp pc
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "4bit_lcdlib.h"

int main(void)
{
	DDRC=0XFF;
	PORTC=0XFF;
	DDRD=0XFF;
	PORTD=0XFF;
	DDRA=0XFF;
	PORTA=0X00;
	int i=0,k=0;
	LCD_Init();
	char DISPLAY1[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F} ;
    while(1)
    {
		PORTA|=(1<<0);
		_delay_ms(20);
		LCD_Clear();
		LCD_String("PEDESTRIANS GO");
		PORTD=DISPLAY1[2];
		PORTC=DISPLAY1[0];
		_delay_ms(800);
		for(k=1;k>=0;k--)
		{
			PORTD=DISPLAY1[k];
		for(i=9;i>=0;i--)
		{
			PORTC=DISPLAY1[i];
			_delay_ms(500);						//RED
        //TODO:: Please write your application code 
		if(DISPLAY1[k]==0x3F && DISPLAY1[i]==0x4F)
		{
			break;
		}
		}
		}		
		PORTA&=~(1<<0);
		LCD_Clear();
		LCD_String("PEDESTRIANS COME");
		LCD_Command(0xC0);
		LCD_String("TO HALT");
		PORTA|=(1<<1);
		_delay_ms(20);
		PORTD=DISPLAY1[0];
		for(i=3;i>=1;i--)
		{
			PORTC=DISPLAY1[i];						//YELLOW
			_delay_ms(500);
		}			
		PORTA&=~(1<<1);
		LCD_Clear();
		LCD_String("PEDESTRIANS STOP");
		PORTA|=(1<<2);	
		//_delay_ms(200);
		PORTD=DISPLAY1[1];
		PORTC=DISPLAY1[0];
		_delay_ms(500);
		for(i=9;i>=4;i--)
		{
			PORTD=DISPLAY1[0];
			PORTC=DISPLAY1[i];
			_delay_ms(500);						//GREEN	
		}
		PORTA&=~(1<<2);
		LCD_Clear();
		LCD_String("PEDESTRIANS ");
		LCD_Command(0XC0);
		LCD_String("BE READY");
		PORTA|=(1<<1);
		_delay_ms(200);	
		for(i=3;i>=1;i--)
		{
			PORTC=DISPLAY1[i];						//YELLOW
			_delay_ms(500);
		}			
		PORTA&=~(1<<1);
		_delay_ms(100);
		
	}
	return 0;
}