/*
 * Function needed for the weather screen
 */

// *******************************************************
// *******************************************************

/*
 * Display a character onto the 7 segment screens
 */

void displayCharacter(int offset, int character, int number){

  offset = offset + 4 - character;
  
  if (number == 0){
    seg7.displaybuffer[0] |= 0x0001 << offset;
    seg7.displaybuffer[1] |= 0x0001 << offset;
    seg7.displaybuffer[2] |= 0x0001 << offset;
    seg7.displaybuffer[3] |= 0x0001 << offset;
    seg7.displaybuffer[4] |= 0x0001 << offset;
    seg7.displaybuffer[5] |= 0x0001 << offset;
  }

  if (number == 1){
    seg7.displaybuffer[1] |= 0x0001 << offset;
    seg7.displaybuffer[2] |= 0x0001 << offset;
  }

  if (number == 2){
    seg7.displaybuffer[0] |= 0x0001 << offset;
    seg7.displaybuffer[1] |= 0x0001 << offset;
    seg7.displaybuffer[3] |= 0x0001 << offset;
    seg7.displaybuffer[4] |= 0x0001 << offset;
    seg7.displaybuffer[6] |= 0x0001 << offset;
  }

  if (number == 3){
    seg7.displaybuffer[0] |= 0x0001 << offset;
    seg7.displaybuffer[1] |= 0x0001 << offset;
    seg7.displaybuffer[2] |= 0x0001 << offset;
    seg7.displaybuffer[3] |= 0x0001 << offset;
    seg7.displaybuffer[6] |= 0x0001 << offset;
  }

  if (number == 4){
    seg7.displaybuffer[1] |= 0x0001 << offset;
    seg7.displaybuffer[2] |= 0x0001 << offset;
    seg7.displaybuffer[5] |= 0x0001 << offset;
    seg7.displaybuffer[6] |= 0x0001 << offset;
  }

  if (number == 5){
    seg7.displaybuffer[0] |= 0x0001 << offset;
    seg7.displaybuffer[2] |= 0x0001 << offset;
    seg7.displaybuffer[3] |= 0x0001 << offset;
    seg7.displaybuffer[5] |= 0x0001 << offset;
    seg7.displaybuffer[6] |= 0x0001 << offset;
  }

  if (number == 6){
    seg7.displaybuffer[0] |= 0x0001 << offset;
    seg7.displaybuffer[2] |= 0x0001 << offset;
    seg7.displaybuffer[3] |= 0x0001 << offset;
    seg7.displaybuffer[4] |= 0x0001 << offset;
    seg7.displaybuffer[5] |= 0x0001 << offset;
    seg7.displaybuffer[6] |= 0x0001 << offset;
  }

  if (number == 7){
    seg7.displaybuffer[0] |= 0x0001 << offset;
    seg7.displaybuffer[1] |= 0x0001 << offset;
    seg7.displaybuffer[2] |= 0x0001 << offset;
  }

  if (number == 8){
    seg7.displaybuffer[0] |= 0x0001 << offset;
    seg7.displaybuffer[1] |= 0x0001 << offset;
    seg7.displaybuffer[2] |= 0x0001 << offset;
    seg7.displaybuffer[3] |= 0x0001 << offset;
    seg7.displaybuffer[4] |= 0x0001 << offset;
    seg7.displaybuffer[5] |= 0x0001 << offset;
    seg7.displaybuffer[6] |= 0x0001 << offset;
  }

  if (number == 9){
    seg7.displaybuffer[0] |= 0x0001 << offset;
    seg7.displaybuffer[1] |= 0x0001 << offset;
    seg7.displaybuffer[2] |= 0x0001 << offset;
    seg7.displaybuffer[3] |= 0x0001 << offset;
    seg7.displaybuffer[5] |= 0x0001 << offset;
    seg7.displaybuffer[6] |= 0x0001 << offset;
  }

}

/*
 * Display a number on the 7 segment screens
 */
