#include <avr/io.h>
#include <util/delay.h>

#define 	bit_is_set(sfr, bit)   (_SFR_BYTE(sfr) & _BV(bit))
#define 	bit_is_clear(sfr, bit)   (!(_SFR_BYTE(sfr) & _BV(bit)))

#ifndef cbi
#define cbi(reg,bit)		reg &= ~(_BV(bit))
#endif

#ifndef sbi
#define sbi(reg,bit)		reg |= (_BV(bit))
#endif




void task_4(int time)
{
	int minutes_1=time/600;
	int minutes_2=(time/60)%10;
	int seconds_1= (time-(minutes_1*600 + minutes_2*60))/10;
	int seconds_2 =(time-(minutes_1*600 + minutes_2*60))%10;
	int numbers[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00100111,0b01111111,0b01101111};
	DDRD=0xff;
	DDRA=0xff;
	for (int h=minutes_1;h<=5;h++)
	{
		for (int k=minutes_2;k<=9;k++)
		{
			for(int i=seconds_1;i<=5;i++)
			{
				for(int j=seconds_2;j<=9;j++)
				{
					if(i>=1 || k>=1 || h>=1)
					{
						PORTD=0b10110000;
						PORTA=numbers[i];
						_delay_ms(100);
					}
					if(k>=1 || h>=1)
					{
						PORTD=0b11010000;
						PORTA=numbers[k];
						_delay_ms(100);
					}
					if(h>=1)
						{
						PORTD=0b11100000;
						PORTA=numbers[h];
						_delay_ms(100);
					}
					PORTD=0b01110000;
					PORTA=numbers[j];
					_delay_ms(200);
				}
			}
		}
	}

}




void task_3()
{
	int numbers[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00100111,0b01111111,0b01101111};

		DDRD=0xff;
		DDRA=0xff;
	for (int h=0;h<=9;h++)
	{
		for (int k=0;k<=9;k++)
		{
			for(int i=0;i<=9;i++)
			{
				for(int j=0;j<=9;j++)
				{
					if(i>=1 || k>=1 || h>=1)
					{
						PORTD=0b10110000;
						PORTA=numbers[i];
						_delay_ms(100);
					}
					if(k>=1 || h>=1)
					{
						PORTD=0b11010000;
						PORTA=numbers[k];
						_delay_ms(100);
					}
					if(h>=1)
						{
						PORTD=0b11100000;
						PORTA=numbers[h];
						_delay_ms(100);
					}
					PORTD=0b01110000;
					PORTA=numbers[j];
					_delay_ms(200);
				}
			}
		}
	}

}



int main()
    {

	 task_3();

}

