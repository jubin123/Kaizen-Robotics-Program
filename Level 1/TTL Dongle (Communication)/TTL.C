#define F_CPU 1000000UL //macros defining the F_CPU to 1 MHz

#define BAUDRATE 4800 // macros defining the baud rate

#define myubrr ((F_CPU/(BAUDRATE*16UL))-1) //macros to initialise UBRR value

#include<avr/io.h>
#include<util/delay.h>

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

void main () //main
{
unsigned char value; // declaring a variable ot save received data

DDRB=0b11111111; //Sets PB6,PB7 as output
uart_init(); //calling the function uart_init
_delay_ms(50); //a small delay, just like that

while(1)
{
value=UART_RECEIVE(); //save the received data in the variable

if(value=='F') //if data received is 'w'
PORTB=0b00001010; //Go forward

else if(value=='B') //if data received is 's'
PORTB=0b00000101; //Go reverse

else if(value=='L') //if data received is 'a'
PORTB=0b00000110; //Go left

else if(value=='R') //if data received is 'd'
PORTB=0b00001001; //Go right

else 
PORTB=0b00000000;

} //end of while
}//end of main