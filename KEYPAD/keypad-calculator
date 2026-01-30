//original version by https://elegoo.com
//remade by C0m3b4ck under APL 2.0

#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

char operation_type = 0; 
int operation_value = 0;
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  Serial.println("=== Custom Keypad Calculator Ready ===");
  Serial.println("A=Add, B=Subtract, C=Multiply, D=Divide, #=Clear");
}

void loop(){
  static bool firstNumber = true;
  
  char customKey = customKeypad.getKey();

  if (customKey) {
    // Reset firstNumber flag when operation changes
    if (customKey == 'A' || customKey == 'B' || customKey == 'C' || customKey == 'D') {
      firstNumber = true;
      operation_type = customKey;
    }
    
    // Operation selection
    if (customKey == 'A') Serial.println("Operation: addition");
    else if (customKey == 'B') Serial.println("Operation: subtraction");
    else if (customKey == 'C') Serial.println("Operation: multiplication");
    else if (customKey == 'D') Serial.println("Operation: division");
    else if (customKey == '#') {
      operation_type = 0;
      operation_value = 0;
      firstNumber = true;
      Serial.println("Cleared all values.");
      return;
    }
    else if (customKey == '*') {
      Serial.println("Non-math mode.");
      return;
    }
    //Single numeric handler - operates ONLY if operation_value exists
    else if (customKey >= '0' && customKey <= '9') {
      int number = customKey - '0';
      
      // CASE 1: No operation selected - just set value
      if (operation_type == 0) {
        operation_value = number;
        Serial.print("Set value: "); Serial.println(number);
      }
      // CASE 2: First number after operation selected
      else if (firstNumber && operation_value == 0) {
        operation_value = number;
        Serial.print("First number: "); Serial.println(number);
        firstNumber = false;
      }
      // CASE 3: OPERATE on existing operation_value (KEY FIX)
      else if (operation_value != 0) {
        if (operation_type == 'A') {
          operation_value += number;
          printResult("addition", number);
        }
        else if (operation_type == 'B') {
          operation_value -= number;
          printResult("subtraction", number);
        }
        else if (operation_type == 'C') {
          operation_value *= number;
          printResult("multiplication", number);
        }
        else if (operation_type == 'D') {
          if (number != 0) {
            operation_value /= number;
            printResult("division", number);
          } else {
            Serial.println("ERROR: Division by zero!");
          }
        }
      }
      else {
        Serial.println("No valid operation or value.");
      }
    }
  }
}

void printResult(const char* opName, int number) {
  Serial.print(opName); Serial.print(" | Result: "); 
  Serial.print(operation_value); Serial.print(" | Used: "); 
  Serial.println(number);
}
