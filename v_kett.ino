const int R_1=7;
const int R2=11;
const int B_1=12;
const int B2=20;
const int Y1=6;
const int Y2=13;
const int G1=5;
const int G2=10;
const int ORZ=9;
const int SPin=0;
int LP[] = {20, 13, 12, 11, 10, 9, 7, 6, 5};

//numbers of LED
int num = sizeof(LP) / sizeof(LP[0]);

//brigthness of LEDs
int bright = 0;
int fade = 10; 
int NewValue;
 
//LEDs go out
//in if section we change fade direction
void fade_out(int colorPin){
    analogWrite(colorPin, bright);
    bright += fade;
    if (bright <= 0 || bright >= 255) {
        fade = -fade;
    }
 
    delay(70); 
}
 
//function take random LED from our int array LP
void rnd_choose(){
    int randomLed = random(0, num); 
    Serial.println(randomLed);
    digitalWrite(LP[randomLed], !digitalRead(LP[randomLed]));
    delay(300);
}
 

void r1_b2_g1(){
    digitalWrite(R_1,HIGH);
    digitalWrite(B2,HIGH);
    digitalWrite(G1,HIGH);
    delay(80);
    digitalWrite(R_1,LOW);
    digitalWrite(B2,LOW);
    digitalWrite(G1,LOW);
}  


void r2_y1_g2(){
    digitalWrite(R2,HIGH);
    digitalWrite(Y1,HIGH);
    digitalWrite(G2,HIGH);
    delay(80);
    digitalWrite(R2,LOW);
    digitalWrite(Y1,LOW);
    digitalWrite(G2,LOW);
}  
  

void b1_y2_orz(){
    digitalWrite(B_1,HIGH);
    digitalWrite(Y2,HIGH);
    digitalWrite(ORZ,HIGH);
    delay(80);
    digitalWrite(B_1,LOW);
    digitalWrite(Y2,LOW);
    digitalWrite(ORZ,LOW);
   
} 
 
//function for blinking, duration of blinking generate randomly
void blink(){
    digitalWrite(LP[1], HIGH);
    delay(random(20, 90));
    digitalWrite(LP[1], LOW);
    delay(random(15, 70));
    digitalWrite(LP[4], HIGH);
    delay(random(20, 90));
    digitalWrite(LP[4], LOW);
    delay(random(15, 70));
    digitalWrite(LP[7], HIGH);
    delay(random(20, 90));
    digitalWrite(LP[7], LOW);
    delay(random(15, 70));
}


void setup(){
    pinMode (R_1, OUTPUT);
    pinMode (B2, OUTPUT);
    pinMode (G1, OUTPUT);
    pinMode (R2, OUTPUT);
    pinMode (Y1, OUTPUT);
    pinMode (G2, OUTPUT);
    pinMode (B_1, OUTPUT);
    pinMode (Y2, OUTPUT);
    pinMode (ORZ, OUTPUT);
  
    for (int i = 0; i < num; i++) {
        pinMode(LP[i], OUTPUT);
    }
}
  

void loop(){
   NewValue = analogRead(SPin);
   NewValue = map(NewValue,0,1023,1,6);
    if (NewValue==2){
    rnd_choose();
    }
    if (NewValue==3){
    r1_b2_g1();
    delay(300); 
    b1_y2_orz();
    delay(300); 
    r2_y1_g2();
    delay(300); 
    } 
    if (NewValue==4){
        for (int i = 0; i < sizeof(LP) / sizeof(LP[0]); i++) {
            digitalWrite(LP[i], HIGH);
        };
        delay(300); 
        for (int i = 0; i < sizeof(LP) / sizeof(LP[0]); i++) {
            digitalWrite(LP[i], LOW);
        };
        delay(300); 
    }
    if(NewValue==5){
        fade_out(B_1);
        fade_out(R_1);
        fade_out(Y1);
        fade_out(ORZ);
        fade_out(G1);     
        delay(150);
        }
    if(NewValue==6){
        blink();     
    }
    
    else {
        digitalWrite(R_1,LOW);
        digitalWrite(B2,LOW);
        digitalWrite(G1,LOW);
        digitalWrite(R2,LOW);
        digitalWrite(Y1,LOW);
        digitalWrite(G2,LOW);
        digitalWrite(B_1,LOW);
        digitalWrite(Y2,LOW);
        digitalWrite(ORZ,LOW);
    }
}