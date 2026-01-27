#define BLUE 3
#define GREEN 5
#define RED 6

unsigned long previousMillis = 0;
unsigned long interval = 250;
int flashVal = 0;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    // Toggle flash: 0=off, 255=on  
    flashVal = (flashVal == 0) ? 255 : 0;
    
    analogWrite(RED, flashVal);
    analogWrite(GREEN, flashVal);
    analogWrite(BLUE, flashVal);
  }
}
