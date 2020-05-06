/*
 * red_light_avr_7seg.c
 *
 * Created: 05-05-2020 14:44:41
 *  Author: hp pc
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC=0XFF;
	PORTC=0XFF;
	DDRA=0XFF;
	PORTA=0X00;
	int i=0;
	char DISPLAY1[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F} ;
    while(1)
    {
		PORTA|=(1<<0);
		_delay_ms(20);
		for(i=9;i>3;i--)
		{
			PORTC=DISPLAY1[i];
			_delay_ms(1000);						//RED
        //TODO:: Please write your application code 
		}
		PORTA&=~(1<<0);
		
		PORTA|=(1<<1);
		_delay_ms(20);
		for(i=3;i>=1;i--)
		{
			PORTC=DISPLAY1[i];						//YELLOW
			_delay_ms(1000);
		}			
		PORTA&=~(1<<1);
		PORTA|=(1<<2);	
		//_delay_ms(200);
		for(i=9;i>=4;i--)
		{
			PORTC=DISPLAY1[i];
			_delay_ms(1000);						//GREEN	
		}
		PORTA&=~(1<<2);
		PORTA|=(1<<1);
		_delay_ms(20);	
		for(i=3;i>=1;i--)
		{
			PORTC=DISPLAY1[i];						//YELLOW
			_delay_ms(1000);
		}			
		PORTA&=~(1<<1);
	}
	return 0;
}