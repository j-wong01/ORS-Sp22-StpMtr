const int d = 8;
const int c = 9;
const int b = 10;
const int a = 11;

const int left1 = 14;
const int center1 = 15;
const int right1 = 16;


void setup()
{
  // Declare pins as outputs
  
    pinMode(left1, OUTPUT);
  pinMode(center1, OUTPUT);
  pinMode(right1, OUTPUT);
  
  
  pinMode(d, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(a, OUTPUT);
  
  
  
}



  void loop(){
    
    int d3, c3, b3, a3;
    int d2, c2, b2, a2;
    int d1, c1, b1, a1;
    int ones;
    
    for (ones = 0; ones < 16; ones++) {
      
      
      //hunds
      switch (ones) {
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
        
        case 3:
          d1 = 0;
          c1 = 0;
          b1 = 1;
          a1 = 1;
          break;
          
        case 4:
          d1 = 0;
          c1 = 1;
          b1 = 0;
          a1 = 0;
          break;
          
        case 5:
          d1 = 0;
          c1 = 1;
          b1 = 0;
          a1 = 1;
          break;
          
        case 6:
          d1 = 0;
          c1 = 1;
          b1 = 1;
          a1 = 0;
          break;
          
        case 7:
          d1 = 0;
          c1 = 1;
          b1 = 1;
          a1 = 1;
          break;
          
        case 8:
          d1 = 1;
          c1 = 0;
          b1 = 0;
          a1 = 0;
          break;
          
        case 9:
          d1 = 1;
          c1 = 0;
          b1 = 0;
          a1 = 1;
          break;
          
         case 10:
          d1 = 1;
          c1 = 0;
          b1 = 1;
          a1 = 0;
          break;
          
          case 11:
          d1 = 1;
          c1 = 0;
          b1 = 1;
          a1 = 1;
          break;
          
          
          case 12:
          d1 = 1;
          c1 = 1;
          b1 = 0;
          a1 = 0;
          break;
          
          
          case 13:
          d1 = 1;
          c1 = 1;
          b1 = 0;
          a1 = 1;
          break;
          
          
          case 14:
          d1 = 1;
          c1 = 1;
          b1 = 1;
          a1 = 0;
          break;
          
          
          case 15:
          d1 = 1;
          c1 = 1;
          b1 = 1;
          a1 = 1;
          break;
        
        default:
          d1 = 0;
          c1 = 0;
          b1 = 0;
          a1 = 0;
          break;
      }
      
      
      
      // tens
      switch (ones) {
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
          
         case 10:
          d2 = 1;
          c2 = 0;
          b2 = 1;
          a2 = 0;
          break;
          
          case 11:
          d2 = 1;
          c2 = 0;
          b2 = 1;
          a2 = 1;
          break;
          
          
          case 12:
          d2 = 1;
          c2 = 1;
          b2 = 0;
          a2 = 0;
          break;
          
          
          case 13:
          d2 = 1;
          c2 = 1;
          b2 = 0;
          a2 = 1;
          break;
          
          
          case 14:
          d2 = 1;
          c2 = 1;
          b2 = 1;
          a2 = 0;
          break;
          
          
          case 15:
          d2 = 1;
          c2 = 1;
          b2 = 1;
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
          
         case 10:
          d3 = 1;
          c3 = 0;
          b3 = 1;
          a3 = 0;
          break;
          
          case 11:
          d3 = 1;
          c3 = 0;
          b3 = 1;
          a3 = 1;
          break;
          
          
          case 12:
          d3 = 1;
          c3 = 1;
          b3 = 0;
          a3 = 0;
          break;
          
          
          case 13:
          d3 = 1;
          c3 = 1;
          b3 = 0;
          a3 = 1;
          break;
          
          
          case 14:
          d3 = 1;
          c3 = 1;
          b3 = 1;
          a3 = 0;
          break;
          
          
          case 15:
          d3 = 1;
          c3 = 1;
          b3 = 1;
          a3 = 1;
          break;
        
        default:
          d3 = 0;
          c3 = 0;
          b3 = 0;
          a3 = 0;
          break;
      }
      
      
      
      
      
      int k = 0;
      
      
      while (k < 5000) {
      // send to displays:
      
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
      
      k++;
      }
      
      
    }
    delay(1000);
    
  }


