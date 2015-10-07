/******************************************************************************
SparkFun Spooky Sketch Sounds
Sarah @ SparkFun Electronics>
September 2015
https://github.com/sparkfun/Spooky_Sketches

Development environment specifics:
Arduino 1.6.5

This code is released under the [MIT License](http://opensource.org/licenses/MIT).
Please review the LICENSE.md file included with this example. If you have any questions 
or concerns with licensing, please contact techsupport@sparkfun.com.

Distributed as-is; no warranty is given.
******************************************************************************/

int pirPin = 2; //digital 2 is motion sensor pin

bool oldState;
int showType = 0;     //value to tell which sound to trigger

void setup(){
 Serial.begin(9600); 
 pinMode(pirPin, INPUT);  //reciving info from motion sensor pin
 pinMode(9, INPUT);      
 pinMode(10, INPUT);     
 pinMode(11, INPUT);    
 pinMode(12, INPUT);     
 pinMode(13, INPUT);     
 digitalWrite(9, LOW);   //trigger off
 digitalWrite(10, LOW);   //trigger off
 digitalWrite(11, LOW);   //trigger off
 digitalWrite(12, LOW);   //trigger off
 digitalWrite(13, LOW);   //trigger off
}


void loop(){
  int pirVal = digitalRead(pirPin);  //read the motion sensor value
  Serial.print(pirVal);
  Serial.print(" ");
  Serial.print(showType);
  Serial.println(" ");
  
  if(pirVal == LOW && oldState == HIGH){ //was motion detected 
    showType++;          //switch to the next case
    if (showType > 4)    //if over 4
      showType=0;        //set it back to 0 
    startShow(showType); //run the case
    pinMode(9, INPUT);      
    pinMode(10, INPUT);     
    pinMode(11, INPUT);    
    pinMode(12, INPUT);     
    pinMode(13, INPUT);     
    digitalWrite(9, LOW);   //trigger off
    digitalWrite(10, LOW);   //trigger off
    digitalWrite(11, LOW);   //trigger off
    digitalWrite(12, LOW);   //trigger off
    digitalWrite(13, LOW);   //trigger off
  }
  oldState = pirVal;
}


void startShow(int i) {
  switch(i){
    case 0: pinMode(9, OUTPUT);
            digitalWrite(9, LOW);     //first sound trigger
            delay(2000);
            break;
    case 1: pinMode(10, OUTPUT);
            digitalWrite(10, LOW);    //second sound trigger
            delay(2000);
            break;
    case 2: pinMode(11, OUTPUT);
            digitalWrite(11, LOW);    //third sound trigger
            delay(2000);
            break;
    case 3: pinMode(12, OUTPUT);
            digitalWrite(12, LOW);    //forth sound trigger
            delay(2000);
            break;
    case 4: pinMode(13, OUTPUT);
            digitalWrite(13, LOW);    //fifth sound trigger
            delay(2000);
            break;

  }
}