void displayNumber(int screen, int number){

  int offset = (screen-1) * 4;

  displayCharacter(offset, 1, number%10);
  displayCharacter(offset, 2, (number%100)/10);
  displayCharacter(offset, 3, (number%1000)/100);
  displayCharacter(offset, 4, (number%10000)/1000);
    
}

/*
 * Display the temperature on the 7 segment screens
 */
void displayTemp(int screen, float val){

  int offset = (screen-1) * 4;
  int number = 0;
  int decimalChar = 0;
  int negative = false;

  if (val >= 100){
    number = (int) (val * 10);
    decimalChar = 0;
  } else if (val >= 10){
    number = (int) (val * 100);
    decimalChar = 2;
  } else if (val >= 0){
    number = (int) (val * 1000);
    decimalChar = 1;
  } else if (val >= -10){
    number = (int) (val * 1000);
    decimalChar = 2;
    negative = true;
    number = 0 - ( (int) (val * 100) );
  } else if (val >= -100){
    number = (int) (val * 100);
    decimalChar = 0;
    negative = true;
    number = 0 - ( (int) (val * 10) );
  } else {
    number = 0;
  }

  //display second and third numbers
  displayCharacter(offset, 2, (number%100)/10);
  displayCharacter(offset, 3, (number%1000)/100);

  //is this a negative number?
  if (negative == true){
    //display negative sign
    seg7.displaybuffer[6] |= 0x0001 << offset;
  } else {
    //display first number
    displayCharacter(offset, 4, (number%10000)/1000);
  }

  if (sd_units == "c"){
    seg7.displaybuffer[0] |= 0x0001 << offset + 3;
    seg7.displaybuffer[3] |= 0x0001 << offset + 3;
    seg7.displaybuffer[4] |= 0x0001 << offset + 3;
    seg7.displaybuffer[5] |= 0x0001 << offset + 3;
  } else {
    seg7.displaybuffer[0] |= 0x0001 << offset + 3;
    seg7.displaybuffer[4] |= 0x0001 << offset + 3;
    seg7.displaybuffer[5] |= 0x0001 << offset + 3;
    seg7.displaybuffer[6] |= 0x0001 << offset + 3;
  }

  //decimal place
  if (decimalChar > 0){
    seg7.displaybuffer[7] |= 0x0001 << offset + decimalChar - 1;
  }

  //degrees symbol
  seg7.displaybuffer[1] |= 0x0001 << screen + 11;

}

/*
 * Clear the screen buffers
 */
void clearScreenBuffer(){

  seg7.displaybuffer[0] = 0x0000;
  seg7.displaybuffer[1] = 0x0000;
  seg7.displaybuffer[2] = 0x0000;
  seg7.displaybuffer[3] = 0x0000;
  seg7.displaybuffer[4] = 0x0000;
  seg7.displaybuffer[5] = 0x0000;
  seg7.displaybuffer[6] = 0x0000;
  seg7.displaybuffer[7] = 0x0000;

  matrix.clear();      // clear display
  
}

/*
 * Plot a chart of rain over the next 24 hours
 */
void plotRain(){

  for (int i = 0; i < 8; i++){
      if (rainChart[i] > 0){
        matrix.drawLine(i + 8, 7, i + 8, 7 - rainChart[i] + 1, LED_ON);
      }
  }
  
}

/*
 * Write the data to the led screens
 */
void writeToScreen(){
  
  seg7.writeDisplay();
  matrix.writeDisplay(); 
  
}

/*
 * Load the settings from the SD card
 */
