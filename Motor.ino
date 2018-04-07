int EN1 = 7;
int EN2 =2;
int IN1 = 3;
int IN2 = 4;
int IN3 = 5;
int IN4 = 6;
#include <SoftwareSerial.h>
SoftwareSerial myserial (8,9);
char Move = 'g' ;
char Move1 = 'z' ;


void setup() {

 pinMode ( IN1 , OUTPUT );
 pinMode ( IN2 , OUTPUT);
 pinMode ( EN1 , OUTPUT ); 
 pinMode ( EN2 , OUTPUT );
 pinMode ( IN3 , OUTPUT );
 pinMode ( IN4 , OUTPUT);
myserial.begin(9600);
Serial.begin(9600);

}

void loop() {
  digitalWrite ( EN1 , HIGH);
  digitalWrite ( EN2 , HIGH);

if(myserial.available())
{
  Move = myserial.read() ;
  Serial.write(myserial.read());
  
  if (  Move == 'f'  )
  {
   digitalWrite( IN1 ,HIGH );
  digitalWrite( IN4 ,HIGH );  
  digitalWrite (IN2, LOW );
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
   digitalWrite( IN1 ,LOW );
  digitalWrite( IN4 ,LOW );  
  digitalWrite (IN2, HIGH );
  digitalWrite( IN3 ,HIGH );
      }
  else if (Move == 'r')
  {
    digitalWrite( IN1 ,HIGH );
  digitalWrite( IN4 ,LOW );  
  digitalWrite (IN2, LOW );
  digitalWrite( IN3 ,HIGH );
  
    }
    else if (Move == 'l')
    {
  digitalWrite( IN1 ,LOW );
  digitalWrite( IN4 ,HIGH );  
  digitalWrite (IN2, HIGH );
  digitalWrite( IN3 ,LOW );
      
      }
}
   
}
