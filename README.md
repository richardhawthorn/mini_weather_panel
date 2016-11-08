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

### License

This work is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License.

<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br />
Designed by <a xmlns:cc="http://creativecommons.org/ns#" href="http://www.richardhawthorn.com" property="cc:attributionName" rel="cc:attributionURL" target="_blank">Richard Hawthorn</a><br />
<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/" target="_blank">View License</a>