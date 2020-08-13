#include<avr/io.h>
#include<util/delay.h>

void init_adc()
{
 ADCSRA = ADCSRA| (0b00000001<<ADEN);
 ADCSRA = ADCSRA |(0b00000001<<ADPS2);
 ADMUX = ADMUX | (0b00000001<< REFS0);
 }
 
unsigned int read_adc()
{
  int p = 0b00000000;
  ADMUX = ADMUX | p;
  ADCSRA = ADCSRA | (0b00000001<<ADSC);
  while((ADCSRA &(0b00000001<<ADIF)) ==0)
  {}
  ADCSRA = ADCSRA | (0b00000001<<ADIF);
  return(ADC);
  } void main()
  {
   DDRB=0b11111111;
   init_adc();
   
   _delay_ms(500);
   unsigned int a;
   unsigned int b;
   
   unsigned int T;
   unsigned int TON;
   unsigned int TOFF;
   DDRD=0b00000000;
   PORTD=0b11111111;
  int q;
  while(1)
 { q=PIND;
  if(q==0b11111100) // white surface and robot moving forward
    PORTB=0b00001010;
  if(q==0b11111110) // leftturn
    PORTB=0b00000110;
  if(q==0b11111101) //right turn
    PORTB=0b00001001;
  if(q==0b11111111)  // black surface , beep anf go forward
    PORTB=0b00011010;
  if(q==0b11111000) // object in front
     PORTB=0b00010000;
  if(q ==0b11110100) // wall sensor
    {  PORTB=0b00001010;// potentiometer getting supply
	    if(q==0b11110101)
		 { PORTB=0b00001001;}
		 if(q==0b11110110)
		 { PORTB=0b00000110;
		 }
		 if(q==0b11110111)
		  { PORTB=0b00011010;
		  }
  
    
  
  
  
  if (q ==0b11110111)
     { PORTB = 0b00011010; }
     b=read_adc();
	a=(b/40);
	T = 25.6;
	TOFF =a;
	TON = T - TOFF;
      if(b  <=870) //this value has to be changed according to the speed required
       {
         PORTB = 0b00001010;
	     _delay_ms(TON);
	     PORTB =0b00000000;
	     _delay_ms(TOFF);
       if(b<=870){  
		 
		 
		   
		 
		  
		  
        }}

   }
 }}