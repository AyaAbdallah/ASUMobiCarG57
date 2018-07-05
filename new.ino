int EN1 = 6;
int EN2 = 3;
int IN1 = 2;
int IN2 = 4;
int IN3 = 5;
int IN4 = 7;
#include <SoftwareSerial.h>
SoftwareSerial myserial (0,1);
char Move = 'w';
int echo = 8;
int trig =9;
float di=0;
float distance=0;
const int PinL =10;
const int PinC = 11;
const int PinR = 12; 
int LState = 0;
int CState = 0;
int RState = 0; 
int x = 0;

void setup() {

pinMode ( IN1 , OUTPUT );
 pinMode ( IN2 , OUTPUT);
 pinMode ( EN1 , OUTPUT ); 
 pinMode ( EN2 , OUTPUT );
 pinMode ( IN3 , OUTPUT );
 pinMode ( IN4 , OUTPUT);
 pinMode (13 , OUTPUT );
myserial.begin(9600);
Serial.begin(9600);
 pinMode (echo , INPUT );
 pinMode( trig , OUTPUT );
 pinMode(PinL, INPUT);
 pinMode(PinC, INPUT);
 pinMode(PinR, INPUT);
 
}

void loop() {
   analogWrite ( EN1 , 72 );
  analogWrite ( EN2 , 90);

if(myserial.available())
{
  Move = myserial.read() ;
  Serial.write(myserial.read());
  
  if (Move == 'A')
  {
      while ( Move != 'z')
      {
  Move = myserial.read() ;
  Serial.write(myserial.read());
  
  while (  Move == 'f')
       {
      
    digitalWrite ( trig , LOW );
  delayMicroseconds (2);
  digitalWrite ( trig , HIGH );
  delayMicroseconds (10);
  digitalWrite ( trig , LOW );
  
  di = pulseIn (echo , HIGH );
  distance = di*0.034/2;
  
  if ( distance <= 12 )
  {
          digitalWrite (13, LOW);
    digitalWrite( IN1 ,LOW );
  digitalWrite( IN4 ,LOW );  
  digitalWrite (IN2, LOW );
  digitalWrite( IN3 ,LOW );  
    }else 
    {
      digitalWrite (13, HIGH);
    digitalWrite( IN1 ,LOW );
  digitalWrite( IN4 ,HIGH );  
  digitalWrite (IN2, HIGH );
  digitalWrite( IN3 ,LOW );
      }
 if(myserial.available())
  Move = myserial.read() ; 

}

  if ( Move == 's')
  {
  digitalWrite( IN1 ,LOW );
  digitalWrite( IN4 ,LOW );  
  digitalWrite (IN2, LOW );
  digitalWrite( IN3 ,LOW );

    } 
    
     if (Move == 'b')
    {
   digitalWrite( IN1 ,HIGH );
  digitalWrite( IN4 ,LOW );  
  digitalWrite (IN2, LOW );
  digitalWrite( IN3 ,HIGH );
      }
      
  if (Move == 'r')
  {
    digitalWrite( IN1 ,LOW );
  digitalWrite( IN4 ,LOW );  
  digitalWrite (IN2, HIGH );
  digitalWrite( IN3 ,LOW );
  
    }
    
   if (Move == 'l')   
    {
  digitalWrite( IN1 ,LOW );
  digitalWrite( IN4 ,HIGH );  
  digitalWrite (IN2, LOW );
  digitalWrite( IN3 ,LOW );
      
      }

      }
    if(myserial.available())
  Move = myserial.read() ; 
  }
  
   if ( Move == 'T')
    {
  while ( Move != 'z')
      {
  LState = digitalRead(PinL);
 CState = digitalRead(PinC);
 RState = digitalRead(PinR);


//black ... Low   // white ... HIGH
 if ( RState == HIGH && CState ==LOW && LState == HIGH )//forward
   {
      x=3;
             digitalWrite( IN1 ,LOW );
             digitalWrite( IN4 ,HIGH );  
             digitalWrite (IN2, HIGH );
               digitalWrite( IN3 ,LOW );
   }
  else if ( RState == HIGH &&CState == HIGH && LState == LOW )//Left
   {
       x=2;
                digitalWrite( IN1 ,HIGH );
                 digitalWrite( IN4 ,HIGH );  
                  digitalWrite (IN2, LOW );
                  digitalWrite( IN3 ,LOW );
    } 
    else if ( RState == LOW && CState == HIGH && LState == HIGH )//right
    {
          x=1;
           digitalWrite( IN1 ,LOW );
          digitalWrite( IN4 ,LOW );  
           digitalWrite (IN2, HIGH );
             digitalWrite( IN3 ,HIGH );
      }
  else
  {
         if ( x == 1 )//Right
         {
         digitalWrite( IN1 ,LOW );
          digitalWrite( IN4 ,LOW );  
           digitalWrite (IN2, HIGH );
             digitalWrite( IN3 ,LOW );
            }
            else if ( x == 2 )//Left
            {
               digitalWrite( IN1 ,LOW );
                 digitalWrite( IN4 ,HIGH );  
                  digitalWrite (IN2, LOW );
                  digitalWrite( IN3 ,LOW ); 
              }
           else if (x == 3 )//forward
              {
                 digitalWrite( IN1 ,LOW );
             digitalWrite( IN4 ,HIGH );  
             digitalWrite (IN2, HIGH );
               digitalWrite( IN3 ,LOW );     
                }  
  }
             }
    }
    
}  

  
}
 
