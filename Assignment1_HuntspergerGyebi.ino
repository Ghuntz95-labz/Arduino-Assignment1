//ASSIGNMENT 1
//NAME: GYEBI HUNSTPERGER
//INDEX NUMBER: 2526403526


//Setting Up Variables
int startValue = 5;
int ledPin = 13;

//Fucntion For Flashing Led The Desired Number Of Times
void flashLED(int times) {
  for(int i = 0; i < times; i++){
    digitalWrite(ledPin, HIGH); // LED ON
    delay(150);
    digitalWrite(ledPin, LOW); // LED OFF
    delay(150);
  }
}

//Setup Function: Runs Once After Upload
void setup(){
  
  pinMode(ledPin, OUTPUT);//Pin Output Setup
  
  Serial.begin(9600);//Serial Monitor Initialization
  
  Serial.println("  ");
  Serial.println("=== Smart Countdown Starting ===");
  int count = startValue;
  while (count != 0){
    Serial.print("Count: ");
    Serial.println(count);
    flashLED(6); //flashes or blinks LED, Pin 13
    delay(1000);
    count = count - 1;
  }
  Serial.println("=== Countdown Complete ===");
}

//void function: Runs On Repeat After Upload
void loop(){

 }
