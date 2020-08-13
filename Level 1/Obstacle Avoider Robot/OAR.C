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
if(c==0b11111111) //No obstacle
PORTB=0b00001010; //Forward
if(c==0b11111110) //Obstacle to the right
PORTB=0b00000110; //Turn Left
if(c==0b11110101)
{
PORTB=0b00000101; //Go back and turn right
_delay_ms(300);
PORTB=0b00001001;
_delay_ms(300);
}
if(c==0b11111101) //Obstacle at the center
{
PORTB=0b00000101; //Go back and turn right
_delay_ms(300);
PORTB=0b00000110;
_delay_ms(300);
}
if(c==0b11111100) //Obstacle to the center and right
{
PORTB=0b00000101; //Go back and turn left
_delay_ms(300);
PORTB=0b00000110;
_delay_ms(300);
}
if(c==0b11111011) //Obstacle to the left
PORTB=0b00001001; //Turn Right
if(c==0b11111010) //Obstacle on both sides of the robot
{
PORTB=0b00000101;//Go back and turn right
_delay_ms(300);
PORTB=0b00000110;
_delay_ms(300);
}
if(c==0b11111001) //Obstacle on the center and left
{
PORTB=0b00000101; //Go back and turn right
_delay_ms(300);
PORTB=0b00001001;
_delay_ms(300);
}
if(c==0b11111000) //Obstacle on all sides

{
                                                                                                                                                                                                                                    

PORTB=0b00001001;
_delay_ms(2000);
}
}
}