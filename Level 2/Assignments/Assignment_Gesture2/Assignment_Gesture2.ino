int lm1 = 24;
int lm2 = 25;
int rm1 = 0;
int rm2 = 1;
int arm11=13;
int arm12=14;
int arm21=15;
int arm22=16;

void forward()
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
}
void Stop()
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,0);
}
void Reverse()
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1);
}
void Right()
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1);
}
void Left()
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
}
void arm1f()
{
  digitalWrite(arm11,1);
  digitalWrite(arm12,0);
}
void arm1r()
{
  digitalWrite(arm11,0);
  digitalWrite(arm12,1);
}
void arm2f()
{
  digitalWrite(arm21,1);
  digitalWrite(arm22,0);
}
void arm2r()
{
  digitalWrite(arm21,0);
  digitalWrite(arm22,1);
}

void setup() {
  Serial.begin(9600);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(arm11,OUTPUT);
  pinMode(arm12,OUTPUT);
  pinMode(arm21,OUTPUT);
  pinMode(arm22,OUTPUT);
}

void loop() {
  while(!Serial.available());
  char c = Serial.read();
  Serial.println(c);
  if(c=='f')
  forward();
  if(c=='s')
  Stop();
  if(c=='R')
  Reverse();
  if(c=='l')
  Left();
  if(c=='r')
  Right();
  if(c=='z')
  arm1f();
  if(c=='y')
  arm1r();
  if(c=='x')
  arm2f();
  if(c=='w')
  arm2r();

}
