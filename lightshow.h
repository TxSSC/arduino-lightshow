char inData[20]; // Allocate some space for the string
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character

String currentProgram = "";

int const peak = 300;
int const boomPeak = 500;
int const light01 = 11;
int const light02 = 10;
int const light03 = 9;
int const light04 = 6;
int const light05 = 5;
int const light06 = 3;
int const jack01 = 0;

int bassHit_brightness = 0;
int ibassHit_brightness = 255;
int breathe_brightness = 255;
int breathe_direction = 0;

int ledArray[6] = {light01, light02, light03, light04, light05, light06};

void setup(){

  Serial.begin(9600);
  Serial.write("Power On");
  pinMode(light01, OUTPUT);
  pinMode(light02, OUTPUT);
  pinMode(light03, OUTPUT);
  pinMode(light04, OUTPUT);
  pinMode(light05, OUTPUT);
  pinMode(light06, OUTPUT);
}

// Buffering Serial Port Reader
char Comp(char* This){

  while(Serial.available() > 0) {
    if(index < 19) {
      inChar = Serial.read();
      inData[index] = inChar;
      index++;
      inData[index] = '\0';
    }
  }

  if(strcmp(inData,This)  == 0) {
    for(int i=0;i<19;i++) {
      inData[i]=0;
    }
    index=0;
    return(0);
  }
  else{
    return(1);
  }
}

// Main
void loop() {

  // Set Programs
  if(Comp("a") == 0 || currentProgram == "a"){
    currentProgram = "a";
    bassHit();
  }
  
  if(Comp("b") == 0 || currentProgram == "b"){
    currentProgram = "b";
    inverseBassHit();
  }
  
  if(Comp("c") == 0 || currentProgram == "c"){
    currentProgram = "c";
    bassHitBuildUp();
  }
  
  if(Comp("d") == 0 || currentProgram == "d"){
    currentProgram = "d";
    breather();
  }
  
  if(Comp("e") == 0 || currentProgram == "e"){
    currentProgram = "e";
    candle();
  }

  // Individuals

  if(Comp("1") == 0){
    reset();
    for(int i = 255; i >= 0; i--) {
      analogWrite(ledArray[0], i);
      delay(1);
    }
  }
 
  if(Comp("2") == 0){
    reset();
    for(int i = 255; i >= 0; i--) {
      analogWrite(ledArray[1], i);
      delay(1);
    }
  }
 
  if(Comp("3") == 0){
    reset();
    for(int i = 255; i >= 0; i--) {
      analogWrite(ledArray[2], i);
      delay(1);
    }
  }

  if(Comp("4") == 0){
    reset();
    for(int i = 255; i >= 0; i--) {
      analogWrite(ledArray[3], i);
      delay(1);
    }
  }

  if(Comp("5") == 0){
    reset();
    for(int i = 255; i >= 0; i--) {
      analogWrite(ledArray[4], i);
      delay(1);
    }
  }

  if(Comp("6") == 0){
    reset();
    for(int i = 255; i >= 0; i--) {
      analogWrite(ledArray[5], i);
      delay(1);
    }
  }

  if(Comp("7") == 0){
    reset();
    for(int i = 255; i >= 0; i--) {
      analogWrite(ledArray[0], i);
      analogWrite(ledArray[1], i);
      delay(1);
    }
  }

  if(Comp("8") == 0){
    reset();
    for(int i = 255; i >= 0; i--) {
      analogWrite(ledArray[3], i);
      analogWrite(ledArray[4], i);
      delay(1);
    }
  }

  if(Comp("9") == 0){
    reset();
    for(int i = 255; i >= 0; i--) {
      analogWrite(ledArray[0], i);
      analogWrite(ledArray[1], i);
      analogWrite(ledArray[2], i);
      analogWrite(ledArray[3], i);
      analogWrite(ledArray[4], i);
      analogWrite(ledArray[5], i);
      delay(1);
    }
  }
}

