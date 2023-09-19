//define variables for leds/button/sensor
const int btn = 2;
const int sens = 0;
const int led1 = 13;
const int led2 = 12;
const int led3 = 11;

//define an array with our leds
int arr[] = {led1, led2, led3};

//define number of leds
int num_arr = sizeof(arr) / sizeof(arr[0]);

//define level of lightness
int light_lvl, high = 0, low = 1023;

int btn_state = LOW;
int l_btn_state = LOW;

bool circuitEnabled = true; //start with the circuit enabled

//define a function for tuning auto lightness
void auto_tune(){
  if (light_lvl < low){
    low = light_lvl;
  }

  if (light_lvl > high){
    high = light_lvl;
  }
  light_lvl = map(light_lvl, low, high, 0, num_arr);
  light_lvl = constrain(light_lvl, 0, num_arr);
}

void setup(){
  for (int i = 0; i < num_arr; i++){
    pinMode(arr[i], OUTPUT); //set all leds as output
    digitalWrite(arr[i], HIGH); //turn on all LEDs initially
  }
  pinMode(btn, INPUT_PULLUP); //set button as input with internal pull-up resistor
  Serial.begin(9600); //for debugging (sensor readings)
}

//turn on and off leds based on light level and button press
void loop(){
  light_lvl = analogRead(sens);
  auto_tune();
  
  btn_state = digitalRead(btn);
  if (btn_state != l_btn_state){
    if (btn_state == HIGH){
      circuitEnabled = !circuitEnabled;
    }
    delay(50);
  }
  l_btn_state = btn_state;
  if (circuitEnabled){
    for (int i = 0; i < num_arr; i++){
      if (i < light_lvl) {
        digitalWrite(arr[i], HIGH);
      }else{
        digitalWrite(arr[i], LOW);
      }
    }
  }else{
    for (int i = 0; i < num_arr; i++){
      digitalWrite(arr[i], LOW);
    }
  }
}