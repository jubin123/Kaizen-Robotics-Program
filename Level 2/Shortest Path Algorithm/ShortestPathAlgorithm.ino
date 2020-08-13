char reshortn[30];
char directions[30];
char shortn[30];
#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
int rm1= 24;
int rm2= 25;
int lm1= 0;
int lm2= 1;
int l,c1,c2,c3,r;
int i=0;
int k=0;
int j=0;
int tdelay= 500;
int fdelay= 60;
int udelay= 1450;
void Stop() 
{
  
digitalWrite(lm1,0);
digitalWrite(lm2,0);
digitalWrite(rm1,0);
digitalWrite(rm2,0);
}
void forward()
{
digitalWrite(lm1,1);
digitalWrite(lm2,0);
digitalWrite(rm1,1);
digitalWrite(rm2,0);
}
void smallright()
{
digitalWrite(lm1,1);
digitalWrite(lm2,0);
digitalWrite(rm1,0);
digitalWrite(rm2,0);
}
void smallleft() 
{
digitalWrite(lm1,0);
digitalWrite(lm2,0);
digitalWrite(rm1,1);
digitalWrite(rm2,0);
}
void right()
{
digitalWrite(lm1,1);
digitalWrite(lm2,0);
digitalWrite(rm1,0);
digitalWrite(rm2,1);
}
void left() 
{
digitalWrite(lm1, 0);
digitalWrite(lm2, 1);
digitalWrite(rm1, 1);
digitalWrite(rm2, 0);
}
int eosens() //Function to simplify sensor values after performing "inch".
{
  readsens();
  if(((c1+c2+c3)==1)||((c1+c2+c3)==2))
  return  1;
  else
  return 0;
}
void readsens() //Reads the sensor Values.
{
  l=digitalRead( 26 );
  c1=digitalRead(27);
  c2=digitalRead( 28);
  c3=digitalRead( 29);
  r=digitalRead( 30);
  lcd.print(l);
  lcd.print(" ");
  lcd.print(c1);
  lcd.print(" ");
  lcd.print(c2);
  lcd.print(" ");
  lcd.print(c3);
  lcd.print(" ");
  lcd.print(r);
  lcd.print(" ");
}
void inch()
{
  lcd.print("inch function");
  Stop();
  delay(100);
  forward();
  delay(500);
  Stop();
  delay(100);
  readsens();
  lcd.clear();
}
void align()
{
 Stop();
 delay(500);
 forward();
 delay(60);
 Stop();
 delay(100);
 lcd.clear();
 readsens();
}
void printing(char prtdirection[])
{
  lcd.clear();
  for(i=0;prtdirection[i]!='E';i++)
  {
    lcd.print(prtdirection[i]);
  }
  delay(2000);
  }
