



//  secod frame MORTER CONFUGRATION
const int dirPin = 52 ;
const int stepPin = 50;
const int enPin = 48;

// main frame (arduino frame )MORTER CONFUGRATION
const int dirPin_02 = 51;
const int stepPin_02 = 49;
const int enPin_02 = 53;

//................................brush
const int dirPin_brush = 47;
const int stepPin_brush = 45;
const int enPin_brush = 43;


unsigned long mill = 50;
int microsteps = 100;
int microsteps_2 = 100;
float steps = 40000;



void setup() {


  // Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);

  pinMode(stepPin_02, OUTPUT);
  pinMode(dirPin_02, OUTPUT);
  pinMode(enPin_02, OUTPUT);
  digitalWrite(enPin_02, LOW);

  pinMode(stepPin_brush, OUTPUT);
  pinMode(dirPin_brush, OUTPUT);
  pinMode(enPin_brush, OUTPUT);
  digitalWrite(enPin_brush, LOW);




  Serial.begin(9600);

}
void loop() {
  //brush_forward();
  //brush_back();
  forward_motion_of_morter();
  delay(1000);

//back();
 // delay(1000);

  //delay(50);



}

void brush_forward() {
  digitalWrite(dirPin_brush, HIGH);                         // FOR SECOND MORTER
  // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < steps; x++) {
    //    ..............................................................FOR FIRST STEPPER MORTER
    digitalWrite(stepPin_brush, HIGH);
    //  digitalWrite(stepPin_02, HIGH);
    delayMicroseconds(microsteps);
    digitalWrite(stepPin_brush, LOW);
    //     digitalWrite(stepPin_02, LOW);
    delayMicroseconds(microsteps);
    //delay(millisbetweenSteps);
  }
}


void brush_back() {
  digitalWrite(dirPin_brush, LOW);                        // FOR SECOND MORTER
  // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < steps; x++) {
    //    ..............................................................FOR FIRST STEPPER MORTER
    digitalWrite(stepPin_brush, HIGH);
    //  digitalWrite(stepPin_02, HIGH);
    delayMicroseconds(microsteps);
    digitalWrite(stepPin_brush, LOW);
    //     digitalWrite(stepPin_02, LOW);
    delayMicroseconds(microsteps_2);
    //delay(millisbetweenSteps);
  }
}





void forward_motion_of_morter() {
  //brush_forward();
  digitalWrite(dirPin, HIGH);                            // FOR FIRST MORTER
  digitalWrite(dirPin_02, HIGH);                         // FOR SECOND MORTER
  //  digitalWrite(dirPin_brush, HIGH);                     // For brush
  // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < steps; x++) {
    //    ..............................................................FOR FIRST STEPPER MORTER
    //    digitalWrite(stepPin, HIGH);
    //    delayMicroseconds(microsteps);
    //    digitalWrite(stepPin, LOW);
    //    delayMicroseconds(microsteps);

    //  ................................................................FOR SECOND STEPPER MORTER
    //    digitalWrite(stepPin_02, HIGH);
    //    delayMicroseconds(microsteps);
    //    digitalWrite(stepPin_02, LOW);
    //    delayMicroseconds(microsteps);

    //    ..............................................................FOR FIRST STEPPER MORTER
    //    digitalWrite(stepPin_brush, HIGH);
    //    delayMicroseconds(microsteps_2);
    //    digitalWrite(stepPin_brush, LOW);
    //    delayMicroseconds(microsteps_2);





    digitalWrite(stepPin, HIGH);
    digitalWrite(stepPin_02, HIGH);
    //digitalWrite(stepPin_brush, HIGH);
    delayMicroseconds(microsteps);


    digitalWrite(stepPin, LOW);
    digitalWrite(stepPin_02, LOW);
    //  digitalWrite(stepPin_brush, LOW);
    delayMicroseconds(microsteps);

    //  ................................................................FOR SECOND STEPPER MORTER




  }








}


void back() {
  //Changes the rotations direction
  digitalWrite(dirPin, LOW);                            // FOR FIRST MORTER
  digitalWrite(dirPin_02, LOW);                         // FOR SECOND MORTER

  // FOR SECOND MORTER
  //  digitalWrite(dirPin_brush,LOW);
  // Makes 400 pulses for making two full cycle rotation
  for (int x = 0; x < steps; x++) {

//    //    ..............................................................FOR FIRST STEPPER MORTER
//    digitalWrite(stepPin, HIGH);
//    delayMicroseconds(microsteps);
//    digitalWrite(stepPin, LOW);
//    delayMicroseconds(microsteps);
//
//    //  ................................................................FOR SECOND STEPPER MORTER
//
//
//    digitalWrite(stepPin_02, HIGH);
//    delayMicroseconds(microsteps);
//    digitalWrite(stepPin_02, LOW);
//    delayMicroseconds(microsteps);
//    //    Serial.println(x);


    
    digitalWrite(stepPin, HIGH);
    digitalWrite(stepPin_02, HIGH);
    //digitalWrite(stepPin_brush, HIGH);
    delayMicroseconds(microsteps);


    digitalWrite(stepPin, LOW);
    digitalWrite(stepPin_02, LOW);
    //  digitalWrite(stepPin_brush, LOW);
    delayMicroseconds(microsteps);
  }
  // ..........................................................................delay is used for stop morter for tesring phase
 

}



void stop_Robot() {
  digitalWrite(enPin, HIGH);
  digitalWrite(enPin_02, HIGH);


  //
  //  //Changes the rotations direction
  //  digitalWrite(dirPin, LOW);                            // FOR FIRST MORTER
  //  digitalWrite(dirPin_02, LOW);                         // FOR SECOND MORTER
  //
  //  // Makes 400 pulses for making two full cycle rotation
  //  for (int x = 0; x < steps; x++) {
  //
  //    //    ..............................................................FOR FIRST STEPPER MORTER
  //    digitalWrite(stepPin, HIGH);
  //    delayMicroseconds(microsteps);
  //    digitalWrite(stepPin, LOW);
  //    delayMicroseconds(microsteps);
  //
  //    //  ................................................................FOR SECOND STEPPER MORTER
  //
  //    digitalWrite(stepPin_02, HIGH);
  //    delayMicroseconds(microsteps);
  //    digitalWrite(stepPin_02, LOW);
  //    delayMicroseconds(microsteps);
  //    //    Serial.println(x);
  //  }
  // ..........................................................................delay is used for stop morter for tesring phase
  delay(5000); // One second delay
  digitalWrite(enPin, LOW);
  digitalWrite(enPin_02, LOW);
  //  digitalWrite(stepPin, LOW);
  //  digitalWrite(enPin_02, LOW);

  //digitalWrite(enPin_02,LOW);

}
