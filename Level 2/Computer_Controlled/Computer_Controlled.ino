#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

int lm1 = 24;
int lm2 = 25;
int rm1 = 0;
int rm2 = 1;

int e1 = 13;
int e2 = 14;
int w1 = 15;
int w2 = 16;

void Forward()
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

  digitalWrite(e1,0);
  digitalWrite(e2,0);
  digitalWrite(w1,0);
  digitalWrite(w2,0);
  
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
void elup()
{
  digitalWrite(e1,1);
  digitalWrite(e2,0);
}
void eldo()
{
  digitalWrite(e1,0);
  digitalWrite(e2,1);
}
void armup()
{
  digitalWrite(w1,1);
  digitalWrite(w2,0);
}
void armdo()
{
  digitalWrite(w1,0);
  digitalWrite(w2,1);
}

void setup() {
  
  Serial.begin(9600);

  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);

  pinMode(e1,OUTPUT);
  pinMode(e2,OUTPUT);
  pinMode(w1,OUTPUT);
  pinMode(w2,OUTPUT);

  lcd.begin(16,2);
  lcd.print("Initialising");
  delay(1000);
  
}

void loop() {
  lcd.clear();
  while(!Serial.available())
  {
  lcd.clear();
  lcd.print("Start");
  delay(50);
  Stop();
  }

  char c = Serial.read();
  Serial.println(c);
  lcd.print(c);
  //Getting data from the terminal
  if(c=='w') 
  Forward();
  
  if(c=='x')
  Stop(); 
  
  if(c=='s')
  Reverse();
  
  if(c=='a')
  Left();
  
  if(c=='d')
  Right();
  
  if(c=='i')
  elup();
  
  if(c=='k')
  eldo();
  
  if(c=='j')
  armup();
  
  if(c=='l')
  armdo();
  
  
  }
