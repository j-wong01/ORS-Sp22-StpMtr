/*

Title        : Arduino Stepper Motor Controller For Robot Arm (ORS)
Author       : Joshua Wong
Assistance   : Jon Walters, Bernardo Perez
Purpose      : Based on four pushbuttons, the stepper motor will either take a step CCW or CW, will reset and move back to its initial location when it turned on, or set its current location to its new starting location
Written      : 01/11/2022
Last Updated : 02/20/2022
*/

// i/o pins
const int dirPin = 2;
const int stepPin = 3;
const int BUTTON1 = 4;
const int BUTTON2 = 5;
const int RES_BUTT = 6;
const int newZeroButt = 7;


// states of pushbuttons
int buttState1 = 0;
int buttState2 = 0;
int RES_STATE = 0;
int zeroState = 0;


// offsets from location 0
int offSet = 0;

// each step is 1.8 degrees
const int stepsPerRevolution = 100;
 
void setup()
{
  // Declare pins as outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

  void loop()
  {

    // initially set direction to CCW
    digitalWrite(dirPin, HIGH);
    
    for(int x = 0; x < stepsPerRevolution; x++) {
      
      // read states
      buttState1 = digitalRead(BUTTON1);
      buttState2 = digitalRead(BUTTON2);
      RES_STATE = digitalRead(RES_BUTT);
      zeroState = digitalRead(newZeroButt);

      
      // determine which direction to step or reset location
      if (buttState1 == LOW && buttState2 == LOW && RES_STATE == LOW && zeroState == LOW) {
          x--;
      } else if (buttState1 == HIGH && buttState2 == LOW && RES_STATE == LOW && zeroState == LOW){
          
          // set direction to CCW
          digitalWrite(dirPin, HIGH);
          
          // take step
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(2000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(2000);
          
          offSet++;
      } else if (buttState1 == LOW && buttState2 == HIGH && RES_STATE == LOW && zeroState == LOW){
        
          // set direction to CW
          digitalWrite(dirPin, LOW);
          
          // take step
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(2000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(2000);
        
          offSet--;
          
      // reset to initial location (degrees) of motor  
      } else if (buttState1 == LOW && buttState2 == LOW && RES_STATE == HIGH && zeroState == LOW) {
          x = -1; // incremented to 0
          
          // move CCW or CW depending on which direction was taken more
          
          if (offSet >= 0) {
            
            digitalWrite(dirPin, LOW);
          
            for (int k = 0; k < offSet; k++) {
              digitalWrite(stepPin, HIGH);
              delayMicroseconds(1000);
              digitalWrite(stepPin, LOW);
              delayMicroseconds(1000);
            }
            
          } else {
            
            digitalWrite(dirPin, HIGH);
            
            for (int k = offSet; k < 0; k++) {
              digitalWrite(stepPin, HIGH);
              delayMicroseconds(1000);
              digitalWrite(stepPin, LOW);
              delayMicroseconds(1000);
            }
            
          }
          
          offSet = 0;
          
      // set current step to location 0  
      } else if (buttState1 == LOW && buttState2 == LOW && RES_STATE == LOW && zeroState == HIGH) {
          
          x = -1; // incremented to 0
          offSet = 0;
      }
      delay(1000);
    }
  delay(1000); // Wait a second

  }
  
  
    
  
  /*
  // Set motor direction counterclockwise
  digitalWrite(dirPin, LOW);
 
  // Spin motor quickly
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  delay(1000); // Wait a second*/
  
  
  
  
  
  
  
  
  
  /*void loop()
{
  // Set motor direction clockwise
  digitalWrite(dirPin, HIGH);
 
  // Spin motor slowly
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }
  delay(1000); // Wait a second
 
  // Set motor direction counterclockwise
  digitalWrite(dirPin, LOW);
 
  // Spin motor quickly
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
} */




      
      
//      // take step
//      digitalWrite(stepPin, HIGH);
//      delayMicroseconds(2000);
//      digitalWrite(stepPin, LOW);
//      delayMicroseconds(2000);