void reset() {
  if(currentProgram == "1" || currentProgram == "2" || currentProgram == "3" || currentProgram == "c" || currentProgram == "d" || currentProgram == "e") {
    analogWrite(ledArray[0], 0);
    analogWrite(ledArray[1], 0);
    analogWrite(ledArray[2], 0);
    analogWrite(ledArray[3], 0);
    analogWrite(ledArray[4], 0);
    analogWrite(ledArray[5], 0);
   }
  currentProgram = "";
}

void bassHit() {
  delay(1);
  
  if (bassHit_brightness > 0){
    bassHit_brightness--;
  }
  
  if (analogRead(jack01) > peak){
    bassHit_brightness = 255;
    analogWrite(light01, bassHit_brightness);
    analogWrite(light02, bassHit_brightness);
    analogWrite(light03, bassHit_brightness);
    analogWrite(light04, bassHit_brightness);
    analogWrite(light05, bassHit_brightness);
    analogWrite(light06, bassHit_brightness);
    delay(128);
  }
  
  analogWrite(light01, bassHit_brightness);
  analogWrite(light02, bassHit_brightness);
  analogWrite(light03, bassHit_brightness);
  analogWrite(light04, bassHit_brightness);
  analogWrite(light05, bassHit_brightness);
  analogWrite(light06, bassHit_brightness);
}

void bassHitBuildUp() {
  delay(1);
  
  if (bassHit_brightness > 0){
    bassHit_brightness--;
  }
  
  if (analogRead(jack01) > boomPeak) {
    Serial.write('z');
  }
  
  if (analogRead(jack01) > peak){
    bassHit_brightness = 255;
    analogWrite(light01, bassHit_brightness);
    analogWrite(light05, bassHit_brightness);
    delay(75);
    analogWrite(light02, bassHit_brightness);
    analogWrite(light04, bassHit_brightness);
    delay(75);
    analogWrite(light03, bassHit_brightness);
    delay(50);
    analogWrite(light06, bassHit_brightness);
    delay(128);
  }
  
  analogWrite(light01, bassHit_brightness);
  analogWrite(light02, bassHit_brightness);
  analogWrite(light03, bassHit_brightness);
  analogWrite(light04, bassHit_brightness);
  analogWrite(light05, bassHit_brightness);
  analogWrite(light06, bassHit_brightness);
}

void inverseBassHit() {
  delay(1);
  if (ibassHit_brightness < 255){
    ibassHit_brightness++;
  }
  
  if (analogRead(jack01) > peak){
    ibassHit_brightness = 0;
    analogWrite(light01, ibassHit_brightness);
    analogWrite(light02, ibassHit_brightness);
    analogWrite(light03, ibassHit_brightness);
    analogWrite(light04, ibassHit_brightness);
    analogWrite(light05, ibassHit_brightness);
    analogWrite(light06, ibassHit_brightness);
    delay(128);
  }
  
  analogWrite(light01, ibassHit_brightness);
  analogWrite(light02, ibassHit_brightness);
  analogWrite(light03, ibassHit_brightness);
  analogWrite(light04, ibassHit_brightness);
  analogWrite(light05, ibassHit_brightness);
  analogWrite(light06, ibassHit_brightness);
}

void breather() {
  if (breathe_brightness > 10 && breathe_direction == 0){
    breathe_brightness--;
  }
  
  if(breathe_brightness < 240 && breathe_direction == 1){
    breathe_brightness++;
  }
  
  if (breathe_brightness == 10){
    breathe_direction = 1;
    delay(300);
  } else if (breathe_brightness == 240) {
    breathe_direction = 0;
    delay(100);
  }
  
  analogWrite(light01, breathe_brightness);
  analogWrite(light02, breathe_brightness);
  analogWrite(light03, breathe_brightness);
  analogWrite(light04, breathe_brightness);
  analogWrite(light05, breathe_brightness);
  analogWrite(light06, breathe_brightness);
  delay(8);
}

void candle() {
  delay(75);
  analogWrite(light01, random(120)+135);
  analogWrite(light02, random(120)+135);
  analogWrite(light03, random(120)+135);
  analogWrite(light04, random(120)+135);
  analogWrite(light05, random(120)+135);
  analogWrite(light06, random(120)+135);
}