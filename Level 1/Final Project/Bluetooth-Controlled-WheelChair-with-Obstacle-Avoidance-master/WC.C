#define F_CPU 1000000UL
#define  Trigger_pin	PA0	
#include <avr/interrupt.h>
#include<avr/io.h>
#include<util/delay.h>
#include <string.h>
#include <stdlib.h>
#define BAUDRATE 4800 // macros defining the baud rate

#define myubrr ((F_CPU/(BAUDRATE*16UL))-1) //macros to initialise UBRR value
  
void uart_init() //function to initialise UART
{
UBRRH= (myubrr>>8);
UBRRL= myubrr;
UCSRB= UCSRB | (1<<RXEN); //enable receiver
}

unsigned int UART_RECEIVE() //function to receive data
{
while((UCSRA&(1<<RXC))==0); //wait while data is being received

return(UDR); //return 8-bit data
}

int TimerOverflow = 0;

ISR(TIMER1_OVF_vect)
{
	TimerOverflow++; 



} 
long count;
double distance;
void main () //main
{ DDRA = 0x01;
unsigned char value; // declaring a variable ot save received data

DDRB=0b11111111; //Sets PB6,PB7 as output
uart_init(); //calling the function uart_init
_delay_ms(50); //a small delay, just like that
 


sei();                       
TIMSK = (1 << TOIE1);	/* Enable Timer1 overflow interrupts */
TCCR1A = 0;		/* Set all bit to zero Normal operation */

while(1)
{
value=UART_RECEIVE(); //save the received data in the variable

if(value=='F') //if data received is 'w'
PORTB=0b000001010; //Go forward

else if(value=='B') //if data received is 's'
PORTB=0b00000101; //Go reverse

else if(value=='L') //if data received is 'a'
PORTB=0b00001001; //Go left

else if(value=='R') //if data received is 'd'
PORTB=0b00000110; //Go right

else 
{PORTB=0b00000000;}

		/* Give 10us trigger pulse on trig. pin to HC-SR04 */
PORTA |= (1 << Trigger_pin); 
_delay_ms(10);
PORTA &= (~(1 << Trigger_pin));
TCNT1 = 0;	/* Clear Timer counter */
TCCR1B = 0x41;	/* Capture on rising edge, No prescaler*/
TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */

/*Calculate width of Echo by Input Capture (ICP) */
while ((TIFR & (1 << ICF1)) == 0);/* Wait for rising edge */
TCNT1 = 0;	/* Clear Timer counter */
TCCR1B = 0x01;	/* Capture on falling edge, No prescaler */
TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */
TimerOverflow = 0;/* Clear Timer overflow count */
while ((TIFR & (1 << ICF1)) == 0);/* Wait for falling edge */
count = ICR1 + (65535 * TimerOverflow);	/* Take count */
/* 8MHz Timer freq, sound speed =343 m/s */
distance = (double)count / 466.47;
if(distance<=5)
  { PORTB=0b00000000;
 _delay_ms(1000);
 PORTB=0b00000101;
  _delay_ms(1000);
 
} 
}
}

		
 //end of while
