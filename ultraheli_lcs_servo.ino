#include <LiquidCrystal.h> 
#include <Servo.h> 
  
#define echo 3
#define trig 4
  
float  duration, distance; //the time it takes for a pulse to return, the one-way distance traveled by the pulse.
  
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
Servo lidServo;


void setup(){
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    Serial.begin(9600);
    lcd.begin(16, 2);
    lidServo.attach(5);
}

//calculate the one-way distance traveled when the distance to the object is less than 10 cm, the servo turns and opens the trash can lid.
void loop(){
    time_measurement();
    distance = duration * (0.0343) / 2;
    display_distance();
    if (distance < 10){
        open_lid();
    }else{
        close_lid();
    }
}
    
//function to measure the time it takes for a pulse to return.
void time_measurement(){
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
  
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
  
    duration = pulseIn(echo, HIGH);
}

//function for displaying distance on an LCD/Serial Monitor.
void display_distance(){
    lcd.clear();
    lcd.setCursor(0, 0);
    Serial.print("Distance in Cm: ");
    Serial.print(distance);
    Serial.println();
    lcd.print("Distance in Cm: ");
    lcd.setCursor(5, 1);
    lcd.print(distance);
    delay(1000);
}

//rotate the servo to open the lid, adjust the angle as needed to fully open the lid
void open_lid(){
    lidServo.write(90);
}

//rotate the servo to close the lid, adjust the angle as needed to fully close the lid
void close_lid(){
    lidServo.write(0);
}