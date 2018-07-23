  void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13,HIGH);
delay(3000);

digitalWrite(13,LOW);
delay(3000);

digitalWrite(12,HIGH);
delay(2000);
digitalWrite(12,LOW);
delay(2000);

digitalWrite(11,HIGH);
delay(1000);

digitalWrite(11,LOW);
delay(1000);


digitalWrite(10,HIGH);
delay(5000);

digitalWrite(10,LOW);
delay(5000);

digitalWrite(9,HIGH);
delay(400);

digitalWrite(9,LOW);
delay(400);







}
