/*
 * Narsimlu Kemsaram 
 * Reference: https://randomnerdtutorials.com/guide-to-neo-6m-gps-module-with-arduino/
 */
 
#include <SoftwareSerial.h>

//Include the Mona_ESP library
#include <Wire.h>
#include "Mona_ESP_lib.h"

// The serial connection to the GPS module
SoftwareSerial ss(breakout_26, breakout_25);

void setup(){
  //Initialize the MonaV2 robot
	Mona_ESP_init();
  Serial.begin(9600);
  ss.begin(9600);
}

void loop(){
  while (ss.available() > 0){
    // get the byte data from the GPS
    byte gpsData = ss.read();
    Serial.write(gpsData);
  }
}
