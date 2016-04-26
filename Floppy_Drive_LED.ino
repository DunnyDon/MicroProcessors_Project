
#include <Charliplexing.h>
#include <Figure.h>
#include <Font.h>
int motorpin=30;
int directiono=31;
//turns on all lights
void setup(){
  pinMode(directiono,OUTPUT);
 pinMode(motorpin,OUTPUT);
 pinMode(13,OUTPUT);
   LedSign::Init(); //initializes screen
  LedSign::Clear();
  //x is rows ie going along with the ciseco writing
  //rows and columns start off at 0!!
}
void loop(){
  int numlights=20;//decides how many lights you want turned on
  int xarray[numlights];
  int yarray[numlights];
  int counter=0;
  while(counter<=numlights){//keeps going through the loop until all 20 are turned on
      int x=random(0, 13);//13 columns so set 13 as max 
      int y=random(0, 9);//9 rows
      LedSign::Set(x,y,7);// this is a function to turn on the leds (column,row,brightness)
      delay(500);
      xarray[counter]=x;
      yarray[counter]=y;
      counter++;
      for(int j=0;j<counter;j++){
        //this loop will play the music
        //this is just using the buzzer as a debugger and testing the output
          //if(xarray[counter]<10){
          digitalWrite(motorpin,LOW);
          digitalWrite(directiono,HIGH);
          digitalWrite(13,HIGH);
          delay(150);
          digitalWrite(motorpin,HIGH);
          delay((xarray[j]+1)*(yarray[j]+1));
       
          digitalWrite(motorpin,LOW);
          digitalWrite(directiono,LOW);
          digitalWrite(13,LOW);
          delay(150);
          digitalWrite(motorpin,HIGH);
          delay((yarray[j]+1)*(xarray[j]+1));
         // }
      }  
  }
  LedSign::Clear();
}
