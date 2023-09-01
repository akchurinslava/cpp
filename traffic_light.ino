//version main
//define ports for colours
const int RED = 13;
const int YELLOW = 12;
const int GREEN = 7;
const int RED_P = 11;
const int GREEN_P = 10;

//for count cycles
int x = 0;

//sub function for yellow blinking
void yellow_blink(){
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN_P, HIGH);
  delay(300);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN_P, LOW);
  delay(300);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN_P, HIGH);
  delay(300);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN_P, LOW);
  delay(300);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN_P, HIGH);
  delay(300);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN_P, LOW);
  delay(300);
}

//sub function for green and red blinking
void r_g_blink(){
  digitalWrite(RED_P, LOW);
  digitalWrite(GREEN, LOW);
  delay(300);
  digitalWrite(RED_P, HIGH);
  digitalWrite(GREEN, HIGH);
  delay(300);
  digitalWrite(RED_P, LOW);
  digitalWrite(GREEN, LOW);
  delay(300);
  digitalWrite(RED_P, HIGH);
  digitalWrite(GREEN, HIGH);
  delay(300);
  digitalWrite(RED_P, LOW);
  digitalWrite(GREEN, LOW);
  delay(300);
  digitalWrite(RED_P, HIGH);
  digitalWrite(GREEN, HIGH);
  delay(300);
}

//function for switching colours of traffic light for cars and people in day time
void colours_day(){
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN_P, HIGH);
  delay(2000);
  yellow_blink();
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN_P, LOW);
  digitalWrite(RED_P, HIGH);
  digitalWrite(GREEN, HIGH);
  delay(2000);
  r_g_blink();
  digitalWrite(GREEN, LOW);
  digitalWrite(RED_P, LOW);
}

//function for switching colours of traffic light for cars in night time
void colours_night(){
  delay(500);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN_P, HIGH);
  delay(500);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN_P, LOW);
  delay(500);
}


void setup(){
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED_P, OUTPUT);
  pinMode(GREEN_P, OUTPUT);
}


void loop(){
  while (x < 6){
    x = x + 1;
    if (x <= 3) colours_day();
    if (x > 3) colours_night();
  } 
}



// //version short
// //define ports for colours
// const int RED = 13;
// const int YELLOW = 12;
// const int GREEN = 7;

// //for count cycles
// int x = 0;

// //function for switching colours of traffic light for cars in day time
// void colours_day_cars(){
//   digitalWrite(RED, HIGH);
//   delay(500); 
//   digitalWrite(RED, LOW);
//   digitalWrite(YELLOW, HIGH);
//   digitalWrite(GREEN, LOW);
//   delay(500);  
//   digitalWrite(RED, LOW);
//   digitalWrite(YELLOW, LOW);
//   digitalWrite(GREEN, HIGH);
//   delay(500);
//   digitalWrite(GREEN, LOW);
// }

// //function for switching colours of traffic light for cars in night time
// void colours_night_cars(){
//   digitalWrite(YELLOW, HIGH);
//   delay(500);
//   digitalWrite(YELLOW, LOW);
//   delay(500);
// }

// //function for switching colours of traffic light for people in day time
// void colours_day_people(){
//   digitalWrite(RED, HIGH);
//   delay(500);
//   digitalWrite(RED, LOW);
//   delay(500);
//   digitalWrite(GREEN, HIGH);
//   delay(500);
//   digitalWrite(GREEN, LOW);
//   delay(500);
// }

// //function for switching colours of traffic light for people in night time
// void colours_night_people(){
//   digitalWrite(GREEN, HIGH);
//   delay(500);
//   digitalWrite(GREEN, LOW);
//   delay(500);
// }


// void setup(){
//   pinMode(RED, OUTPUT);
//   pinMode(YELLOW, OUTPUT);
//   pinMode(GREEN, OUTPUT);
// }


// void loop(){
//   while (x < 13){
//     x = x + 1;
//     if (x <= 3) colours_day_cars();
//     if (x <= 6 & x > 3) colours_night_cars();
//     if (x < 10 & x > 6) colours_day_people();
//     if (x > 10) colours_night_people();  
//   } 
// }





// long version
// //define ports for colours
// const int RED = 13;
// const int YELLOW = 12;
// const int GREEN = 7;

// //for count cycles
// int x = 0;

// //function for switching colours of traffic light for cars in day time
// void colours_day_cars(){
//   digitalWrite(RED, HIGH);
//   digitalWrite(YELLOW, LOW);
//   digitalWrite(GREEN, LOW);
//   delay(500); 
//   digitalWrite(RED, LOW);
//   digitalWrite(YELLOW, HIGH);
//   digitalWrite(GREEN, LOW);
//   delay(500);  
//   digitalWrite(RED, LOW);
//   digitalWrite(YELLOW, LOW);
//   digitalWrite(GREEN, HIGH);
//   delay(500);
//   digitalWrite(GREEN, LOW);
// }

// //function for switching colours of traffic light for cars in night time
// void colours_night_cars(){
//   digitalWrite(YELLOW, HIGH);
//   delay(500);
//   digitalWrite(YELLOW, LOW);
//   delay(500);
// }

// //function for switching colours of traffic light for people in day time
// void colours_day_people(){
//   digitalWrite(RED, HIGH);
//   digitalWrite(GREEN, LOW);
//   delay(500);
//   digitalWrite(RED, LOW);
//   digitalWrite(GREEN, LOW);
//   delay(500);
//   digitalWrite(RED, LOW);
//   digitalWrite(GREEN, HIGH);
//   delay(500);
//   digitalWrite(GREEN, LOW);
//   delay(500);
// }

// //function for switching colours of traffic light for people in night time
// void colours_night_people(){
//   digitalWrite(GREEN, HIGH);
//   delay(500);
//   digitalWrite(GREEN, LOW);
//   delay(500);
// }



// void setup(){
//   pinMode(RED, OUTPUT);
//   pinMode(YELLOW, OUTPUT);
//   pinMode(GREEN, OUTPUT);
// }

// void loop(){
//   while (x < 13){
//     x = x + 1;
//     if (x <= 3) colours_day_cars();
//     if (x <= 6 & x > 3) colours_night_cars();
//     if (x < 10 & x > 6) colours_day_people();
//     if (x > 10) colours_night_people();  
//   } 
// }