 const int xpin=A0;
const int ypin=A1;
int a,b;

void setup() {
  Serial.begin(9600);
  a=analogRead(xpin);
  Serial.print(a);
  Serial.print('\t');
  b=analogRead(ypin);
  Serial.println(b);
}

void loop() {
 int x=analogRead(xpin);
 int y=analogRead(ypin);

 if (((x<=(465))&&(x>=(365))) && ((y<=(450)) && (y>=(350))))

{
  Serial.print('s');
}
 if ((y<=(515)) && (y>=415))

{
  Serial.print('f');
}
 if ((y<=(400)) && (y>=300))

{
  Serial.print('o');
}
 if ((x<=(515)) && (x>=415))

{
  Serial.print('r');
}
 if ((x<=(400)) && (x>=300))

{
  Serial.print('l');
}
}
 
