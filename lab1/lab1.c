#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>

#ifndef _BV
#define _BV(bit)				(1<<(bit))
#endif
#ifndef sbi
#define sbi(reg,bit)		reg |= (_BV(bit))
#endif

#ifndef cbi
#define cbi(reg,bit)		reg &= ~(_BV(bit))
#endif

#ifndef tbi
#define tbi(port, pin) (port) ^= _BV(pin)
#endif

int main() {
//zadanie 1
/*	DDRD=0x11110000; //255 tez git

	sbi(DDRD, PD6);

	while (1) {
		sbi(PORTD, PD6);
		_delay_ms(2000);

		cbi(PORTD, PD6);
		_delay_ms(2000);
	}
// zadanie 2

	for(int i=0;i<255;i++)
	{

	}*/

//zadanie 3
	DDRD = 0b11111111;
	while(1)
	{
		PORTD=0b10000000;
		_delay_ms(4000);
		PORTD = 0b01000000;
		_delay_ms(4000);
		PORTD=0b00100000;
		_delay_ms(4000);
		PORTD = 0b00010000;
		_delay_ms(4000);
		PORTD=0b00001000;
		_delay_ms(4000);
		PORTD = 0b00000100;
		_delay_ms(4000);
		PORTD=0b00000010;
		_delay_ms(4000);
		PORTD = 0b00000001;
		_delay_ms(4000);
	}


//zadanie 4
	DDRD = 0b11111111;
	while(1)
	{
		PORTD=0b10000000;
		_delay_ms(4000);
		PORTD = 0b01000000;
		_delay_ms(4000);
		PORTD=0b00100000;
		_delay_ms(4000);
		PORTD = 0b00010000;
		_delay_ms(4000);
		PORTD=0b00001000;
		_delay_ms(4000);
		PORTD = 0b00000100;
		_delay_ms(4000);
		PORTD=0b00000010;
		_delay_ms(4000);
		PORTD = 0b00000001;
		_delay_ms(4000);
				PORTD=0b00000010;
				_delay_ms(4000);
				PORTD = 0b00000100;
				_delay_ms(4000);
				PORTD=0b00001000;
				_delay_ms(4000);
				PORTD = 0b00010000;
				_delay_ms(4000);
				PORTD=0b00100000;
				_delay_ms(4000);
				PORTD = 0b01000000;
				_delay_ms(4000);

	}

}
