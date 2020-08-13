  //................................brush
const int dirPin_brush = 47;
const int stepPin_brush = 45;
const int enPin_brush = 43;


//  secod frame MORTER CONFUGRATION
const int dirPin = 52 ;
const int stepPin = 50;
const int enPin = 48;

//main frame
const int dirPin_02 = 51;
const int stepPin_02 = 49;
const int enPin_02 = 53;

unsigned long mill = 40; 
int microsteps =27;
int microsteps_2 = 27;
long steps =200;

// 22400 microstep for single revolution of wheel 100 mm dia at 1/8i
// 1057 for 17 degree of rotation of 100 mm wheel at 1/8 microstep 
//long steps =1600;   for one revolution at 1/8 step for mena 17 eithout gear

int var_0 = 200;
int var =10000;
void back();

int microsteps_brush=100;
void setup() {
  pinMode(stepPin_brush, OUTPUT);
  pinMode(dirPin_brush, OUTPUT);
  pinMode(enPin_brush, OUTPUT);
  digitalWrite(enPin_brush, LOW);
  // Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);
  
  pinMode(stepPin_02, OUTPUT);
  pinMode(dirPin_02, OUTPUT);
  pinMode(enPin_02, OUTPUT);
  digitalWrite(enPin_02, LOW);
  Serial.begin(9600);
}


void loop() {

  //test_optimum_rpm();
     //  
//back();
 //delay(2000);    
 forward_motion_of_morter();
 //delay(2000);  
//brush_forward();  
}

void forward_motion_of_morter() {

  digitalWrite(dirPin, HIGH);                            // FOR FIRST MORTER
  digitalWrite(dirPin_02, HIGH);                         // FOR SECOND MORTER
  // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (long x = 0; x < steps; x++) {
    //    ..............................................................FOR FIRST STEPPER MORTER
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(microsteps);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(microsteps_2);


    //  ................................................................FOR SECOND STEPPER MORTER
    digitalWrite(stepPin_02, HIGH);
    delayMicroseconds(microsteps);
    digitalWrite(stepPin_02, LOW);
    delayMicroseconds(microsteps_2);       
  }
}


void back() {
  //Changes the rotations direction
  digitalWrite(dirPin, LOW);                            // FOR FIRST MORTER
  digitalWrite(dirPin_02, LOW);                         // FOR SECOND MORTER
    

  // Makes 400 pulses for making two full cycle rotation
  for (long x = 0; x < steps; x++) {
    //    ..............................................................FOR FIRST STEPPER MORTER
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(microsteps);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(microsteps_2);
//    //  ................................................................FOR SECOND STEPPER MORTER

    digitalWrite(stepPin_02, HIGH);
    delayMicroseconds(microsteps);
    digitalWrite(stepPin_02, LOW);
    delayMicroseconds(microsteps_2);

  }
    
  // ..........................................................................delay is used for stop morter for tesring phase
 
}


void stop_Robot() {
  digitalWrite(enPin, HIGH);
  digitalWrite(enPin_02, HIGH);
  // ..........................................................................delay is used for stop morter for tesring phase
  digitalWrite(enPin, LOW);
  digitalWrite(enPin_02, LOW);
delay(2000);
}



void brush_forward() {
  digitalWrite(dirPin_brush, HIGH);                         // FOR SECOND MORTER
  for (int x = 0; x < steps; x++) {
    //    ..............................................................FOR FIRST STEPPER MORTER
    digitalWrite(stepPin_brush, HIGH);
    delayMicroseconds(microsteps_brush);
    digitalWrite(stepPin_brush, LOW);
    delayMicroseconds(microsteps_brush);
  }
}


void test_optimum_rpm(){
  for (int x = 0; x < var_0; x++) {
    for(int y=0;y<var;y++){
    digitalWrite(stepPin_02, HIGH);
    delayMicroseconds(microsteps);
    digitalWrite(stepPin_02, LOW);
    delayMicroseconds(microsteps);
  }
 // delay(1000);
  Serial.println("microsteps");
  Serial.println(microsteps);
  
  microsteps=microsteps-1;
   }
}
