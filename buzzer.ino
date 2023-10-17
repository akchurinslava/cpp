//define PINs for button and buzzer
const int buzzerPin = 9;
const int buttonPin = 7;

//define lenghth of sound and arraies of notes of melodies
const int songLength = 22;
char notes1[] = "cdefgabC ";
char notes2[] = "gfedc ";
char notes3[] = "abCdefg ";

//define arraies of lenght notes of melodies
int beats1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int beats2[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int beats3[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};


//define speed, current song and button pressure
int tempo = 150;
int currentSong = 0;
bool buttonPressed = false;


//define PINs for LEDs
const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;

//for button pressure and input we use input_pullup
void setup(){
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}


void loop(){
  if (digitalRead(buttonPin) == LOW && !buttonPressed){
    buttonPressed = true;
    currentSong = (currentSong + 1) % 3;
    delay(500);
  }else if (digitalRead(buttonPin) == HIGH){
    buttonPressed = false;
  }

  playMelody(currentSong);
}

//define function for songs playing and LEDs activate
void playMelody(int song){
  int duration;
  const char *melody;
  const int *beats;

  if (song == 0){
    melody = notes1;
    beats = beats1;
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }else if (song == 1){
    melody = notes2;
    beats = beats2;
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
  }else if (song == 2){
    melody = notes3;
    beats = beats3;
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
  }

  for (int i = 0; i < songLength; i++){
    duration = beats[i] * tempo;

    if (melody[i] == ' '){
      noTone(buzzerPin);
      delay(duration);
    }else{
      tone(buzzerPin, frequency(melody[i]), duration);
      delay(duration);
    }
    delay(tempo / 10);
  }
}

//define function for GHz
int frequency(char note){
  const char notes[] = "cdefgabC";
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
  for (int i = 0; i < 8; i++){
    if (note == notes[i]){
      return frequencies[i];
    }
  }
  return 0;
}
