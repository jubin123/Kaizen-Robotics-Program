#include<avr/io.h>
#include<util/delay.h>

void init_adc() //ADC initialising function

{
ADCSRA = ADCSRA | (0b00000001<<ADEN); // ENable the ADC
ADCSRA = ADCSRA | (0b00000001<<ADPS2);  // Set the sampling rate
ADMUX = ADMUX | (0b00000001<<REFS0); // Set the reference voltage

}

unsigned int read_adc()
{
int p=0b00000000; //select the input pin
ADMUX = ADMUX | p; //ADMUX=01000000

ADCSRA = ADCSRA | 1<<ADSC; //Start conversion
while((ADCSRA&(0b00000001<<ADIF)) ==0) //Check for end conversion
{}
ADCSRA = ADCSRA | (0b00000001<<ADIF); //clear ADIF bit

return(ADC); //Get the output from ADC
}

void main()
{
DDRB=0b11111111; //Part B is output
init_adc(); //call the ADC initialising function
_delay_ms(500);
unsigned int a; //initialised as unsigned int as it relates to an analog input
unsigned int p;

unsigned int T;
unsigned int TON;
unsigned int TOFF;

while(1)
{
p=read_adc(); //Read the ADC input from ADC
a=(p/40); // scaling the total time period
T=25.6; //Total time period
TOFF=a; //ON Time based on the current Analog input
TON=T-TOFF; //OFF Time = Total Time Period - ON time

if(p<870)
{
PORTB=0b00001010;
_delay_ms(TON);
PORTB=0b00000000;
_delay_ms(TOFF);
}

else
PORTB=0b00000000;
}
}
