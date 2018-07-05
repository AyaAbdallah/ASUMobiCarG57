int EN1 = 6;
int EN2 = 3;
int IN1 = 2;
int IN2 = 4;
int IN3 = 5;
int IN4 = 7;
#include <SoftwareSerial.h>
SoftwareSerial myserial (0,1);
char Move = 'g' ;
char Move1 = 'z' ;
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
pinMode (13 , OUTPUT);
 pinMode ( IN4 , OUTPUT);
myserial.begin(9600);
Serial.begin(9600);
pinMode(PinL, INPUT);
 pinMode(PinC, INPUT);
 pinMode(PinR, INPUT);

}

void loop() {
  analogWrite ( EN1 , 90);
  analogWrite ( EN2 , 90 );

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
        
        



/*else //if (RState == HIGH && LState == LOW || Rstate == LOW && LState == HIGH || Rstate == HIGH && LState == HIGH )
   {
          if ( x == 1 )// Right
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
             
  }*/
/*if ( RState == LOW && LState == HIGH )//Right
  {
    x=1;
  }
    else if ( LState == LOW  && RState == HIGH )//left
   {
      x=2;
    } 
   else/*/