void setup()
{
  lcd.begin(16,2);
  lcd.print("MSR with LHR");
  delay(500);
  lcd.clear();
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(26,INPUT);
  pinMode(27,INPUT);
  pinMode(28,INPUT);
  pinMode(29,INPUT);
  pinMode(30,INPUT);
}
void loop() 
{
lcd.clear();
readsens();
lcd.clear();
//LINE FOLLOWER
//FORWARD DIRECTION
if ((l==1)&&(c1==1)&&(c2==0)&&(c3==1)&&(r==1))
{
  lcd.print("FORWARD");
  forward();
}
//LEFT
else if (((l==1 )&&(c1== 0)&&(c2==0)&&(c3==1)&&(r==1))||((l==1 )&&(c1==0 )&&(c2==1)&&(c3==1)&&(r==1)))
{
  lcd.print("LEFT");
  smallleft();//small left
}
//RIGHT
else if (((l==1 )&&(c1==1 )&&(c2==1)&&(c3==0)&&(r==1))||((l==1 )&&(c1==1 )&&(c2==0)&&(c3==0)&&(r==1)))
{
  lcd.print("RIGHT");
  smallright();//small right
  }
  //DEAD END
  else if ((l==1 )&&(c1== 1)&&(c2==1)&&(c3==1)&&(r==1))
  {
    lcd.print("U TURN");
    left();
    delay(udelay);
    directions[i]='U';
    i++;
  }
  //DECISIONS MADE TO MOVE IN A 2WAY INTERSECTION(right)
    else if (((l== 0)&&(c1==0 ))||((c3==0)&&(r==0)))
   {
    align();
    if (((l==1 )&&(c1==1 )&&(c2==0)&&(c3==0)&&(r==0))||((l==1 )&&(c1==0 )&&(c2==0)&&(c3==0)&&(r==0)))
    {
      lcd.print("RT/Strt n rt?");
      inch();
     if ((l== 1)&&(c1==1 )&&(c2==1)&&(c3==1)&&(r==1))
     {
      lcd.print("right");
      right();
      delay(tdelay);
     }
     else if ((l== 1 )&&(r== 1 )&&(eosens() ))
     {
      lcd.print("STRAIGHT");
      directions[i]='S';
      i++;
      forward();
      delay(fdelay);
     }
    }
//DECISIONS MADE TO MOVE IN 2 WAY INTERSECTION (left)
     else if (((l==0 )&&(c1==0 )&&(c2==0)&&(c3==1)&&(r==1))||((l==0)&&(c1==0 )&&(c2==0)&&(c3==0)&&(r==1)))
     {
      lcd.print("Lft/str n lft?");
     inch();
    if ((l== 1)&&(c1==1 )&&(c2==1)&&(c3==1)&&(r==1))
    {
      lcd.print("LEFT");
    left();
    delay(tdelay); 
     }
      else if ((l== 1 )&&(r== 1 )&&(eosens() ))
      {
        lcd.print("LEFT");
        directions[i]='L';
        i++;
        left();
        delay(tdelay);
      }
    }
//4way Intersection/T Intersection/End
  else if ((l==0 )&&(c1==0 )&&(c2==0)&&(c3==0)&&(r==0))
  {
    lcd.print("T/END/4");
    inch();
    if ((l==1)&&(r==1 )&&(eosens()))
      {
        lcd.print("4 WAY");
      directions[i]='L';
      i++;
      left();
      delay(tdelay);
  }
   else if ((l== 1)&&(c1==1 )&&(c2==1)&&(c3==1)&&(r==1))
   {
    lcd.print("T-int");
    directions[i]='L';
    i++;
    left();
    delay(tdelay);
   }

else if ((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0))
{
  lcd.print("END OF MAZE");
  directions[i]='E';
  printing(directions);
  Stop();
  delay(5000);
  lcd.clear();
  replacement(directions);
}
}
}
}
//SHORTEST PATH ALGORITHM
void replacement(char shortn[])
{
  lcd.print("ENTERED REPLACEMENT");
  delay(1000);
  lcd.clear();
for(i=0;shortn[i]!='E';i++) //Loop to eliminate unnecessary turns.
{
  if(shortn[i]=='U')
{
   if((shortn[i-1]=='S')&&(shortn[i+1]=='L'))
   {
   shortn[i-1]='X';
   shortn[i]='X';
   shortn[i+1]='R';
   }
   else if ((shortn[i-1]=='L')&&(shortn[i+1]=='L'))
    {
   shortn[i-1]='X';
   shortn[i]='X';
   shortn[i+1]='S';
   }
    else if ((shortn[i-1]=='L')&&(shortn[i+1]=='S'))
    {
   shortn[i-1]='X';
   shortn[i]='X';
   shortn[i+1]='R';
   }
     else if ((shortn[i-1]=='L')&&(shortn[i+1]=='R'))
    {
   shortn[i-1]='X';
   shortn[i]='X';
   shortn[i+1]='U';
   }
     else if ((shortn[i-1]=='R')&&(shortn[i+1]=='L'))
    {
   shortn[i-1]='X';
   shortn[i]='X';
   shortn[i+1]='U';
   }
     else if ((shortn[i-1]=='S')&&(shortn[i+1]=='S'))
    {
   shortn[i-1]='X';
   shortn[i]='X';
   shortn[i+1]='U';
   }
  }
  }
lcd.clear();
lcd.print("FINISHED NEW PATH");
delay(1000);
lcd.print("NEW:");
j=0;
for(i=0;shortn[i]!='E';i++)
{
  if(shortn[i]!='X')
  {
    reshortn[j]=shortn[i];
    j++;
  }
}
reshortn[j]='E';
lcd.print("SPA=");
printing(reshortn);
delay(1000);
for(i=0;reshortn[1]!='E';i++)
{
  if(reshortn[i]=='U')
  {
    replacement(reshortn);
    }
else
{
lcd.clear();
lcd.print("FINAL=");
printing(reshortn);
final();
} //End of shortening string.
void decisions()
{
  lcd.print("ENTERD DECISIONS");
  lcd.clear();
  if (reshortn[k]=='S')
  {
    forward();
    delay(fdelay);
    }
    else if (reshortn[k]=='L')
  {
    left();
    delay(tdelay);
    }
     else if (reshortn[k]=='R')
  {
    right();
    delay(tdelay);
    }
    k++;
}
void final() //Moves in the shortest path.
{
  lcd.clear();
  lcd.print("ENTERED FINAL");
  while(1)
  {
    readsens();
    if ((l==1)&&(c1==1)&&(c2==0)&&(c3==1)&&(r==1))
{
  forward();
}
else if (((l==1 )&&(c1== 0)&&(c2==0)&&(c3==1)&&(r==1))||((l==1 )&&(c1==0 )&&(c2==1)&&(c3==1)&&(r==1)))
{
  smallleft();
}
else if (((l==1 )&&(c1==1 )&&(c2==1)&&(c3==0)&&(r==1))||((l==1 )&&(c1==1 )&&(c2==0)&&(c3==0)&&(r==1)))
{
  smallright();
  }
  else if (((l== 0)&&(c1==0 ))||((c3==0)&&(r==0)))
   {
    align();
    if (((l==1 )&&(c1==1 )&&(c2==0)&&(c3==0)&&(r==0))||((l==1 )&&(c1==0 )&&(c2==0)&&(c3==0)&&(r==0)))
    {
      inch();
     if ((l== 1)&&(c1==1 )&&(c2==1)&&(c3==1)&&(r==1))
     {
      right();
      delay(tdelay);
     }
     else if ((l== 1 )&&(r== 1 )&&(eosens() ))
     {
      decisions();
      }
      }
     else if (((l==0 )&&(c1==0 )&&(c2==0)&&(c3==1)&&(r==1))||((l==0)&&(c1==0 )&&(c2==0)&&(c3==0)&&(r==1)))
     {
     inch();
    if ((l== 1)&&(c1==1 )&&(c2==1)&&(c3==1)&&(r==1))
    {
      lcd.print("=LEFT");
    left();
    delay(tdelay); 
     }
      else if ((l== 1 )&&(r== 1 )&&(eosens() ))
      {
        lcd.print("=stnlt"); 
          decisions();
       }
}
else if ((l==0 )&&(c1==0 )&&(c2==0)&&(c3==0)&&(r==0))
  {
    inch();
    if ((l==1)&&(r==1 )&&(eosens()))
      {
        decisions();
      }
      }
else if ((l== 1)&&(c1==1 )&&(c2==1)&&(c3==1)&&(r==1))
{
  decisions();
 }
 else if ((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0)) 
{
  while(1)
  {
    Stop();
  }
}}}}
