#include <Esplora.h>
 
void setup() {
}

//Designed to work with transmitted.ino. This basic code simply allows lights of different intensity to
//be produced by the LED light, depending on which button is pressed. This is the basic "manual" mode
//of transmission. The next level up is to have this code "automatically" transmit a coded message
//following the algorithm dictated by the transmitted (read transmitter.ino).
//This "automatic" transmission can be as simple as copying and pasting "Esplora.writeRGB(SOMETHING)" 
//multiple time (i.e. there is no need to write an interator working through an input array.
void loop() {
  int btn1 = Esplora.readButton(1);
  int btn2 = Esplora.readButton(2);
  int btn3 = Esplora.readButton(3);
  int btn4 = Esplora.readButton(4);
  
  if (btn1 == LOW) {
    bool active = false;
    if (active ==false){
    active = true;
    Esplora.writeRGB(100,100,100); // pulse DOT led 
    delay(200);
    Esplora.writeRGB(0,0,0);
    delay(200);
    active = false; 
    }   
  }
  else
  {
    Esplora.writeRGB(0,0,0);
  }
  
  if (btn2 == LOW) {
   bool active = false;
    if (active ==false){
    active = true;
    Esplora.writeRGB(255,255,255); // pulse DASH led 
    delay(600);
    Esplora.writeRGB(0,0,0);
    delay(600);
    active = false; 
    }
  }
  else
  {
    Esplora.writeRGB(0,0,0);
  }
  if (btn3 == LOW)  {
    bool active = false;
    if (active ==false){
    active = true;
    Esplora.writeRGB(75,0,0); // pulse OVER led 
    delay(200);
    Esplora.writeRGB(0,0,0);
    active = false; 
    }
  }
  else 
  {
    Esplora.writeRGB(0,0,0);
  }
 }
