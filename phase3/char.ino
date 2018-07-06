#include <SoftwareSerial.h>
SoftwareSerial myserial (0,1);
String x ;
char z = 'w'  ;
float y    ;   

void setup() {
pinMode ( 13 , OUTPUT );
myserial.begin(9600);
Serial.begin(9600);

}

void loop() {
if (myserial.available() )
{
  
  z = myserial.read() ;
  Serial.write(myserial.read());
 

if ( z != ' ' )
      x = x + z; 
      else{
 y = x.toFloat();
     Serial.print (y);
     x = "";
      }
                
}
}
