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

void task_1 ();
void task_2 ();
void task_3 ();
void task_4 ();

int main() {
task_3();

}

void task_1 ()
{
	DDRD=0x11110000; //255 tez git
	sbi(DDRD, PD6);

	while (1) {
		sbi(PORTD, PD6);
		_delay_ms(4000);

		cbi(PORTD, PD6);
		_delay_ms(4000);
	}
}

void task_2 ()
{
	DDRD = 0b11111111;
		for(int i=0;i<255;i++)
		{

		}

}

void task_3 ()
{
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
}

void task_4 ()
{
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