void loadConfigFromSD(){

  char character;
  int line = 1;
  
  if (!SD.begin(0)) {
    matrix.drawBitmap(0, 0, no, 8, 8, LED_ON);
    matrix.drawBitmap(8, 0, card, 8, 8, LED_ON);
    writeToScreen();
    return;
  }

  configFile = SD.open("config.txt");
  if (configFile){

    while (configFile.available()) {
      character = (char) configFile.read();

       //Serial.print((char) configFile.read());

      if (character == '\r'){
        line++;
      } else if (character == '\n'){
        //do nothing
      } else {
      
        if (line == 2){
          sd_ssid = sd_ssid + character;
        } else if (line == 4){
          sd_password = sd_password + character;
        } else if (line == 6){
          sd_apikey = sd_apikey + character;
        } else if (line == 8){
          sd_location = sd_location + character;
        } else if (line == 10){
          sd_units = sd_units + character;
        } else if (line == 12){
          sd_timezone = sd_timezone + character;
        }
      } 
    }
    // close the file:
    configFile.close();
    
  }

  /*
  Serial.println(sd_ssid);
  Serial.println(sd_password);
  Serial.println(sd_apikey);
  Serial.println(sd_location);
  Serial.println(sd_units);
  Serial.println(sd_timezone);
  */
  
}

/*
 * Setup the screens so we can write to them
 */
void setupScreens(){

  seg7.begin(0x70);  // pass in the address
  matrix.begin(0x71);  // pass in the address

  seg7.setBrightness(16);
  matrix.setBrightness(2);
  matrix.setRotation(1);

  clearScreenBuffer();
  writeToScreen();
  
}

/*
 * Connect to the wifi
 */
void connectToWifi(){

  char ssid[sd_ssid.length()+1]; 
  char password[sd_password.length()+1]; 

  sd_ssid.toCharArray(ssid, sd_ssid.length()+1);
  sd_password.toCharArray(password, sd_password.length()+1);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
}


/*
 * Connect to the api and extract the json
 */
boolean connectToApi(String url){

  boolean good_data = false;
  
  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (client.connect(host, httpPort)) {
    
    Serial.print("Requesting URL: ");
    Serial.println(url);
    
    // This will send the request to the server
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" + 
                 "User-Agent: runscope/0.1" + 
                 "Connection: close\r\n\r\n");
    delay(5000);
    
    // Read all the lines of the reply from server and print them to Serial
    while(client.available()){

      //if we already have the json string then ignore all future incoming data
      if (good_data){
        client.readStringUntil('\r');
      } else {

        json = client.readStringUntil('\r');
      
        //find the line containing json
        if (json.substring(1, 2) == "{"){
  
          //look for a string we know will be in there
          if (json.indexOf("temp") != -1){
            good_data = true;
          }
          
          //Serial.println(json);
         
        }
      }
      
    }

    if (good_data){
      return true;
    } else {
      return false;
    }

  } else {
    Serial.println("connection failed");
    return false;
  }
  
}

/*
 * Return the value of a specific key of the json
 */
String getValue(String key, boolean next){
  
  int posStart = 0;
  int posEnd = 0;
  int keyLen = 0;
  String result;

  key = '"'+key+'"';

  keyLen = key.length();

  if (next != true){
    lastkey = 0;
  }
  
  posStart = json.indexOf(key, lastkey);
  posStart = posStart + keyLen + 1;  
  posEnd = json.indexOf(",", posStart);
  result = json.substring(posStart, posEnd);

  lastkey = posEnd;

  return result;
  
}

/*
 * Display the relevant weather icon on the 8x8 matrix
 */
void displayIcon(int icon){

  if (icon == 1){
    matrix.drawBitmap(0, 0, sun, 8, 8, LED_ON);
  } else if (icon == 2){
    matrix.drawBitmap(0, 0, cloud_sun, 8, 8, LED_ON);
  } else if (icon == 3){
    matrix.drawBitmap(0, 0, cloud, 8, 8, LED_ON);
  } else if (icon == 4){
    matrix.drawBitmap(0, 0, cloud, 8, 8, LED_ON);
  } else if (icon == 9){
    matrix.drawBitmap(0, 0, cloud_rain, 8, 8, LED_ON);
  } else if (icon == 10){
    matrix.drawBitmap(0, 0, cloud_rain, 8, 8, LED_ON);
  } else if (icon == 11){
    matrix.drawBitmap(0, 0, lightning, 8, 8, LED_ON);
  } else if (icon == 13){
    matrix.drawBitmap(0, 0, snow, 8, 8, LED_ON);
  } else {
    matrix.drawBitmap(0, 0, mist, 8, 8, LED_ON);
  }

  writeToScreen();
      
}

