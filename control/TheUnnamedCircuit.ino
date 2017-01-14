
// 
// The Unnamed Circuit
// 
// Made by smpss91341 smpss91341
// License: CC-BY-SA 3.0

int Nl=-10;



int Zo=0;
int Ps=5;
int Pl=10;
float y1,y2,y3,y4,y5,y6,y7,y8;

int irrecv;
float setpoint,setpoint2;
float a,b,c,d,e,f,g,h;

float errpoint,getTemp,fin ;
float check;

void setup()
{
  Serial.begin(9600);

}


void loop() {

  //gettemp = Serial.read();

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
      
    
      
  }
      //Serial.println(setpoint);
      //Serial.println(setpoint2);
      Serial.println(fin);
      Serial.println("=======");
      
    delay(5000);
  
}
