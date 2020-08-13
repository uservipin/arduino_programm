

void setup() {
 Serial.begin(9600);
 Serial.println("Date & Time, Humidity %, Temperature *C, Temperature *F");
 
}

void loop() {
 // Wait a few seconds between measurements.
 delay(1000);
// Reading temperature or humidity takes about 250 milliseconds!
 // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)

// Check if any reads failed and exit early (to try again).

 Serial.print(",");
 Serial.print("1");
 Serial.print(",");
 Serial.print("2");
 Serial.print(",");
 Serial.println("3");
}
