#include <Adafruit_Fingerprint.h>
#include<TimerOne.h>
#include <SoftwareSerial.h>
#include<stdio.h>
int getFingerprintIDez();
void key_insert();
SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
int getFingerprintIDez();
// RELAY NO. 3 IS CONNECTED TO POWER SUPPLY
int input_read = 2;            // is input to finget print module
int pass_circuit = 11;         // connected to relay no. 5
int output_data = 13;          // relay no. 1 and 6 connected
int output_relay_two = 10;     // relay no. 2                                                                                                                                                                                                      relay no. 2
int output_relay_four = 12;    // relay no. 4
int data = 0;
String password;
//String vipin = "VIPIN";
int count = 0;
int count_again = 0;


int variable_for_out_while_loop = 1;
void setup()
{
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...

  Serial.begin(9600);
  Serial.println("Adafruit finger detect test");

  // set the data rate for the sensor serial port
  finger.begin(57600);
  //pinMode(buzzer, OUTPUT); // Set buzzer - pin 10 as an output
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1)
      Serial.println("Waiting for valid finger...");
  }
}

void loop()                     // run over and over again
{
  uint8_t id ;
  key_insert();
  //  getFingerprintIDez();

  delay(500);

  Serial.println("hello");
}

int getFingerprintIDez() {
  while (true) {
    while (! Serial.available());
    uint8_t p = finger.getImage();
    if (p != FINGERPRINT_OK)  return -1;
    p = finger.image2Tz();
    if (p != FINGERPRINT_OK)  return -1;
    p = finger.fingerFastSearch();
    if (p != FINGERPRINT_OK)  return -1;
    Serial.print("Found ID #"); Serial.print(finger.fingerID);
    Serial.print(" with confidence of "); Serial.println(finger.confidence);
    if (finger.confidence >= 70) {
      return  finger.confidence;
    }
  }
}



int controll_finger_print() {
   if (variable_for_out_while_loop == 1) {
  while (true) {
    Serial.println("inside while loop key insert");
   
      int confidence_data =  getFingerprintIDez();
      Serial.println(confidence_data);
      if (confidence_data >= 70) {
        Serial.println("inside iffff");
        variable_for_out_while_loop = 2;
        return confidence_data;
      }
    }
  }
}




void key_insert() {
  int confidence_data = controll_finger_print();

  //  Serial.println("key_insert function is called ");
  digitalWrite(output_relay_four, LOW);    // turn the LED off by making the voltage LOW                               ..
  digitalWrite(output_relay_two, LOW);    // turn the LED off by making the voltage LOW                                ..
  //  .....................................................................................................................
  data = digitalRead(input_read);
  Serial.print("print digital read inside key_insert data is : ");   Serial.println(data);
  delay(150);
  if (data == 1) {
    digitalWrite(output_data, HIGH);
    Serial.println("key is ON and power supply is ON");
    delay(150);
  }
  if (data == 0) {
    digitalWrite(output_data, LOW );
    Serial.println("  key is OFF and power supply is OFF  ");
    delay(150);
  }
}

