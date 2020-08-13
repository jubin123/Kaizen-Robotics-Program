const int xpin=A0;
const int ypin=A1;
int a,b;

int rm1=0;
int rm2=1;
int lm1=24;
int lm2=25;

void setup() {
  Serial.begin(9600);
  a=analogRead(xpin);
  Serial.print(a);
  Serial.print('\t');
  b=analogRead(ypin);
  Serial.println(b);

  pinMode(rm1,INPUT);
  pinMode(rm2,INPUT);
  pinMode(lm1,INPUT);
  pinMode(lm2,INPUT);
}

void loop() {
 int x=analogRead(xpin);
 int y=analogRead(ypin);

 if (((x<=(426))&&(x>=(366))) && ((y<=(436)) && (y>=(376))))
{
  Serial.print('s');
}
 if ((y<=(388)) && (y>=(380)))

{
  Serial.print('f');
}
 if ((y<=(475)) && (y>=(415)))

{
  Serial.print('R');
}
 if ((x<=(458)) && (x>=(398)))

{
  Serial.print('l');
}
 if ((x<=(365)) && (x>=(305)))

{
  Serial.print('r');
}
}
