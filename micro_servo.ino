//attach library for Micro Servo
#include  <Servo.h>

//define the variables for temperature sensor, LED, socket for servo, servo position
//define the variables for voltage and celsium degrees
//define a servo control object
const int temp = 0;
const int led = 13;
const int serv_pin = 9;
int serv_pst;
float volt, celsius;
Servo serv;

//function take some int values(in our case it will be temperature) and return converted voltage
float get_vol(int pin){
return (analogRead(pin) * 0.004882814);
}

//attach serv to serv_pin value
void setup(){
  serv.attach(serv_pin);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

//if degrees are lower or equal then 22 servo position on 0 and lights off
//if degrees are higher or equal then 35 servo position 180 and lights on
//output in serial monitor
void loop(){
  volt = get_vol(temp);
  celsius = (volt - 0.5) * 100.0;
  Serial.print(" Degrees in celsium: ");
  Serial.print(celsius);
  if (celsius <= 28){
    serv.write(0);
    digitalWrite(led, LOW);
  
  }else if (celsius >= 29){
    serv.write(180);  
    digitalWrite(led, HIGH);
  } 
}