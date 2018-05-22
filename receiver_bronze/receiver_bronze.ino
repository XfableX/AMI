#include <Esplora.h>

//MODIFY THE VALUES BELOW FOR BRONZE!!!
#define LOW_MIN 100
#define LOW_MAX 299

#define MID_MIN 300
#define MID_MAX 599

#define HIGH_MIN 600
#define HIGH_MAX 1000
String RecievedString;

//receiver module for "Morse"
//Expected transmission to follow this algorithm:
//Wait 10 seconds
//Transmit a single signal for 5 seconds (counting "0, 1, 2, 3, 4, 5") then no signal is transmitted in the next 2 seconds, this delay might be longer if necessary.
//Repeat until finish
//Constants are calibrated to current transmitter's light brightness
//To avoid ambient interference, hold both Arduino boards face down (creating a shadow), with the LED right next to the light sensor, facing at a 90-degree angle.

//Extension possibility: implement a Morse runtime parser with the letter is determined when "OVER" is received. Follow the "Morse tree".
//This parser can be accomplished simply with a global variable to remember the last "node" that has been reached in the Morse tree.
//Every time a single signal is received, some logic will determine the next node and save it. When "OVER" is received, the last node is the letter!
void setup()
{
  Serial.begin(9600);
} 

int state = 0; //0: standby, 1: reading
int seconds = 0;
int previousReading = 0; //intensity reading from light sensor
int maxReading = 0; //intensity reading from light sensor
int signalTimer = 0; //a variable to keep track of how long the signal has been transmitted 

 
void loop() //Forever looping, receiving, decoding
{
  int currentReading = Esplora.readLightSensor();
  
  //clock ticking every one second
  delay(1000);
  seconds = seconds + 1;

  Serial.println(currentReading);
  //Serial.println(seconds);

  if (seconds < 10)
  {
    Serial.println("GETTING READY...PLEASE WAIT 10 SECONDS");
  }
  else if (seconds == 10)
  {
    Serial.println("STATE: STANDBY");
  }
  
  if (currentReading > previousReading + 10 && seconds > 10) //There is a big jump in reading, indicating the start of the reading state
  {
    state = 1;
    maxReading = currentReading;
    signalTimer = seconds;
    Serial.println("STATE: READING");
  }
  else if (currentReading < previousReading - 100 && seconds > 10) //There is a big drop in reading, indicating the start of the standby state
  {
    state = 0;
    signalTimer = seconds;
    Serial.println("STATE: STANDBY");
  }
  
  //Serial.println("CURRENT STATE" + state == 0 ? "STANDBY" : "READING");
  
  if (currentReading > maxReading)
  {
    maxReading = currentReading;
  }
  
  previousReading = currentReading;

  if (state == 1 && maxReading > LOW_MIN && maxReading < LOW_MAX /*&& seconds == signalTimer + 4*/) //4 is to compensate for the one second it takes to switch state
  {
    over();
    Serial.println("OVER");
    signalTimer = seconds; //reset signalTimer for another 5 seconds
  }
  else if (state == 1 && maxReading > MID_MIN && maxReading < MID_MAX /*&& seconds == signalTimer + 4*/)
  {
    dot();
    Serial.println("DOT");
    signalTimer = seconds; //reset signalTimer for another 5 seconds
  }
  else if (state == 1 && maxReading > HIGH_MIN && maxReading < HIGH_MAX /*&& seconds == signalTimer + 4*/)
  {
    dash();
    Serial.println("DASH");
    signalTimer = seconds; //reset signalTimer for another 5 seconds
  }
  else if (state == 0)
  {
    signalTimer = seconds;
  }
  Serial.println(RecievedString);
}
void dash(){
  RecievedString=RecievedString+"dash ";
}
void dot(){
  RecievedString=RecievedString+"dot ";
}
void over(){
  RecievedString=RecievedString+"over";
}


