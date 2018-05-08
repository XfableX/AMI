#include <Esplora.h>;
bool AvgE=false;
int value;
int doAvg = 0;
int index = 0;
float TotalLight=0;
float averageLight = 0;
int secondsActv;
int wantedpos;
String AsciiToMorse[37]={
  "dot beep","beep dot dot dot","beep dot beep dot","beep dot dot" };

void setup() {
  //this starts the serial so that we can output to serial
  Serial.begin(9600);

}

void loop() {
  //defines the buttons so that we dont have to type Esplora.readButton everytime
  int btn1 = Esplora.readButton(1);
  int btn2 = Esplora.readButton(2);
  int btn3 = Esplora.readButton(3);
  int btn4 = Esplora.readButton(4);
  //sets value to be the esplora light sensor so that we can use it in detecting difference in light
  value = Esplora.readLightSensor();

  //Calculates the average light level of the room and outputs for use in calculating when it recieves light from LED
  if (doAvg < 1000){
    index ++;
    TotalLight=TotalLight+value;
    averageLight=TotalLight/index;
    doAvg++;
    //Serial.println(averageLight);
  }
  else if (doAvg == 1000){
    String strn = ("The average light level in this room is: ");
    Serial.println(strn);
    Serial.println(averageLight);
    AvgE=true;
    doAvg++;
  //  blah();
  }
  
  //button to recalculate the average (for when changing rooms)
  if (btn1 == LOW){
    index = 1;
    TotalLight=0;
    averageLight=0;
    doAvg = 0;
  }
  //pulses LED for Dot
  else if (btn2 == LOW){
    bool active = false;
    if (active ==false){
    active = true;
    Esplora.writeRGB(0,255,0);
    delay(100);
    Esplora.writeRGB(0,0,0);
    delay(200);
    active = false;
    }
    }
    //pulses LED for Beep
   else if (btn3 == LOW) {
    Esplora.writeRGB(0,255,0);
    delay(750);
    Esplora.writeRGB(0,0,0);
   }
   else if (btn4 == LOW) {
    Esplora.writeRGB(255,255,255);
   }//if light exceeds average by predtermined threshold and AvgE is true call blah
    if (value > averageLight+100&&AvgE==true){
      //lighttime = true;
      blah();
    }

}
bool lighttime = true;
int previousmillis;
void blah(){
  if (lighttime = true) 
  {
    previousmillis = millis();
    lighttime = false;
  }
  int mdivide1000;
   mdivide1000 = (millis()/1000);
   secondsActv = (mdivide1000 - previousmillis);
   Serial.println(value);
   Serial.println(secondsActv);
   if (secondsActv > 200)
   {
    printf("DASH");
   }
   else 
   {
    printf("DOT");
   }
}
int testInArray(String phrase){
   for (int i=0; i<AsciiToMorse; i++) {
   if (phrase = AsciiToMorse[i]) {
     wantedpos = i;
     return wantedpos;
   }
}
}

