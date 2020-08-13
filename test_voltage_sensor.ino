
int read_voltage_pin =A0;


void setup() {
  // put your setup code here, to run once:
pinMode(read_voltage_pin,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int read_voltage=analogRead(read_voltage_pin);
int voltage= (read_voltage*5.0)/1024;
Serial.println(voltage);
}
