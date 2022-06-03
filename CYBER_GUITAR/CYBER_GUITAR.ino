#include <Wire.h>
#include "Adafruit_MPR121.h"
#include <Arduino.h>
#include <BLEMidi.h>

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

#define SDA_1 21
#define SCL_1 22

#define SDA_2 33
#define SCL_2 32

//def esp32 touch pins
#define TCH_0 4   //touch0
#define TCH_1 27  //touch7
#define TCH_2 15  //touch3
#define TCH_3 13  //touch4
#define TCH_4 12  //touch5
#define TCH_5 14  //touch6

TwoWire I2Cone = TwoWire(0);
TwoWire I2Ctwo = TwoWire(1);

Adafruit_MPR121 cap[6] = {Adafruit_MPR121(),Adafruit_MPR121(),Adafruit_MPR121(),Adafruit_MPR121(),Adafruit_MPR121(),Adafruit_MPR121()};

uint16_t lasttouched[6] = {0,0,0,0,0,0};
uint16_t currtouched[6] = {0,0,0,0,0,0};

void setup() {
  Serial.begin(115200);
  Serial.println("TEST"); 

  I2Cone.begin(SDA_1, SCL_1, 100000); 
  I2Ctwo.begin(SDA_2, SCL_2, 100000);
  
  cap[0].begin(0x5A, &I2Cone);
  cap[1].begin(0x5B, &I2Cone);
  cap[2].begin(0x5C, &I2Cone);
  cap[3].begin(0x5A, &I2Ctwo);
  cap[4].begin(0x5B, &I2Ctwo);
  cap[5].begin(0x5C, &I2Ctwo);

  Serial.println("Initializing bluetooth");
  BLEMidiServer.begin("CYBERGUITAR_0.1");
  Serial.println("Waiting for connections...");
  
}
  
void loop() {
  if(BLEMidiServer.isConnected()) {
    touches();
     BLEMidiServer.noteOn(0, 69, 127);
     BLEMidiServer.noteOff(0, 69, 127);
  }
    


 /*
 Serial.println("------mprs------"); 
 Serial.println(cap[0].touched()); 
 Serial.println(cap[1].touched());
 Serial.println(cap[2].touched()); 
 Serial.println(cap[3].touched());
 Serial.println(cap[4].touched()); 
 Serial.println(cap[5].touched());
 Serial.println("----------esps---------");
 Serial.println(touchRead(4));//touch 0, gpio 4
 Serial.println(touchRead(27));//touch 7, gpio 27
 Serial.println(touchRead(15));//touch 3, gpio 15
 Serial.println(touchRead(13));//touch 4, gpio 13
 Serial.println(touchRead(12));//touch 5, gpio 12
 Serial.println(touchRead(14));//touch 6, gpio 14
 Serial.println("-------------------");
 delay(500);*/
}
