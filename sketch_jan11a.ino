/*

Title        : Arduino Stepper Motor Controller For Robot Arm (ORS)
Author       : Joshua Wong
Assistance   : Jon Walters, Bernardo Perez
Purpose      : Based on four pushbuttons, the stepper motor will either take a step CCW or CW, will reset and move back to its initial location when it turned on, or set its current location to its new starting location
Written      : 01/11/2022
Last Updated : 03/28/2022
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

// enables
const int left1 = 14;
const int center1 = 15;
const int right1 = 16;

const int d = 8;
const int c = 9;
const int b = 10;
const int a = 11;


// offsets from location 0
int offSet = 0;

// each step is 1.8 degrees
const int stepsPerRevolution = 100;
 
void setup()
{
  // Declare pins as outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
  pinMode(left1, OUTPUT);
  pinMode(center1, OUTPUT);
  pinMode(right1, OUTPUT);
  
  pinMode(d, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(a, OUTPUT);
  
  
  
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
        
        
          while (buttState1) {
             buttState1 = digitalRead(BUTTON1);
          }
          
          // set direction to CCW
          digitalWrite(dirPin, HIGH);
          
          // take step
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(2000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(2000);
          
          offSet++;
      } else if (buttState1 == LOW && buttState2 == HIGH && RES_STATE == LOW && zeroState == LOW){
        
          while (buttState2) {
            buttState2 = digitalRead(BUTTON2);
          }
        
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
        
        
          while (RES_STATE) {
            RES_STATE = digitalRead(RES_BUTT);
          }
          
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
        
          while (zeroState) {
            zeroState = digitalRead(newZeroButt);
          }
          
          x = -1; // incremented to 0
          offSet = 0;
      }
      
      if (offSet > 199) {
        offSet = 0;
      }
      
      int a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3;
      
      int offCpy = offSet;
      
      int hund = offCpy / 100;
      
      int ones = offCpy % 10;
      int tens = (offCpy % 100) / 10;
      
      // hundreds disp
      switch (hund) {
        case 1:
          d1 = 0;
          c1 = 0;
          b1 = 0;
          a1 = 1;
          break;
        
        case 2:
          d1 = 0;
          c1 = 0;
          b1 = 1;
          a1 = 0;
          break;
        
        default:
          d1 = 0;
          c1 = 0;
          b1 = 0;
          a1 = 0;
          break;
      }
      
      
     
      
      // tens disp
      switch (tens) {
        case 1:
          d2 = 0;
          c2 = 0;
          b2 = 0;
          a2 = 1;
          break;
        
        case 2:
          d2 = 0;
          c2 = 0;
          b2 = 1;
          a2 = 0;
          break;
        
        case 3:
          d2 = 0;
          c2 = 0;
          b2 = 1;
          a2 = 1;
          break;
          
        case 4:
          d2 = 0;
          c2 = 1;
          b2 = 0;
          a2 = 0;
          break;
          
        case 5:
          d2 = 0;
          c2 = 1;
          b2 = 0;
          a2 = 1;
          break;
          
        case 6:
          d2 = 0;
          c2 = 1;
          b2 = 1;
          a2 = 0;
          break;
          
        case 7:
          d2 = 0;
          c2 = 1;
          b2 = 1;
          a2 = 1;
          break;
          
        case 8:
          d2 = 1;
          c2 = 0;
          b2 = 0;
          a2 = 0;
          break;
          
        case 9:
          d2 = 1;
          c2 = 0;
          b2 = 0;
          a2 = 1;
          break;
        
        default:
          d2 = 0;
          c2 = 0;
          b2 = 0;
          a2 = 0;
          break;
      }
      
      
      
      
      // ones disp
      switch (ones) {
        case 1:
          d3 = 0;
          c3 = 0;
          b3 = 0;
          a3 = 1;
          break;
        
        case 2:
          d3 = 0;
          c3 = 0;
          b3 = 1;
          a3 = 0;
          break;
        
        case 3:
          d3 = 0;
          c3 = 0;
          b3 = 1;
          a3 = 1;
          break;
          
        case 4:
          d3 = 0;
          c3 = 1;
          b3 = 0;
          a3 = 0;
          break;
          
        case 5:
          d3 = 0;
          c3 = 1;
          b3 = 0;
          a3 = 1;
          break;
          
        case 6:
          d3 = 0;
          c3 = 1;
          b3 = 1;
          a3 = 0;
          break;
          
        case 7:
          d3 = 0;
          c3 = 1;
          b3 = 1;
          a3 = 1;
          break;
          
        case 8:
          d3 = 1;
          c3 = 0;
          b3 = 0;
          a3 = 0;
          break;
          
        case 9:
          d3 = 1;
          c3 = 0;
          b3 = 0;
          a3 = 1;
          break;
        
        default:
          d3 = 0;
          c3 = 0;
          b3 = 0;
          a3 = 0;
          break;
      }
      
            
      digitalWrite(d, d1);
      digitalWrite(c, c1);
      digitalWrite(b, b1);
      digitalWrite(a, a1);
      
      digitalWrite(left1, LOW);
      digitalWrite(center1, HIGH);
      digitalWrite(right1, HIGH);
      
      digitalWrite(left1, HIGH);
      digitalWrite(center1, HIGH);
      digitalWrite(right1, HIGH);
      
       
      digitalWrite(d, d2);
      digitalWrite(c, c2);
      digitalWrite(b, b2);
      digitalWrite(a, a2);
      
      digitalWrite(left1, HIGH);
      digitalWrite(center1, LOW);
      digitalWrite(right1, HIGH);
      
      digitalWrite(left1, HIGH);
      digitalWrite(center1, HIGH);
      digitalWrite(right1, HIGH);
      
      digitalWrite(d, d3);
      digitalWrite(c, c3);
      digitalWrite(b, b3);
      digitalWrite(a, a3);
     
      digitalWrite(left1, HIGH);
      digitalWrite(center1, HIGH);
      digitalWrite(right1, LOW);
      
      digitalWrite(left1, HIGH);
      digitalWrite(center1, HIGH);
      digitalWrite(right1, HIGH);
     
      
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
