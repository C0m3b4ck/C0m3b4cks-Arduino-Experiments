#define BLUE 3
#define GREEN 5
#define RED 6

unsigned long previousMillis = 0;
int flashState = 0;  // 0=OFF, 1=ON
int morseStep = 0;
int interval = 250;
int patternLength = 11;

int sosPattern[] = {1,1,1, 2,3,3,3, 2,1,1,1, 2,2,2,2,2,2,2,2,2,2,2,2,2};  // 1=dot, 3=dash, 2=space

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    int patternVal = sosPattern[morseStep];
    
    if (flashState == 0) {  // Currently OFF - start flash
      if (patternVal == 2) {  // Space: skip to OFF time
        interval = 250;
        morseStep++;
      } else {
        flashState = 1;  // Turn ON
        interval = (patternVal == 1) ? 250 : 750;  // Dot or dash duration
        analogWrite(RED, 255);
        analogWrite(GREEN, 255);
        analogWrite(BLUE, 255);
      }
    } else {  // Currently ON - turn OFF and advance
      flashState = 0;  // Turn OFF
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
      interval = 250;  // OFF time between elements
      morseStep++;
    }
    
    if (morseStep >= patternLength) morseStep = 0;
    
    Serial.print("Step:"); Serial.print(morseStep);
    Serial.print(" Pattern:"); Serial.print(patternVal);
    Serial.print(" State:"); Serial.print(flashState);
    Serial.print(" Interval:"); Serial.println(interval);
  }
}
