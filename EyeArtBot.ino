  #include <Servo.h> 
   
  Servo Eye_Horizontal;  // create servo object to control a servo 
  Servo Eye_Vertical; 
  
  int min_horizontal = 30;
  int mid_horizontal = 90;
  int max_horizontal = 130;
  
  int min_vertical = 32;
  int mid_vertical = 50;
  int max_vertical = 70;
  
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
  
  void left_to_right()
  {
    //left to right
    for(pos = max_horizontal; pos>=min_horizontal; pos-=1)     // goes from 180 degrees to 0 degrees 
    {                                
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
    Eye_Vertical.write(mid_vertical);
    Eye_Horizontal.write(mid_horizontal);
    Eye_Horizontal.attach(1);  // attaches the servo on pin 9 to the servo object 
    Eye_Vertical.attach(0);
    delay(100);
    randomSeed(analogRead(0));
    //StartSequence();    
  } 
   
  void RandomPosition(int centerH, int centerV, int theRadius)
  {
    int randH;
    int randV;
    randH = random(centerH-theRadius,centerH+theRadius);
    if(randH < min_horizontal)
    {
      randH = min_horizontal;
    }
    if(randH > max_horizontal)
    {
      randH = max_horizontal;
    }    
    randV = random(centerV-theRadius,centerV+theRadius);
    if(randV < min_vertical)
    {
      randV = min_vertical;
    }
    if(randV > max_vertical)
    {
      randV = max_vertical;
    }        
    Eye_Horizontal.write(randH);
    Eye_Vertical.write(randV);
  }
  
  void RandomMiddling()
  {
    int theRadius = 50;
    RandomPosition(mid_horizontal, mid_vertical, theRadius);  
  }
  
  void RandomDelay()
  {
    int randD = random(1,2000);
    delay(randD);
  }
  
  void StartSequence()
  {
    Look_Center_Left_Right_Up_Down();
    Look_Center_Left_Right_Up_Down();
  
    Look_Center();
    delay(3000);
    
    right_to_left();
    left_to_right();
    
    Look_Center();
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
  
  void loop() 
  { 
    //StartSequence();
     RandomDelay();
     RandomMiddling();
     //RandomPosition();
    
  } 

