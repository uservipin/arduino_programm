#include<TimerOne.h>
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
// include the library code:


#include <math.h>
#include<stdio.h>

void getFingerprintIDez();
SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

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


String LedStatus = "OFF";
int RedLed = 4;
int YellowLed = 13;

void key_insert() {
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

//.................................  get finger print id  with verification



void  getFingerprintIDez() {
  int value_for_inside_while_looop = 1;
  if ( value_for_inside_while_looop == 1) {
    while (1) {

      Serial.println("inside while loop");
      uint8_t p = finger.getImage();
      if (p != FINGERPRINT_OK) ;
      p = finger.image2Tz();
      if (p != FINGERPRINT_OK) ;
      p = finger.fingerFastSearch();
      if (p != FINGERPRINT_OK)  ;
      Serial.print("Found ID #"); Serial.println(finger.fingerID);
      Serial.print(" with confidence of "); Serial.println(finger.confidence);


      if (finger.fingerID == 0) {
        Serial.println("3");
        //Serial.println("unlock");
        int count_3 = 1;
        if (count_3 == 1 ) {
          Serial.println("unlock");
        }
      }
      if (finger.confidence >= 70) {
        return   ;
      }

    }
  }
}



//..................................................... setup

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("wELCOME IN SECCURITY SYSTEM SOLUTIONS... :");
  //  Serial.println(data);
  pinMode(output_relay_four, OUTPUT);
  pinMode(pass_circuit, OUTPUT);
  pinMode(output_relay_two, OUTPUT);
  pinMode(input_read, INPUT);
  pinMode(output_data, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(YellowLed, OUTPUT);
  Timer1.initialize(5000000);
  Timer1.attachInterrupt(getFingerprintIDez);

  // put your setup code here, to run once:


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

void loop() {
  getFingerprintIDez();
  Serial.print("finger  id CONFIDENCE is "); 

 
  //  //  Serial.println("LOOP.....LOOP.....LOOP.....");
  int check_data = 0;
  while (check_data == 0) {
    if (!Serial.available()) {
      Serial.println("inside not serial");
      key_insert();
      delay(100);
    }
  }
}





void Blink() {
  if (LedStatus == "ON") {
    digitalWrite(YellowLed, LOW);
    LedStatus = "OFF";
    return;
  }

  if (LedStatus == "OFF") {
    digitalWrite(YellowLed, HIGH);
    LedStatus = "ON";
    return;
  }
}





