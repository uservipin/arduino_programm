#include <Adafruit_Fingerprint.h>
#include<TimerOne.h>
#include <SoftwareSerial.h>
#include<stdio.h>
int getFingerprintIDez();
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

int variable_for_out_while_loop = 1;
// ........................................................ key insert
void key_insert() {
  while (true) {
    //  Serial.println("key_insert function is called ");
    //    relay 2 and relay 4 are off because we are using simple bike key to power the finger print module so
    digitalWrite(output_relay_four, LOW);    // turn the LED off by making the voltage LOW                               ..
    digitalWrite(output_relay_two, LOW);     // turn the LED off by making the voltage LOW                                ..
    //  .....................................................................................................................

    //    here data should be come from digital read and pass with relay no. 7

    //    READ DATA OF HIGH DIGITAL PIN
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
      //OFF EVERY REVELENT DIGITAL SWITCH AND RETURN
      //variable_for_out_while_loop=1  ACCORDING TO CONDITION IF POSSIBLE
      Serial.println("  key is OFF and power supply is OFF  ");
      delay(150);
    }
  }
}
//.................................  get finger print id  with verification
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

      //      high digital pin to read for  calling  contoll finger print ;
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
//...................................................srial read  function

void  serial_read() {
  Serial.println("your password is incorrect please enter correct passwoed: ....");
  password = Serial.readString();
  Serial.println(password);
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
  //  Timer1.initialize(5000000);
  //  Timer1.attachInterrupt(getFingerprintIDez);
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

//...........................................void loop

void loop() {

  int confidence_daata_of_finger_print = controll_finger_print();
  if (confidence_data_of_finger_print >= 70) {
    //call key insert function
  }
  Serial.print("finger  id CONFIDENCE is ");
  //  Serial.println(finger_id);

  //  if (finger_id) {
  //
  //    Serial.println("welcome you are securely login ");
  //  }

  //  //  Serial.println("LOOP.....LOOP.....LOOP.....");
  //  int check_data = 0;
  //  while (check_data == 0) {
  //    if (!Serial.available()) {
  //      Serial.println("inside not serial");
  //      key_insert();
  //      delay(100);
  //    }
  //    //    Serial.println("WELCOME IN SECURITY LOOP ........ ");
  //    //    delay(1000);
  //    if ( Serial.available() ) {
  //      String  read_string = string_read();
  //      if (read_string != "VIPIN" && read_string != "STOP") {
  //        serial_read();
  //      }
  //      if (read_string == "PASS") {
  //        bypass_bluetooth() ;
  //      }
  //      if (read_string == "VIPIN") {
  //        Serial.println("your password is correct YOU HAVE LOGIN :...");
  //        int correct_code_variable = correct_code();
  //      }
  //      //      break;
  //    }
  //    check_data = check_data + 1;
  //    //    Serial.print("value of check data value is:   "); Serial.println(check_data);
  //  }
}


void Blink() {

  Serial.println("inside blink..................................");
}








