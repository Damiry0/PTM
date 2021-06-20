#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "LCD_HD44780.h"


int main()
    {
	LCD::init();
	DDRA=0xff;
	double a,temp;
	int first,second,third;
	ADMUX |= ((1 << REFS0)|(0<< REFS1));
	ADMUX |= (0 << ADLAR);
	ADMUX |= ((0 << MUX1)|(0<< MUX2)|(0 << MUX3)|(0<< MUX4)|(0<<MUX0));
	// W przypadku zmiany na tryb roznicowy nalezy zmienic powyzsza linijke, np.
	// (1<< MUX4) zmieni on na tryb roznicowy pomiedzy portem ADC0 (pozytywny)
	// i ADC1 (negatywny) o wzmocnieniu równym 1x
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADSC);
	ADCSRA |= (1 << ADATE);
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

	//SFIOR |= (0<<ADTS2) | (0<<ADTS1) | (0<<ADTS1);

		while(1){
			if(ADCSRA & _BV(ADIF))
			{
				LCD::clear();
				a=(ADC *5)/1024;
				first=a;
				temp = (a*10);
				second=temp;
				second=second%10;
				temp=(a*100);	//
				third=temp;		//
				third= third%10;  // nie mam pojecie czemu to nie dziala, testujac to recznie i w innym kompliatorze wychodzi poprawnie
				printf("%d",second);
				char text[16];
				sprintf(text, "%i.%i%i", first,second,third);
				LCD::writeText(text);
				_delay_ms(1000);
			}

		}

	return 0;
}

