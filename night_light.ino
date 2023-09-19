// //define varriables for leds/button/sensor
// const int btn = 2;
// const int sens = 0;
// const int led1 = 13;
// const int led2 = 12;
// const int led3 = 11;
// const int led4 = 10;

// //define an array with our leds
// int arr[] = {led1, led2, led3, led4};

// //define number of leds
// int num_arr = sizeof(arr) / sizeof(arr[0]);

// //define level of lightness
// int light_lvl, high = 0, low = 1023;

// int buttonState = LOW;
// int lastButtonState = LOW;

// //define a function for tuning auto lightness
// void auto_tune(){
//   if (light_lvl < low){
//     low = light_lvl;
//   }

//   if (light_lvl > high){
//     high = light_lvl;
//   }
//   light_lvl = map(light_lvl, low, high, 0, num_arr);
//   light_lvl = constrain(light_lvl, 0, num_arr);
// }

// void setup(){
//   for (int i = 0; i < num_arr; i++){
//     pinMode(arr[i], OUTPUT); //set all leds as output
//   }
//   Serial.begin(9600); //for debugging (sensor readings)
// }

// //turn on and off leds based on light level
// void loop(){
//   light_lvl = analogRead(sens);
//   auto_tune();
//   for (int i = 0; i < num_arr; i++){
//     if (i < light_lvl) {
//       digitalWrite(arr[i], HIGH);
//     } else {
//       digitalWrite(arr[i], LOW);
//     }
//   }
// }


// Define variables for leds/button/sensor
const int btn = 2;
const int sens = 0;
const int led1 = 13;
const int led2 = 12;
const int led3 = 11;
const int led4 = 10;

// Define an array with our leds
int arr[] = {led1, led2, led3, led4};

// Define number of leds
int num_arr = sizeof(arr) / sizeof(arr[0]);

// Define level of lightness
int light_lvl, high = 0, low = 1023;

int buttonState = LOW;
int lastButtonState = LOW;

bool circuitEnabled = true; // Start with the circuit enabled

// Define a function for tuning auto lightness
void auto_tune() {
  if (light_lvl < low) {
    low = light_lvl;
  }

  if (light_lvl > high) {
    high = light_lvl;
  }
  light_lvl = map(light_lvl, low, high, 0, num_arr);
  light_lvl = constrain(light_lvl, 0, num_arr);
}

void setup() {
  for (int i = 0; i < num_arr; i++) {
    pinMode(arr[i], OUTPUT); // Set all leds as output
    digitalWrite(arr[i], HIGH); // Turn on all LEDs initially
  }
  pinMode(btn, INPUT_PULLUP); // Set button as input with internal pull-up resistor
  Serial.begin(9600); // For debugging (sensor readings)
}

// Turn on and off leds based on light level and button press
void loop() {
  light_lvl = analogRead(sens);
  auto_tune();
  
  buttonState = digitalRead(btn);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      // Button is pressed, toggle circuit state
      circuitEnabled = !circuitEnabled;
    }
    delay(50); // Debounce delay
  }
  lastButtonState = buttonState;
  
  if (circuitEnabled) {
    for (int i = 0; i < num_arr; i++) {
      if (i < light_lvl) {
        digitalWrite(arr[i], HIGH);
      } else {
        digitalWrite(arr[i], LOW);
      }
    }
  } else {
    // Turn off all LEDs when the circuit is disabled
    for (int i = 0; i < num_arr; i++) {
      digitalWrite(arr[i], LOW);
    }
  }
}
