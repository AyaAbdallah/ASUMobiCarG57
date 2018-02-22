int LED_B= 4;
int LED_G= 5;
int LED_R= 6;
int LED_Y= 7;
void setup() {
  // put your setup code here, to run once:
pinMode(LED_B,OUTPUT);
pinMode(LED_G,OUTPUT);
pinMode(LED_R,OUTPUT);
pinMode(LED_Y,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED_B,HIGH);
digitalWrite(LED_G,LOW);
digitalWrite(LED_R,LOW);
digitalWrite(LED_Y,LOW);
delay(1000);

digitalWrite(LED_B,LOW);
digitalWrite(LED_G,HIGH);
digitalWrite(LED_R,LOW);
digitalWrite(LED_Y,LOW);
delay(1000);

digitalWrite(LED_B,LOW);
digitalWrite(LED_G,LOW);
digitalWrite(LED_R,HIGH);
digitalWrite(LED_Y,LOW);
delay(1000);

digitalWrite(LED_B,LOW);
digitalWrite(LED_G,LOW);
digitalWrite(LED_R,LOW);
digitalWrite(LED_Y,HIGH);
delay(1000);

digitalWrite(LED_B,LOW);
digitalWrite(LED_G,LOW);
digitalWrite(LED_R,HIGH);
digitalWrite(LED_Y,LOW);
delay(1000);

digitalWrite(LED_B,LOW);
digitalWrite(LED_G,HIGH);
digitalWrite(LED_R,LOW);
digitalWrite(LED_Y,LOW);
delay(1000);

}
