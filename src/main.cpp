#include <Arduino.h>

// 3631AS 1-Digit Code (Right-most Digit 3 active)

// Define Segment Pins using standard NodeMCU/D1 Mini labels
const int segA = D1;  // GPIO5
const int segB = D3;  // GPIO0 
const int segC = D5;  // GPIO14
const int segD = D6;  // GPIO12
const int segE = D7;  // GPIO13
const int segF = D0;  // GPIO16
const int segG = D8;  // GPIO15

// 7-Segment lookup table for numbers 0-9 (1 = ON, 0 = OFF)
const byte numPatterns[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

// Function to print a single number
void printNumber(int number) {
  digitalWrite(segA, numPatterns[number][0]);
  digitalWrite(segB, numPatterns[number][1]);
  digitalWrite(segC, numPatterns[number][2]);
  digitalWrite(segD, numPatterns[number][3]);
  digitalWrite(segE, numPatterns[number][4]);
  digitalWrite(segF, numPatterns[number][5]);
  digitalWrite(segG, numPatterns[number][6]);
}

void setup() {
  // Set all segment pins as OUTPUTs
  pinMode(segA, OUTPUT); 
  pinMode(segB, OUTPUT); 
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT); 
  pinMode(segE, OUTPUT); 
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
}

void loop() {
  // Loop through numbers 0 to 9, changing every 1 second
  for (int i = 0; i <= 9; i++) {
    printNumber(i);
    delay(1000); 
  }
}
