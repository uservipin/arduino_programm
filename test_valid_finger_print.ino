#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
// include the library code:
int getFingerprintIDez();

SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

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

void open_lock() {
  digitalWrite(13, 225);

}
void close_lock() {
 digitalWrite(13, 225); 
}

void loop()                     // run over and over again
{
getFingerprintIDez();
  delay(50);           
}
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;
  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  if (finger.fingerID == 0) {
   
    Serial.println("3");
    //Serial.println("unlock");
   int count_3 =1;
    if (count_3 == 1 ) {
      Serial.println("unlock");
    }
  }
}

