#include <Esplora.h>
char *ptr = NULL;
char *strings[10];
char* AsciiToMorse[36] = {\
                          "dot:beep", \
                          "beep:dot:dot:dot", \
                          "beep:dot:beep:dot", \
                          "beep:dot:dot", \
                          "dot", \
                          "dot:dot:beep:dot", \
                          "beep:beep:dot", \
                          "dot:dot:dot:dot", \
                          "dot dot", \
                          "dot beep beep beep", \
                          "beep dot beep", \
                          "dot beep dot dot", \
                          "beep beep", \
                          "beep dot", \
                          "beep beep beep", "dot beep beep dot", "beep beep dot beep", "dot beep dot", "dot dot dot", "beep", "dot dot beep", "dot dot dot beep", "dot beep beep", "beep dot dot beep", "beep dot beep beep", "beep beep dot dot", "dot beep beep beep beep", "dot dot beep beep beep", "dot dot dot beep beep", "dot dot dot dot beep", "dot dot dot dot dot", "beep dot dot dot dot", "beep beep dot dot dot", "beep beep beep dot dot", "beep beep beep beep dot", "beep beep beep beep beep"
                         };
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
      //  char array[] = MorseReturn;
      byte indexM = 0;
      ptr = strtok(AsciiToMorse[Index], ": ;");
      while(ptr != NULL)
      {
        strings[indexM] = ptr;
        indexM++;
        ptr = strtok(NULL, ": ;");  // takes a list of delimiters
      }
      // int WordSplitIndex=0;
      for (String c : strings) {
        if (c == "dot") {
         // Serial.println("dot");
          dot();
        }
        else if (c == "beep") {
          dash();
          //Serial.println("beep");
        }
        else if (c == "over"){
          over();
        }
        //      WordSplitIndex++;
      }
      //Serial.println (MorseReturn);
    }
  }
  if (SrlRead == "dot") {

    dot();

    bool active = false;
    if (active == false) {
      active = true;
      //<<<<<<< HEAD
      Esplora.writeRGB(5, 5, 5); // pulse DOT led
      delay(2000);
      //=======
      Esplora.writeRGB(25, 25, 25); // pulse DOT led
      delay(500);
      //>>>>>>> 654429b6284ac727c1f9610c12118eec392b0311
      Esplora.writeRGB(0, 0, 0);
      delay(200);
      active = false;
    }
  }
  else
  {
    Esplora.writeRGB(0, 0, 0);
  }
  if (Esplora.readButton(1) == LOW) {
    dot();
    dot();
    dot();
    dot();
    delay(500);
    dot();
    dot();
  }
  if (SrlRead == "beep") {


    dash();
    bool active = false;
    if (active == false) {
      active = true;
      Esplora.writeRGB(255, 255, 255); // pulse DASH led
      delay(6000);
      Esplora.writeRGB(0, 0, 0);
      delay(600);
      active = false;
    }

  }
  else
  {
    Esplora.writeRGB(0, 0, 0);
  }
  if (SrlRead == "Over")  {
    bool active = false;

    if (active == false) {
      active = true;
      Esplora.writeRGB(10, 0, 0); // pulse OVER led
      delay(200);
      Esplora.writeRGB(0, 0, 0);
      active = false;

      if (active == false) {
        active = true;
        Esplora.writeRGB(10, 0, 0); // pulse OVER led
        delay(2000);
        Esplora.writeRGB(0, 0, 0);
        active = false;

      }
    }
    else
    {
      Esplora.writeRGB(0, 0, 0);
    }
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
void over(){
    bool active = false;
  if (active == false) {
    active = true;
    Esplora.writeRGB(5,5,5); // pulse DOT led
    delay(500);
    Esplora.writeRGB(0, 0, 0);
    delay(200);
    active = false;
  }
}


