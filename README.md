### Description

Weather screen used to display current and upcoming weather conditions

- Current temperature
- Todays max temperature
- Todays weather icon (sun, cloud etc)
- Rainfall for the next 24 hours

#### Instructions

Config information is stored on the micro SD card, inserted into the back of the board.
Copy the example config.txt file (found in the code folder) onto a blank sd card, and add the relevant config information.

Sign up for a free api key at https://openweathermap.org/api and add that to the config file

This config file is used to set the following:

- Network details
- Open weather map API key
- Location (for weather reporting)
- Units
- Timezone

#### Arduino config

You will need to use the ESP8266 Arduino core to compile and upload this code
https://github.com/esp8266/Arduino

These libraries are also required

- Time - http://www.pjrc.com/teensy/td_libs_Time.html
- Adafruit LED Backpack - https://github.com/adafruit/Adafruit_LED_Backpack
- Adafurit GFX - https://github.com/adafruit/Adafruit-GFX-Library

#### Hardware

- ESP8266 Wifi processor
- 2 x 7 segment LED screens
- 2 x 8x8 matrix LED screens 
- FTDI headers for programming
- Mini USB for power
