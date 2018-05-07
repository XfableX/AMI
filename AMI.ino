#include <Esplora.h>;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int btn1 = Esplora.readButton(1);
  int btn2 = Esplora.readButton(2);
  int btn3 = Esplora.readButton(3);
  int btn4 = Esplora.readButton(4);
  int value = readLightSensor();
  Serial.println(value);
  if (btn1 == LOW){
    Esplora.writeRGB(250,0,0);
  }
  else if (btn2 == LOW){
    Esplora.writeRGB(0,250,0);
    }
   else if (btn3 == LOW) {
    Esplora.writeRGB(0,0,255);
   }
   else if (btn4 == LOW) {
    Esplora.writeRGB(255,255,255);
    
   }
}
