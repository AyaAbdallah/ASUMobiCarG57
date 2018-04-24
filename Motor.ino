int EN1 = 6;
int EN2 = 3;
int IN1 = 2;
int IN2 = 4;
int IN3 = 5;
int IN4 = 7;
#include <SoftwareSerial.h>
SoftwareSerial myserial (8,9);
char Move = 'g' ;
char Move1 = 'z' ;
const int PinL =10;
const int PinC = 11;
const int PinR = 12; 
int echo = 0;
int trig =1;
int LState = 0;
int CState = 0;
int RState = 0; 

/////////////////////////////////////////

void setup() {
 pinMode ( IN1 , OUTPUT );
 pinMode ( IN2 , OUTPUT);
 pinMode ( EN1 , OUTPUT ); 
 pinMode ( EN2 , OUTPUT );
 pinMode ( IN3 , OUTPUT );
pinMode (13 , OUTPUT);
 pinMode ( IN4 , OUTPUT);
myserial.begin(9600);
Serial.begin(9600);
pinMode(PinL, INPUT);
 pinMode(PinC, INPUT);
 pinMode(PinR, INPUT);
 pinMode (echo , INPUT );
 pinMode( trig , OUTPUT );
}

void loop() {
  analogWrite ( EN1 , 70 );
  analogWrite ( EN2 , 70);

if(myserial.available())
{
  Move = myserial.read() ;
  Serial.write(myserial.read());
  
  if (  Move == 'f'  )
  {
   
   digitalWrite( IN1 ,LOW );
  digitalWrite( IN4 ,HIGH );  
  digitalWrite (IN2, HIGH );
  digitalWrite( IN3 ,LOW );

  }
  else if ( Move == 's')
  {
  digitalWrite( IN1 ,LOW );
  digitalWrite( IN4 ,LOW );  
  digitalWrite (IN2, LOW );
  digitalWrite( IN3 ,LOW );

    } 
    else if (Move == 'b')
    {
   digitalWrite( IN1 ,HIGH );
  digitalWrite( IN4 ,LOW );  
  digitalWrite (IN2, LOW );
  digitalWrite( IN3 ,HIGH );
      }
  else if (Move == 'r')
  {
    digitalWrite( IN1 ,LOW );
  digitalWrite( IN4 ,LOW );  
  digitalWrite (IN2, HIGH );
  digitalWrite( IN3 ,LOW );
  
    }
    else if (Move == 'l')   
    {
  digitalWrite( IN1 ,LOW );
  digitalWrite( IN4 ,HIGH );  
  digitalWrite (IN2, LOW );
  digitalWrite( IN3 ,LOW );
      
      }
}
/////////////////////
 LState = digitalRead(PinL);
 CState = digitalRead(PinC);
 RState = digitalRead(PinR);

while ( 1 )//black
 {
   if ((RState==LOW && CState == HIGH&& LState == HIGH)|| (RState== LOW && CState == LOW && LState == HIGH) )
  {
      Serial.print("LEFT");
      digitalWrite( IN1 ,HIGH );
  digitalWrite( IN4 ,HIGH );  
  digitalWrite (IN2, LOW );
  digitalWrite( IN3 ,LOW );
  break;
    }
    else if ((RState==HIGH && CState == HIGH&& LState == LOW)|| (RState== HIGH && CState == LOW && LState == LOW)  )
    {
          
        Serial.print("RIGHT");
   digitalWrite( IN1 ,LOW );
  digitalWrite( IN4 ,LOW );  
  digitalWrite (IN2, HIGH );
  digitalWrite( IN3 ,HIGH );
       break;

      }
      else
      {

        Serial.print("forward");
   digitalWrite( IN1 ,LOW );
  digitalWrite( IN4 ,HIGH );  
  digitalWrite (IN2, HIGH );
  digitalWrite( IN3 ,LOW );
             break;
        }
    }
  /////////////////////////////////
  digitalWrite ( trig , LOW );
  delayMicroseconds (3);
  digitalWrite ( trig , HIGH );
  delayMicroseconds (3);
  digitalWrite ( trig , LOW );

  pinMode ( echo , INPUT ); 
  long di = pulseIn (echo , HIGH );
  long distance = (di/2)/29;

  if ( distance < 0.5 )
  {
    digitalWrite( IN1 ,LOW );
  digitalWrite( IN4 ,LOW );  
  digitalWrite (IN2, LOW );
  digitalWrite( IN3 ,LOW );  
    }


}
