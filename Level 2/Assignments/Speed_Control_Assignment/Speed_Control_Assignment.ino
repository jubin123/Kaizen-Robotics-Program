int lm1 = 24;
int lm2 = 25;
int rm1 = 0;
int rm2 = 1;
int ena = 12;
int enb = 13;

void Forward()
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
  analogWrite(ena,255);
  analogWrite(enb,255);
}
void ForwardS()
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
  analogWrite(ena,100);
  analogWrite(enb,100);
}
void Stop()
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,0);
  analogWrite(ena,255);
  analogWrite(enb,255);  
}
void Reverse()
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1);
  analogWrite(ena,255);
  analogWrite(enb,255);  
}
void ReverseS()
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1);
  analogWrite(ena,100);
  analogWrite(enb,100);
}
void Right()
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1);
  analogWrite(ena,255);
  analogWrite(enb,255);  
}
void RightS()
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1);
  analogWrite(ena,100);
  analogWrite(enb,100);  
}
void Left()
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
  analogWrite(ena,255);
  analogWrite(enb,255);  
}
void LeftS()
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
  analogWrite(ena,100);
  analogWrite(enb,100);
}
void setup() {
  Serial.begin(9600);

  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);

}

void loop() {
char c = Serial.read();
 
  if(c=='W')
  Forward();
  
  if(c=='w')
  ForwardS(); 
  
  if(c=='S')
  Reverse();
  
  if(c=='s')
  ReverseS();
  
  if(c=='D')
  Right();
  
  if(c=='d')
  RightS();
  
  if(c=='A')
  Left();
  
  if(c=='a')
  LeftS();

  if(c=='x')
  Stop();
}
