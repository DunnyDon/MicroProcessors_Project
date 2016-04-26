#include <Charliplexing.h>
#include <Figure.h>
#include <Font.h>
 
int motorpin=30;
int directiono=31;
 
int y=random(0,8);//ensures the first light turned on is actually on the shield
  int x=random(0,13);
  int timedelay=20;
  int xcounterpos=1;
  int xcounterneg=0;//initialise all variables
  int ycounterpos=1;
  int ycounterneg=0;
void setup(){
   pinMode(directiono,OUTPUT);
 pinMode(motorpin,OUTPUT);
 
   LedSign::Init(); //initializes screen
  LedSign::Clear();
  //x is rows ie going along with the ciseco writing
  //rows and columns start off at 0!!
}
void loop(){
 
  smile();
  numberone();
  numberseven();
 for(int i=0;i<1500;i+=20){
   forward(20000);
 }
 //moves the motor forward and back
 for(int i=0;i<1300;i+=20){//different threshild here due to the
   back(20000);   //fact that we didn't wat the motor against the back wall
   
 }
 while (true){// this ensures the group number is only printed once
  ball();
 }
 
}
 
void ball(){
   x=xmovement(x);
   y=ymovement(y);
   LedSign::Set(x,y,7);
   delay(timedelay);//xcounterpos of one ball is effecting the o
 
  //delay(timedelay);//calculates new position of each coordiinate and lights up new light
  //then after a delay turns off the light before turning on the next one
}
 
int ymovement(int movey){
      int posit=movey;
     
      if(posit==0){
       motordrive();
       posit++;
       //if it bounces off the left wall it sends it back right and adjusts counters
       ycounterpos=1;// counters are used here to see which wall the ball last hit
       ycounterneg=0;
     }
     else if(posit==8 ){
       motordrive();
       posit--;
       //ball has hit off left wall and goes back
        ycounterpos=0;
       ycounterneg=1;
     }
      else if(ycounterpos==1){// checks which vertical wall was last hit and decieds which way to send it
     
       posit++;
       LedSign::Clear();// turns off the light after moving
       //this solved one of the issues we encountered
       //it stopped the light 'disappearing' when the floppy drive
       //funxtion was callled and just left the light on until it moved away from the wall
    }
     
    else if(ycounterneg==1){
       
       posit--;
       LedSign::Clear();
    }
  return posit;// returns y position
  }
 
 
 
 
int xmovement(int movem){//does the same as the y movement except for the x direction
  int posit=movem;
 
    if(posit==0){
       posit++;
       motordrive();
       xcounterpos=1;
       xcounterneg=0;
   }
   else if(posit==13 ){
       posit--;
       motordrive();
       xcounterpos=0;
       xcounterneg=1;
   }
    else if(xcounterpos==1){
       posit++;
  }
   
  else if(xcounterneg==1){
       posit--;
  }
    return posit;
}
 
 
 
    void forward(int p){
  p-=1000;
  digitalWrite(motorpin,LOW);
  digitalWrite(directiono,LOW);
  //you must set the direction pin before the motor is turned on
 //delays were used because the motor could not handle the speed at which the direction changed
  delayMicroseconds(p);
  digitalWrite(motorpin,HIGH);
  delay(1);
  digitalWrite(motorpin,LOW);
   }
   
    void back(int p){
  p-=1000;
  digitalWrite(motorpin,LOW);
  digitalWrite(directiono,HIGH);//you must set the direction pin before the motor is turned on
  //delays were used because the motor could not handle the speed at which the direction changed
  delayMicroseconds(p);
  digitalWrite(motorpin,HIGH);
  delay(1);
  digitalWrite(motorpin,LOW);
  }
 
 
 
 void motordrive(){
          int p=pitch(x);
          //the pitch function calculates the delay needed to make the required tone.
          //250000 microseconds for 1/4sec, the buzz should sound for this long. 2p is the amount of time it take to go forward AND back.
          //So 250000/2p gives us the amount of cycles to run for to buzz for 1/4 of a sec. (rounded down to the nearest whole number, since it's an int)
      for(int i=0; i<250000/(2*p);i++){
          forward(p);
          back(p);
  }
 }
 
 int pitch(int x){
  float q=x-1;
  double pp = 1000000/220; //base note of 110Hz
  double temp = pp*(pow(2,q/12));    //with a q ranging from 0 to 12, we get a range of 110Hz to 55Hz
  int p = temp;
  return p;
 }
 
 void smile(){
   //turns on the lights for a smile one by one
   //looks better than all of them being turned on at once hence the delay
     LedSign::Set(9,5,7);
     delay(100);
     LedSign::Set(12,5,7);
     delay(100);
     LedSign::Set(9,3,7);
     delay(100);
     LedSign::Set(12,3,7);
     delay(100);
     LedSign::Set(11,2,7);
     delay(100);
     LedSign::Set(10,2,7);
     delay(100);
     
}
 
void numberone(){
     //turns on the lights for the number one, one by one
   
     LedSign::Set(6,6,7);
     delay(100);
     LedSign::Set(6,5,7);
     delay(100);
     LedSign::Set(6,4,7);
     delay(100);
     LedSign::Set(6,3,7);
     delay(100);
     LedSign::Set(6,2,7);
     delay(100);
     LedSign::Set(6,1,7);
     delay(100);
}
 
void numberseven(){
  //turns on the lights for the number one, one by one
     LedSign::Set(4,6,7);
     delay(100);
     LedSign::Set(3,6,7);
     delay(100);
     LedSign::Set(2,6,7);
     delay(100);
     LedSign::Set(2,5,7);
     delay(100);
     LedSign::Set(2,4,7);
     delay(100);
     LedSign::Set(2,3,7);
     delay(100);
     LedSign::Set(2,2,7);
     delay(100);
     LedSign::Set(2,1,7);
     delay(100);
     LedSign::Set(1,4,7);
     delay(100);
     LedSign::Set(3,4,7);
     delay(100);
}
