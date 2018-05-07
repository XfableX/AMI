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
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  
  int btn1 = Esplora.readButton(1);
  int btn2 = Esplora.readButton(2);
  int btn3 = Esplora.readButton(3);
  int btn4 = Esplora.readButton(4);
  
  value = Esplora.readLightSensor();
  
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
  
  
  if (btn1 == LOW){
    index = 1;
    TotalLight=0;
    averageLight=0;
    doAvg = 0;
  }
  
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
   else if (btn3 == LOW) {
    Esplora.writeRGB(0,255,0);
    delay(750);
    Esplora.writeRGB(0,0,0);
   }
   else if (btn4 == LOW) {
    Esplora.writeRGB(255,255,255);
    
   }
    if (value > averageLight+400&&AvgE==true){
      blah();
    }

}

void blah(){
   
   secondsActv = (millis()/1000);
   Serial.println(value);
   Serial.println(secondsActv);
}
int testInArray(String phrase){
   for (int i=0; i<AsciiToMorse; i++) {
   if (phrase = AsciiToMorse[i]) {
     wantedpos = i;
     return wantedpos;
   }
}
}


