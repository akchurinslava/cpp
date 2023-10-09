#include <LiquidCrystal.h>


//define variable for temperature sensor;
//define variables for temperature and after convert to Celsius, voltage
//define an array for LEDs
//defina an array for LCD pins
int sensor = A0;
float temp, tempc, volt;
int ledPins[] = {13, 9, 8};
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//function take some int values(in our case it will be temperature) and return converted voltage
float get_vol(int pin){
return (analogRead(pin) * 0.004882814);
}

//define an amount of symbols and rows on LCD
void setup(){
  lcd.begin(16, 2);
  for (int i = 0; i < sizeof(ledPins) / sizeof(ledPins[0]); i++){
    pinMode(ledPins[i], OUTPUT);
  }
}


void loop(){
  volt = get_vol(temp);
  tempc = (volt - 0.5) * 100.0;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Now temp is: ");
  lcd.print(tempc);

  lcd.setCursor(0, 1);

  if (tempc < 25){
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[2], LOW);
    lcd.print("VERY COLD!");
  }else if (tempc >= 25 && tempc < 26){
    digitalWrite(ledPins[0], LOW);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], LOW);
    lcd.print("NORMAL!");
  }else if (tempc >= 26){
    digitalWrite(ledPins[0], LOW);
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[2], HIGH);
    lcd.print("VERY HOT!");
  }
  delay(1000);
}