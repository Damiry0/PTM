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

int getKey() //do task 3
{
 for(int i=0;i<4;i++)
 {
	 sbi(PORTC,i);
	 if(bit_is_set(PINC,4))
	 {
		 cbi(PORTC,i);
		 return 4*i+1;
	 }
	 else if(bit_is_set(PINC,5))
	 	 {
	 		 cbi(PORTC,i);
	 		 return 4*i +2;
	 	 }
	 else if(bit_is_set(PINC,6))
	 	 {
	 		 cbi(PORTC,i);
	 		 return 4*i +3;
	 	 }
	 else if(bit_is_set(PINC,7))
	 	 {
	 		 cbi(PORTC,i);
	 		 return 4*i+4;
	 	 }
	 cbi(PORTC,i);
 }
 return 0;
}


void task_1() // zapalanie diody dolnym rzedem
{
		DDRD=0xff;
		PORTD=0x00;
		DDRC=0b00001111;
		PORTC=0xff;
		while(1)
		{
		if (bit_is_set(PINC,7))
		{
			sbi(PORTD, PD6);
		}
		else
		{
			cbi(PORTD, PD6);
		}
		}
}

void task_2(){ // zmiana kierunku dolnym rzedem,funckja moze wymagac mocniejszego wcisniecia przycisku by zadzialala
	DDRD=0xFF;
	PORTD=0x00;
	DDRC=0b00001111;
	PORTC=0xff;
	int i=0,ksi=1;
	while(1)
	    {
	    for(i=0;i<8;i=i+ksi)
	      {
	    	if (i<0 || i>8){ksi=ksi*(-1);continue;}
	    	if (bit_is_set(PINC,7)){ksi=ksi*(-1);}
	      sbi(PORTD,i);
	      _delay_ms(2500);
	      cbi(PORTD,i);
	      }
	    for(i=8;i>0;i=i-ksi)
	      {
	    	if (i<0 || i>8){ksi=ksi*(-1);continue;}
	    	if (bit_is_set(PINC,7)){ksi=ksi*(-1);}
	    	sbi(PORTD,i);
	    	_delay_ms(2500);
	    	cbi(PORTD,i);
	      }
	    }
}

void task_3()
{
	DDRD=0xff;
		PORTD=0x00;
		DDRC=0b00001111;
		PORTC=0xff;
		while(1)
		{

			PORTD=getKey();
		}
}



int main()
    {

	task_3();

}

