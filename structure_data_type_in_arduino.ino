//use structure in c to hold  and return more then single data  and different data type  
//FUNCTION IS CHAQUED IN PROTEUS
//CODE WRITTEN IN ARDUINO IDE

#include<stdio.h>
struct test {
  int data ;
  int input ;
};

struct test function(int a ,int b) {
  struct test call_struct;
  call_struct.data = a + b;
  call_struct.input = a - b;
  return call_struct;
}

int  counter() {
  int i;
  for (i = 0; i < 10; i++) {
    Serial.println("counter function works");
    //  Serial.println(i);
  }
  return i;
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
//  int j = counter(); 
//  Serial.println(j);

struct test test_no=function(10,5);
Serial.println(test_no.data);
Serial.println(test_no.input);

  // put your main code here, to run repeatedly:

}
