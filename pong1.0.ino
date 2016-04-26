#include <Charliplexing.h>
#include <Figure.h>
#include <Font.h>
int buzzPin = 41;
int tempx=random(0,13);
    int tempy=random(0,8);
int numlights=3;
  int timedelay(150);
  int xcounterpos=1;
  int xcounterneg=0;//initialise all variables
  int ycounterpos=1;
  int ycounterneg=0;
void setup(){
  

  pinMode(buzzPin, OUTPUT);
   LedSign::Init(); //initializes screen
  LedSign::Clear();

  //x is rows ie going along with the ciseco writing
  //rows and columns start off at 0!!
}
void loop(){
  int x[numlights];
int y[numlights];
  x[0]=1;
  x[1]=3;
  x[2]=5;
  
  for(int i=0;i<numlights;i++){
     
  x[i]=xmovement(x[i]);
  y[i]=ymovement(y[i],i);
  LedSign::Set(x[i],y[i],7);
  
  }
  delay(timedelay);//xcounterpos of one ball is effecting the o
  LedSign::Clear();
}

/*void ball(){
   x=xmovement(x);
  y=ymovement(y);
  LedSign::Set(x,y,7);
   delay(timedelay);//xcounterpos of one ball is effecting the o
  LedSign::Clear();
  //delay(timedelay);//calculates new position of each coordiinate and lights up new light
  //then after a delay turns off the light before turning on the next one
}*/

int ymovement(int movey,int i ){
  int j=i;
  int posit=movey;
  int ycounterneg[numlights];
  int ycounterpos[numlights];
  if(posit==0){
   buzz();
   posit++;
   //if it bounces off the left wall it sends it back right and adjusts counters
   ycounterpos=1;// counters are used here to see which wall the ball last hit
   ycounterneg=0;
   
 }
 else if(posit==8 ){
   buzz();
   posit--;
   //ball has hit off left wall and goes back
    ycounterpos=0;
   ycounterneg=1;
  
 }
  else if(ycounterpos==1){// checks which wall was last hit and decieds which way to send it
  
   posit++;
   
}

else if(ycounterneg==1){
   
   posit--;
   
}
return posit;// returns y position
  }
  
  
  
  
int xmovement(int movem){//does the same as the y movement except for the x direction
  int posit=movem;
  
  if(posit==0){
   
   posit++;
  buzz();
   xcounterpos=1;
   xcounterneg=0;
 }
 else if(posit==13 ){
  
   posit--;
   buzz();
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

 void buzz(){
 digitalWrite(buzzPin, HIGH);
delay(20);
digitalWrite(buzzPin, LOW);
delay(20); 
}
