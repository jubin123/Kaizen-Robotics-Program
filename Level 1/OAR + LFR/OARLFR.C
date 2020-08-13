#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRD=0b00000000; //Setting part D as an input part
DDRB=0b11111111; //Seting Part B as an Output part
PORTD=0b11111111; //Pulling up all the pins of part B
int c;
while(1)
{
c=PIND;
if(c==0b11111010) //No obstacle
PORTB=0b00001010; //Forward

if(c==0b11111011) 
PORTB=0b00000110;

if(c==0b11111110)
 PORTB=0b00001001;


if(c==0b11111000) 
PORTB=0b00000000;

if(c==0b11111001) 
PORTB=0b00000000;



if(c==0b11111111) //
{
PORTB=0b00011010;

}



}
}


                                                                                                                                                                                                                                    



