#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define bit_is_set(sfr, bit) (_SFR_BYTE(sfr) & _BV(bit))
#define bit_is_clear(sfr, bit) (!(_SFR_BYTE(sfr) & _BV(bit)))

#ifndef cbi
#define cbi(reg, bit) reg &= ~(_BV(bit))
#endif

#ifndef sbi
#define sbi(reg, bit) reg |= (_BV(bit))
#endif

void init_PWM() // zadanie 1
{
	TCCR1A |= (1 << WGM10) | (1 << WGM11) | (1 << COM1A1);
	TCCR1B |= (1 << WGM12) | (1 << CS12); //ustawienie prescalera na 256 bitow
}

int main()
{
	// pliki .hex przestały mi się tworzyć po przejściu z C do C++, zamiast tego dołączyłem plik .elf który działa tak samo
	DDRD = 255;
	DDRC = 255;
	DDRB = 0x00;
	PORTB = 0xff;

	init_PWM();
	int low = 1023 * 0.05, high = 1023 * 0.12; //Wartoscia TOP wedlug dokumentacji dla FastPWM 10-bit jest 1023, Zadanie 2
	OCR1A = (low + high) / 2; //wartosc poczatkowa serwa
	while (1)
	{
		//zadanie 5
		if (bit_is_clear(PINB, 0))
		{
			if (bit_is_clear(PINB, 2) && OCR1A < high)  //zadanie 4
			{
				cbi(PORTD, PD5);
				OCR1A = OCR1A + 1;
				_delay_ms(200);
			}
			if (bit_is_clear(PINB, 1) && OCR1A > low)
			{
				cbi(PORTD, PD5);
				OCR1A = OCR1A - 1;
				_delay_ms(200);
			}
			else
			{
				sbi(PORTD, PD5);
				_delay_ms(200);
			}
		}
		else
		{
			int i = 50;
			while (i != high) //zadanie 3
			{
				OCR1A = i;
				_delay_ms(200);
				i++;
			}
			while (i != low)
			{
				OCR1A = i;
				_delay_ms(200);
				i--;
			}
		}
	}
	return 0;
}
