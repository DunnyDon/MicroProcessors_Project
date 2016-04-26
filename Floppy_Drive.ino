//Floppy Drive
int motorpin=30;
int directiono=31;
void setup(){
 pinMode(directiono,OUTPUT);
 pinMode(motorpin,OUTPUT);
 pinMode(13,OUTPUT);//LED used as a debugger 
}
void loop(){
  int x=random(10,20);
  int y=random(10,20);
  for(int i=0;i<=x;i++){
  digitalWrite(motorpin,LOW);
  digitalWrite(directiono,HIGH);
  digitalWrite(13,HIGH);
  delay(y);
  digitalWrite(motorpin,HIGH);
  delay(1);
  }
  //To change the sound you change the delay
   for(int j=0;j<=y;j++){
  digitalWrite(motorpin,LOW);
  digitalWrite(directiono,LOW);
  digitalWrite(13,LOW);
  delay(x);
  digitalWrite(motorpin,HIGH);
  delay(1);
   }
}
    /* if(time+2<millis()){
            
          digitalWrite(motorpin,LOW);
          digitalWrite(directiono,LOW);
          
          delay(15);
          digitalWrite(motorpin,HIGH);
          delay((xarray[j]+1)*(yarray[j]+1)/20);
           times=millis()-time;
           }
        
        else if(times-3>millis())
         {
            time=millis();
          digitalWrite(motorpin,LOW);
          digitalWrite(directiono,HIGH);
          digitalWrite(13,LOW);
          delay(15);
          digitalWrite(motorpin,HIGH);
          delay((yarray[j]+1)*(xarray[j]+1)/50);
          
          
       
      }  */
