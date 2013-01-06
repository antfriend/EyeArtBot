//
//


#include <Servo.h> 
 
Servo Eye_Horizontal;  // create servo object to control a servo 
Servo Eye_Vertical; 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  Eye_Horizontal.attach(1);  // attaches the servo on pin 9 to the servo object 
  Eye_Vertical.attach(0);
} 
 
 
void loop() 
{ 
  int min_horizontal = 20;
  int mid_horizontal = 90;
  int max_horizontal = 160;
  
  int min_vertical = 20;
  int mid_vertical = 50;
  int max_vertical = 90;
  
  Eye_Vertical.write(mid_vertical);
  Eye_Horizontal.write(mid_horizontal);
  delay(3000);
  
  // right to left
  for(pos = min_horizontal; pos < max_horizontal; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    Eye_Horizontal.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  //left to right
  for(pos = max_horizontal; pos>=min_horizontal; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    Eye_Horizontal.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  
  Eye_Vertical.write(mid_vertical);
  Eye_Horizontal.write(mid_horizontal);
  delay(3000);
  
  //top to bottom
  for(pos = min_vertical; pos < max_vertical; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    Eye_Vertical.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  //top to bottom
  for(pos = max_vertical; pos < min_vertical; pos -= 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    Eye_Vertical.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  
  
} 
