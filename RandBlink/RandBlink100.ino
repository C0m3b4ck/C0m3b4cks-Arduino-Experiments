/*
  RandBlink

  Randomized LED flashing.

  Made by C0m3b4ck under APL 2.0

  Original script available here:
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

//global variables
int randomizeCounter = 0; //counts how many times randomization ran

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); //required for message printing (like the one in randomize function)
  randomSeed(analogRead(A0)); //used for randomization
}

int randomize() {
  int randomizeCounterNum;
  //prevents randomized number from not being smaller than 0
  if (randomizeCounterNum <= 0) {
  randomizeCounterNum = random(1, 1000);
  } else {
    randomizeCounterNum = randomizeCounter;
  }

  int randNum = random(1, (1000 - randomizeCounterNum)); //the more times randomized, the smaller the randomization range
  randomizeCounter = randomizeCounter + 1;
  String message = "Randomization no.: " + String(randomizeCounter) + " Randomized number: " + String(randNum) + " Max randomized number: " + String(1000 - randomizeCounter);
  Serial.println(message);  // Prints to Serial Monitor

  return randNum;  // Return value for delay use
}

void loop() {
// the loop function runs over and over again forever
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(randomize());                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(randomize());                       // wait for a second
}
