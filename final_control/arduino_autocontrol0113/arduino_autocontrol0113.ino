#include<Stepper.h>
#define STEPS 3200
#include <math.h>
#include <Servo.h>

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19
/*

#define E_STEP_PIN         26
#define E_DIR_PIN          28
#define E_ENABLE_PIN       24

#define Q_STEP_PIN         36
#define Q_DIR_PIN          34
#define Q_ENABLE_PIN       30

#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            13

#define FAN_PIN            9

#define PS_ON_PIN          12
#define KILL_PIN           -1

#define HEATER_0_PIN       10
#define HEATER_1_PIN       8
#define TEMP_0_PIN          13   // ANALOG NUMBERING
#define TEMP_1_PIN          14   // ANALOG NUMBERING
*/

int a = 0;     //  gen counter
int stop_position = 95;
int velocity = 20;
Servo myservo;


void setup() {
  
  myservo.attach(4,500,2400); 
  
  pinMode(X_STEP_PIN  , OUTPUT);
  pinMode(X_DIR_PIN    , OUTPUT);
  pinMode(X_ENABLE_PIN    , OUTPUT);
  
  pinMode(Y_STEP_PIN  , OUTPUT);
  pinMode(Y_DIR_PIN    , OUTPUT);
  pinMode(Y_ENABLE_PIN    , OUTPUT);
  
  pinMode(Z_STEP_PIN  , OUTPUT);
  pinMode(Z_DIR_PIN    , OUTPUT);
  pinMode(Z_ENABLE_PIN    , OUTPUT);
  


    

}





void loop () {
  myservo.write(0);
 // int getcontrol = returnValue();
  int var = 1;
    switch(var){
      case 1:
            power();
     
            break;
      case 2:
            tmp_up();
            servoTouch();
            break;
           
      case 3:
           tmp_down();
           servoTouch();
           break; 
    }

  
 

   }
   
   void servoTouch(){
    myservo.write(0);
    delay(1000);
    myservo.write(12);
    delay(1000);
    myservo.write(0);

}
  
void power(){
  
  
  //Z軸 前後
  digitalWrite(Z_DIR_PIN,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 1600; x++) {
    digitalWrite(Z_STEP_PIN,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(Z_STEP_PIN,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
  digitalWrite(Y_DIR_PIN,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 3200; x++) {
    digitalWrite(Y_STEP_PIN,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(Y_STEP_PIN,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
  servoTouch();
  delay(1000);
  
  digitalWrite(Z_DIR_PIN,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 1600; x++) {
    digitalWrite(Z_STEP_PIN,HIGH);
    delayMicroseconds(500);
    digitalWrite(Z_STEP_PIN,LOW);
    delayMicroseconds(500);
  }
  delay(1000);    
      

  digitalWrite(Y_DIR_PIN,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 3200; x++) {
    digitalWrite(Y_STEP_PIN,HIGH);
    delayMicroseconds(500); 
    digitalWrite(Y_STEP_PIN,LOW);
    delayMicroseconds(500);
  }
  }


void tmp_up(){
  
    digitalWrite(Y_DIR_PIN,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 3200; x++) {
    digitalWrite(Y_STEP_PIN,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(Y_STEP_PIN,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  digitalWrite(Y_DIR_PIN,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 3200; x++) {
    digitalWrite(Y_STEP_PIN,HIGH);
    delayMicroseconds(500);
    digitalWrite(Y_STEP_PIN,LOW);
    delayMicroseconds(500);
  }
  delay(1000);
  }


void tmp_down(){
  
    digitalWrite(Y_DIR_PIN,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 3200; x++) {
    digitalWrite(Y_STEP_PIN,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(Y_STEP_PIN,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  digitalWrite(Y_DIR_PIN,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 3200; x++) {
    digitalWrite(Y_STEP_PIN,HIGH);
    delayMicroseconds(500);
    digitalWrite(Y_STEP_PIN,LOW);
    delayMicroseconds(500);
  }
  delay(1000);
  }
  
  
  int returnValue(int chose){
  
  float y1,y2,y3,y4,y5,y6,y7,y8;

  int irrecv;
  float setpoint,setpoint2;
  float a,b,c,d,e,f,g,h;
  
  float errpoint,getTemp1,fin ;
  float check;
  
  float getTemp = 24.0;
  
  errpoint = getTemp-28;
  
  
 
  y1 =  0.2*errpoint-2;  //冷28
  y2 = -0.2*errpoint-1 ;  //冷28
  y3 = 0.2*errpoint-1; //28  
  y4 = -0.2*errpoint; //28 
  y5 = 0.2*errpoint;   //26
  y6 = -0.2*errpoint+1;  //26
  y7 = 0.2*errpoint+1;  //24
  y8 = -0.2*errpoint+2;  //24
  float x[8] = {y1,y2,y3,y4,y5,y6,y7,y8};
  
  //x = myarray[y1,y2,y3,y4,y5,y6,y7,y8];
  for(int i=0; i<8; i++){
    //Serial.println(x[i]);
    check = x[i];
    if (x[i]<=1 && x[i]>=0){
      switch(i){
        case 0: 
          a = x[i]*28;
       // Serial.println(setpoint);
              break;
        
        case 1: 
          b = x[i]*28;
         // Serial.println(setpoint2);
              break;
        
        case 2:
          c = x[i]*28;
         // Serial.println(setpoint);
              break;
    
        
        case 3: 
          d = x[i]*28;
         // Serial.println(setpoint2);
            break;
        
        case 4: 
          e = x[i]*26;
          
            break;
        
        case 5: 
          f = x[i]*26;
         // Serial.println(setpoint2);
            break;
        
        case 6: 
          g = x[i]*26;
          
            break;
        
        case 7: 
          h = x[i]*24;
         // Serial.println(setpoint2);
            break;   
      }
    }

      fin = a+b+c+d+e+f+g+h;
      
    
      if(fin>28)
      {
        return 1;
      }
      else if(fin<28)
      {
        return 2;
      }
      else{
        return 3;
      }
      
  }

      Serial.println(fin);
      Serial.println("=======");
      
      
    delay(5000);

}



    
  

