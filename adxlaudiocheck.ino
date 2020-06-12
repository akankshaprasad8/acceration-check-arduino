

int a=1;
int b=1;
int c=1;
int d=1;
int e=1;
int f=1;
int GNDPin=A4;
int VccPin=A5; 
int xPin=A3; 
int yPin=A2; 
int zPin=A1; 
long x; 
long y; 
long z; 
int cmd=0x90;
int velocity=0x45;
void setup()
{
  Serial.begin(115200);
  pinMode(GNDPin, OUTPUT);
  pinMode(VccPin, OUTPUT);
  digitalWrite(GNDPin, LOW); 
  digitalWrite(VccPin, HIGH); 
}
void loop()
{
  x = analogRead(xPin); 
  y = analogRead(yPin); 
  z = analogRead(zPin);
  Serial.print("x=");
  Serial.println(x);
  Serial.print("y=");
  Serial.println(y);
  Serial.print("z=");
  Serial.println(z);
   if(x<340)
   {
      if(a==1)
      {    
      Serial.println("audio 1");
       Serial.write(cmd);
  Serial.write(0x1E);
  Serial.write(velocity);
     Serial.write(cmd);
  Serial.write(0x1E);
  Serial.write(0x00);
       }
      a=0;
      b=1;
      c=1;
      d=1;
      e=1;
      f=1;
   }
    else if(x>400) 
    { if(b==1)
    {
      Serial.println("audio 2");
      Serial.write(cmd);
  Serial.write(0x1F);
  Serial.write(velocity);
     Serial.write(cmd);
  Serial.write(0x1F);
  Serial.write(0x00);
    }
    b=0;
    c=1;
    a=1;
    d=1;
    e=1;
    f=1;
    }
    else if(y>400) 
    { if(c==1)
      {Serial.println("audio 3");
      Serial.write(cmd);
  Serial.write(0x20);
  Serial.write(velocity);
     Serial.write(cmd);
  Serial.write(0x20);
  Serial.write(0x00);
      }
      c=0;
      a=1;
      b=1;
      d=1;
      e=1;
      f=1; 
    }
    else if(y<340) 
    { if(d==1)
    {
      Serial.println("audio 4");
      Serial.write(cmd);
  Serial.write(0x21);
  Serial.write(velocity);
  delay(100);
     Serial.write(cmd);
  Serial.write(0x21);
  Serial.write(0x00);
  delay(100);
    }
    d=0;
    c=1;
    b=1;
    a=1;
    e=1;
    f=1;
    }
    else if(z<340)
   {if(e==1)
     {
      Serial.println(" audio 5");
      Serial.write(cmd);
  Serial.write(0x22);
  Serial.write(velocity);
     Serial.write(cmd);
  Serial.write(0x22);
  Serial.write(0x00);
     }
   e=0;
   d=1;
   c=1;
   b=1;
   a=1;
   f=1;
}

else
{
  if(f==1)
     {
      Serial.println(" audio 6");
     Serial.write(cmd);
  Serial.write(0x22);
  Serial.write(velocity);
     Serial.write(cmd);
  Serial.write(0x22);
  Serial.write(0x00);
     }
   f=0;
   d=1;
   c=1;
   b=1;
   a=1;
   e=1;
}
}
