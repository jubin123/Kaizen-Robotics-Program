int rm1 = 0;
int rm2 = 1;
int lm1 = 2;
int lm2 = 3;
int lmen = 4;
int rmen = 5;

int buz = 6;
int lir = 15;
int rir = 16;
int oir = 17;
int cir = 14;

int Speed;


void setup() 
{
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(lmen, OUTPUT);
  pinMode(rmen, OUTPUT);
  
  pinMode(buz,OUTPUT);
  
  pinMode(lir,INPUT);
  pinMode(rir,INPUT);
  pinMode(oir,INPUT);
  pinMode(cir,INPUT);
}

void loop() 
{
  set_speed();
  line_follow();
}

void set_speed()
{
  if(digitalRead(cir) == 1)
  {
    Speed=255;
  }
  else
  {
    Speed=200;
  }
}

void line_follow()
{
  if(digitalRead(oir) == 1)
  {
    if((digitalRead(lir)==0) && (digitalRead(rir)==0))
    {
      forward();
      sbuz();
    }
    else if((digitalRead(lir)==1) && (digitalRead(rir)==0))
    {
      left();
      sbuz();
    }
    else if((digitalRead(lir)==0) && (digitalRead(rir)==1))
    {
      right();
      sbuz();
    }
    else if((digitalRead(lir)==1) && (digitalRead(rir)==1))
    {
      forward();
      bbuz();
    }
  }
  else
  {
    Stop();
    bbuz();
  }
}

void forward()
{
  digitalWrite(lm1, 1);
  digitalWrite(lm2, 0);
  digitalWrite(rm1, 1);
  digitalWrite(rm2, 0);
  analogWrite(lmen, Speed);
  analogWrite(rmen, Speed);
}

void right()
{
  digitalWrite(lm1, 1);
  digitalWrite(lm2, 0);
  digitalWrite(rm1, 0);
  digitalWrite(rm2, 1);
  analogWrite(lmen, Speed);
  analogWrite(rmen, Speed);  
}

void left()
{
  digitalWrite(lm1, 0);
  digitalWrite(lm2, 1);
  digitalWrite(rm1, 1);
  digitalWrite(rm2, 0);
  analogWrite(lmen, Speed);
  analogWrite(rmen, Speed);    
}

void Stop()
{
  digitalWrite(lm1, 0);
  digitalWrite(lm2, 0);
  digitalWrite(rm1, 0);
  digitalWrite(rm2, 0);
  analogWrite(lmen, Speed);
  analogWrite(rmen, Speed);    
}

void bbuz()
{
  digitalWrite(buz, 1);
}

void sbuz()
{
  digitalWrite(buz, 0);
}
