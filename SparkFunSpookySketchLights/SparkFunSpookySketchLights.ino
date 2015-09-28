/******************************************************************************
SparkFun Spooky Sketch Lights
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

int pirPin = 2; //digital 2
int pumpkinPin = 8; //digital 8
int ghostPin = 9; //digital 9

void setup(){
 pinMode(pirPin, INPUT);         //getting info from motion sensor pin
 pinMode(pumpkinPin, OUTPUT);   //sending info to LED pin
 pinMode(ghostPin, OUTPUT);      //sending info to LED pin
 digitalWrite(pumpkinPin, LOW); //Set LED as off to start
 digitalWrite(ghostPin, LOW);    //Set LED as off to start
}


void loop(){
  int pirVal = digitalRead(pirPin); //read motion sensor
  
  if(pirVal == LOW){ //was motion detected
    digitalWrite(pumpkinPin, HIGH); //Turn LED on
    digitalWrite(ghostPin, HIGH);    //Turn LED on
    delay(3000);                     //Wait 3 seconds
    digitalWrite(pumpkinPin, LOW);  //Turn LED off
    digitalWrite(ghostPin, LOW);     //Turn LED off
  }

}

