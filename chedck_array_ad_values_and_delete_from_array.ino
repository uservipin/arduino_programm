
int array[5];
void setup() {
  // put your setup code here, to run once:
  //how to use array
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(7, OUTPUT);
}

void loop() {


  digitalWrite(7, HIGH);
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    Serial.println("values in array");
    //here analog data is read and add to array
    int data = analogRead(A0);
    Serial.println(data);
    array[i] = data;
    sum = sum + array[i];
    
    Serial.println(array[i]);
  }

  //  Serial.println("print array ");
  //  for (int i = 0; i < 5; i++)
  //  {
  //    //    sum = sum + array[i];
  //    Serial.println(array[i]);
  //  }


  Serial.print("sum of number      ");    Serial.println(sum);
  int avg = sum / 5;
  Serial.print("average is ");               Serial.println(avg);
  for (int i = 0; i < 5; i++)
  {
    array[i] = 0;
  }

  Serial.println("new array is ");
  for (int i = 0; i < 5; i++)
  {

    Serial.println(array[i]);
  }

}
