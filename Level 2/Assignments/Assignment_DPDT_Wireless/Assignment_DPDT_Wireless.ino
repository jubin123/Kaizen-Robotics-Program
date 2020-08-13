int f=0;
int re=1;
int l=2;
int r=3;
void setup() {
  Serial.begin(9600);

  pinMode(f,INPUT);
  pinMode(re,INPUT);
  pinMode(l,INPUT);
  pinMode(r,INPUT);
}

void loop() {

 if ((digitalRead(f)==1) && (digitalRead(re)==0))

{
  Serial.print('f');
}
 if ((digitalRead(re)==1) && (digitalRead(f)==0))

{
  Serial.print('R');
}
 if ((digitalRead(l)==1) && (digitalRead(r)==0))

{
  Serial.print('l');
}
 if ((digitalRead(r)==1) &&  (digitalRead(l)==0))

{
  Serial.print('r');
}
else
{
  Serial.print('s');  
}

}
