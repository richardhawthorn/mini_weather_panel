/*
 *  Weather screen
 *  Richard Hawthorn
 *  richardhawthorn.com
 *  2016-11-6 
 *  
 *  Connect to the Open Weather Map API and display current a daily weather conditions
 */

#include <ESP8266WiFi.h>
#include <Wire.h>
#include <TimeLib.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_LEDBackpack seg7 = Adafruit_LEDBackpack();
Adafruit_8x16matrix matrix = Adafruit_8x16matrix();

#include <SPI.h>
#include <SD.h>

File configFile;

#include "variables.h"
#include "functions.h"


/*
 * Setup the system
 */
void setup() {
  
  Serial.begin(115200);

  setupScreens();
  loadConfigFromSD();
  connectToWifi();
  
}


/*
 * Main loop
 */
void loop() {

  getCurrentWeather();
  getUpcomingWeather();

  //wait until we make the request again
  delay(60000 * sleep_minutes);
}