/*
 * Update all the screens
 */
void updateScreens(){

  clearScreenBuffer();
  
  displayTemp(1, current_temp);
  displayTemp(3, todays_temp);
  displayIcon(weather_icon);
  plotRain();

  writeToScreen();
  
}

/*
 * Convert Tmeperature from kelvin to either c or f
 */
float convertTemp(float temp){

  if (sd_units == "c"){
    temp = temp - 273.15;
  } else {
    temp = (1.8 * (temp - 273)) + 32;
  }

  return temp;
  
}

/*
 * Extract the current temperature from the json string
 */
void processCurrentTemp(){

  String result = getValue("temp", false);

  float temp = result.toFloat();

  todays_temp = convertTemp(temp);

  updateScreens();
  
}



/*
 * Process the date into Y-m-d, taking into account the timezone
 */
String processDate(int date){

  String dateString = "";
  
  setTime(date + (sd_timezone.toInt() * 60 * 60));
  dateString = year() + '-' + month() + '-' + day();
  return dateString;
  
}

/*
 * Find the maximum temperature from the forcast for today
 */
void processTodaysTemp(){

  lastkey = 0;

  String result = "";
  float temp = 0;
  float maxTemp = 0;

  String todays_date = "";
  String date = "";

  for (int i = 0; i < 8; i++){
    result = getValue("temp", true);
    temp = result.toFloat();
    temp = convertTemp(temp);

    date = getValue("dt", true);
    date = processDate(date.toInt());

    if (todays_date == ""){  
      todays_date = date;
    }

    //if this is still today, then keep processing - we don't want tomorrows temp shown
    if (date == todays_date){

      Serial.println(result);
  
      if (temp > maxTemp){
        maxTemp = temp;
      }
      
    }
  }

  current_temp = maxTemp;

  updateScreens();
  
}

/*
 * Find the maximum weather icon from the forcast for today
 */
void processTodaysIcon(){

  lastkey = 0;

  String result = "";
  int icon = 0;
  int maxIcon = 0;

  String todays_date = "";
  String date = "";

  for (int i = 0; i < 8; i++){
    result = getValue("icon", true);
    result = result.substring(1, 3);
    icon = result.toInt();

    date = getValue("dt", true);
    date = processDate(date.toInt());

    if (todays_date == ""){  
      todays_date = date;
    }

    //if this is still today, then keep processing - we dont want tomorrows temp shown
    if (date == todays_date){

      Serial.println(icon);
      
      if (icon > maxIcon){
        maxIcon = icon;
      }
      
    }
  }

  weather_icon = maxIcon;
  updateScreens();
  
}

/*
 * Extract the rain levels from the next 24 hours of weather data
 */
void process24hRain(){

  lastkey = 0;

  String result = "";
  float rain = 0;
  int thisRain = 0;

  for (int i = 0; i < 8; i++){
    result = getValue("rain", true);
    result = result.substring(7);
    rain = result.toFloat();

    thisRain = (int) ceil(rain);
    if (thisRain > 7){
      thisRain = 7;
    }
    
    rainChart[i] = thisRain;
    
  }

  updateScreens();
  
}

/*
 * Get the current weather from the api
 */
void getCurrentWeather(){

  String url = "/data/2.5/weather";
  url += "?q=";
  url += sd_location;
  url += "&appid=";
  url += sd_apikey;

  if (connectToApi(url)){

    processCurrentTemp();
    
  }
  
}

/*
 * Get the weather forcast from the api
 */
void getUpcomingWeather(){

  String url = "/data/2.5/forecast";
  url += "?q=";
  url += sd_location;
  url += "&appid=";
  url += sd_apikey;

  if (connectToApi(url)){

    processTodaysTemp();
    processTodaysIcon();
    process24hRain();
    
  }
  
}

// *******************************************************
// *******************************************************
