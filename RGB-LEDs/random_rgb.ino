//www.elegoo.com
//2016.12.8 - Modified for random colors

#define BLUE 3
#define GREEN 5
#define RED 6

int currentRed = 0;
int currentGreen = 0;
int currentBlue = 0;
int targetRed = 0;
int targetGreen = 0;
int targetBlue = 0;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  randomSeed(analogRead(0)); // Seed random generator
}

void loop() {
  #define delayTime 10
  
  // Pick new random target color
  targetRed = random(256);   // 0-255
  targetGreen = random(256);
  targetBlue = random(256);
  
  // Fade smoothly to target color
  fadeToColor(currentRed, targetRed, RED);
  fadeToColor(currentGreen, targetGreen, GREEN);
  fadeToColor(currentBlue, targetBlue, BLUE);
  
  // Update current values to targets for next cycle
  currentRed = targetRed;
  currentGreen = targetGreen;
  currentBlue = targetBlue;
}

void fadeToColor(int current, int target, int pin) {
  int step = (target > current) ? 1 : -1;
  while (current != target) {
    current += step;
    analogWrite(pin, current);
    delay(delayTime);
  }
}
