#include <Esplora.h>

String AsciiToMorse[33] = {\
"dot beep", \
"beep dot dot dot", \
"beep dot beep dot", \
"beep dot dot", \
"dot", \
"dot dot beep dot", \
"beep beep dot", \
"dot dot dot dot", \
"dot dot", \
"dot beep beep beep", \
"beep dot beep", \
"dot beep dot dot", \
"beep beep", \
"beep dot", \
"beep beep beep", "dot beep beep dot", "beep beep dot beep", "dot beep dot", "dot dot dot", "beep", "dot dot beep", "dot dot dot beep", "dot beep beep", "beep dot dot beep", "beep dot beep beep", "beep beep dot dot", "dot beep beep beep beep", "dot dot beep beep beep", "dot dot dot beep beep", "dot dot dot dot beep", "dot dot dot dot dot", "beep dot dot dot dot", "beep beep dot dot dot", "beep beep beep dot dot", "beep beep beep beep dot", "beep beep beep beep beep"};
char Alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
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
  Serial.begin(9600);
  String SrlRead = Serial.readString();
  String MorseReturn;
  String null;
  int Index;
  if (SrlRead != null) {
    for (char& c : SrlRead) {
      for (int i = 0; i < 26; i++)
      {
        if (c == Alphabet[i])
        {
          Index = i;
        }
      }
      MorseReturn = AsciiToMorse[Index];
      Serial.println(MorseReturn);
    }
  }
  if (SrlRead == "Dot") {
<<<<<<< HEAD
    dot();
=======
    bool active = false;
    if (active ==false){
    active = true;
//<<<<<<< HEAD
    Esplora.writeRGB(5,5,5); // pulse DOT led 
    delay(2000);
//=======
    Esplora.writeRGB(25,25,25); // pulse DOT led 
    delay(500);
//>>>>>>> 654429b6284ac727c1f9610c12118eec392b0311
    Esplora.writeRGB(0,0,0);
    delay(200);
    active = false; 
    }   
>>>>>>> d9362ac57d0c46c4bdc3805c6b0b1e5aa507ac99
  }
  else
  {
    Esplora.writeRGB(0, 0, 0);
  }

  if (SrlRead == "Dash") {
<<<<<<< HEAD

    dash();
=======
   bool active = false;
    if (active ==false){
    active = true;
    Esplora.writeRGB(255,255,255); // pulse DASH led 
    delay(6000);
    Esplora.writeRGB(0,0,0);
    delay(600);
    active = false; 
    }
>>>>>>> d9362ac57d0c46c4bdc3805c6b0b1e5aa507ac99
  }
  else
  {
    Esplora.writeRGB(0, 0, 0);
  }
  if (SrlRead == "Over")  {
    bool active = false;
<<<<<<< HEAD
    if (active == false) {
      active = true;
      Esplora.writeRGB(10, 0, 0); // pulse OVER led
      delay(200);
      Esplora.writeRGB(0, 0, 0);
      active = false;
=======
    if (active ==false){
    active = true;
    Esplora.writeRGB(10,0,0); // pulse OVER led 
    delay(2000);
    Esplora.writeRGB(0,0,0);
    active = false; 
>>>>>>> d9362ac57d0c46c4bdc3805c6b0b1e5aa507ac99
    }
  }
  else
  {
    Esplora.writeRGB(0, 0, 0);
  }
}
void dash() {
  bool active = false;
  if (active == false) {
    active = true;
    Esplora.writeRGB(255, 255, 255); // pulse DASH led
    delay(1000);
    Esplora.writeRGB(0, 0, 0);
    delay(600);
    active = false;
  }
<<<<<<< HEAD
}


void dot() {
  bool active = false;
  if (active == false) {
    active = true;
    Esplora.writeRGB(25, 25, 25); // pulse DOT led
    delay(500);
    Esplora.writeRGB(0, 0, 0);
    delay(200);
    active = false;
  }
}

=======
  if (SrlRead == "A") {
    Esplora.writeRGB(75,75,75);
    delay(2000);//light levels and delay for dot
    Esplora.writeRGB(0,0,0);
    delay(2000);//delay for between dots/beeps within letter
    Esplora.writeRGB(255,255,255);
    delay(6000);//light levels and delay for dash
    Esplora.writeRGB(0,0,0);
    delay(2000);//delay for between dots/beeps within letter
    Esplora.writeRGB(255,255,255);
    delay(6000);//light levels and delay for dash
    Esplora.writeRGB(0,0,0);
    delay(2 000);//delay for between letters 

    if (SrlRead == "N"||"n") {
    Esplora.writeRGB(255,255,255);
    delay(2000);//light levels and delay for dot
    Esplora.writeRGB(0,0,0);
    delay(2000);//delay for between dots/beeps within letter
    Esplora.writeRGB(75,75,75);
    delay(6000);//light levels and delay for dash
    Esplora.writeRGB(0,0,0);
    delay(2000);//delay for between letters 

    if (SrlRead == "O"||"o") {
    Esplora.writeRGB(255,255,255);
    delay(2000);//light levels and delay for dot
    Esplora.writeRGB(0,0,0);
    delay(2000);//delay for between dots/beeps within letter
    Esplora.writeRGB(255,255,255);
    delay(6000);//light levels and delay for dash
    Esplora.writeRGB(0,0,0);
    delay(6000);//delay for between letters 
  }
 }
>>>>>>> d9362ac57d0c46c4bdc3805c6b0b1e5aa507ac99

