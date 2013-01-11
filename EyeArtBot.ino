#include <Servo.h> 
 
Servo Eye_Horizontal;  // create servo object to control a servo 
Servo Eye_Vertical; 

int min_horizontal = 10;
int mid_horizontal = 90;
int max_horizontal = 140;

int min_vertical = 30;
int mid_vertical = 50;
int max_vertical = 65;

int pos = 0;    // variable to store the servo position 

void right_to_left()
{
  // right to left
  for(pos = min_horizontal; pos < max_horizontal; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    Eye_Horizontal.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }  
}

void Look_Center_Left_Right_Up_Down()
{
  int theDelay = 3000;
  Look_Center();
  delay(theDelay);
  Look_Left();
  delay(theDelay);
  Look_Right();
  delay(theDelay);  
  Look_Center();
  delay(theDelay);
  Look_Up();
  delay(theDelay);  
  Look_Down();
  delay(theDelay);  
}

void Look_Center()
{
  LookOverThere(mid_horizontal, mid_vertical);
}

void Look_Left()
{
  LookOverThere(max_horizontal, mid_vertical);
}

void Look_Right()
{
  LookOverThere(min_horizontal, mid_vertical);
}

void Look_Up()
{
  LookOverThere(mid_horizontal, min_vertical);
}

void Look_Down()
{
  LookOverThere(mid_horizontal, max_vertical);
}

void LookOverThere(int x, int y)
{
  Eye_Horizontal.write(x);
  Eye_Vertical.write(y);
}

void setup() 
{ 
  Eye_Horizontal.attach(1);  // attaches the servo on pin 9 to the servo object 
  Eye_Vertical.attach(0);
  Eye_Vertical.write(mid_vertical);
  Eye_Horizontal.write(mid_horizontal);
  delay(3000);
} 
 

void loop() 
{ 
  
  Look_Center_Left_Right_Up_Down();
  Look_Center_Left_Right_Up_Down();
  Look_Center_Left_Right_Up_Down();
  Look_Center_Left_Right_Up_Down();
  Look_Center();
  delay(9000);
  
  right_to_left();
   
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
