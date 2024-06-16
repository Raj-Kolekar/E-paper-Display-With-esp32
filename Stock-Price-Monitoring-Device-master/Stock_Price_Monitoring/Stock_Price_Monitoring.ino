#include <GxEPD.h>

#include <GxGDEY027T91/GxGDEY027T91.h>    // 2.7" b/w

#include GxEPD_BitmapExamples

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>


#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>

//****************************** Create String Variables for your favourite Stock
String DATE;
String TIME;
String DAY;
String FIRST;
String SECOND;
String THIRD;
String FOURTH;
String FIFTH;
String SIXTH;


WiFiMulti WiFiMulti;

#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  120        /* Time ESP32 will go to sleep (in seconds) */

RTC_DATA_ATTR int bootCount = 0;



#if defined(ESP32)

GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16); // arbitrary selection of 17, 16
GxEPD_Class display(io, /*RST=*/ 16, /*BUSY=*/ 4); // arbitrary selection of (16), 4


#else

GxIO_Class io(SPI, /*CS=*/ SS, /*DC=*/ 8, /*RST=*/ 9); // arbitrary selection of 8, 9 selected for default of GxEPD_Class
GxEPD_Class display(io, /*RST=*/ 9, /*BUSY=*/ 7); // default selection of (9), 7

#endif


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");

  display.init(115200); // enable diagnostic output on Serial

  Serial.println("setup done");

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("raj's", "12345678");

  ++bootCount;
  Serial.println("Boot number: " + String(bootCount));

  /*
    First we configure the wake up source
    We set our ESP32 to wake up every 5 seconds
  */
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) +
                 " Seconds");

}

void loop()
{

  //DATE
  if ((WiFiMulti.run() == WL_CONNECTED))
  {

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    // configure traged server and url
    http.begin("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=CVPNLL97RXTA57BQ"); //HTTP

    Serial.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        DATE = http.getString();
        Serial.println(DATE);
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }

//TIME
  if ((WiFiMulti.run() == WL_CONNECTED))
  {

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    // configure traged server and url
    http.begin("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=SU3P1CO3SHRS316C"); //HTTP

    Serial.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        TIME = http.getString();
        Serial.println(TIME);
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
  //DAY
  if ((WiFiMulti.run() == WL_CONNECTED))
  {

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    // configure traged server and url
    http.begin("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=LPE4S24CP49TDJK8"); //HTTP

    Serial.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        DAY = http.getString();
        Serial.println(DAY);
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
//FIRST
  if ((WiFiMulti.run() == WL_CONNECTED))
  {

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    // configure traged server and url
    http.begin("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=NRD8R0RXR64SL2G5"); //HTTP

    Serial.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        FIRST = http.getString();
        Serial.println(FIRST);
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
//SECOND
  if ((WiFiMulti.run() == WL_CONNECTED))
  {

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    // configure traged server and url
    http.begin("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=CVPNLL97RXTA57BQ"); //HTTP

    Serial.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        SECOND = http.getString();
        Serial.println(SECOND);
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
  //THIRD
    if ((WiFiMulti.run() == WL_CONNECTED))
  {

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    // configure traged server and url
    http.begin("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=CVPNLL97RXTA57BQ"); //HTTP

    Serial.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        THIRD = http.getString();
        Serial.println(THIRD);
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
  //FOURTH
    if ((WiFiMulti.run() == WL_CONNECTED))
  {

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    // configure traged server and url
    http.begin("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=CVPNLL97RXTA57BQ"); //HTTP

    Serial.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        FOURTH = http.getString();
        Serial.println(FOURTH);
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
  //FIFTH
    if ((WiFiMulti.run() == WL_CONNECTED))
  {

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    // configure traged server and url
    http.begin("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=CVPNLL97RXTA57BQ"); //HTTP

    Serial.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        FIFTH = http.getString();
        Serial.println(FIFTH);
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }


  // Setting the characters of font to be displayed on the board.
  const char* name = "FreeMonoBold12pt7b";
  const GFXfont* f = &FreeMonoBold12pt7b;
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);


  //Printing all the data on the display
display.setCursor(80, 0);
display.println();
display.setCursor(80, 20);
display.println();
display.print(DATE);
display.setCursor(80, 30);
display.println();
display.setCursor(80, 70);
display.println();
display.print(TIME);
display.println();
 /*display.setCursor(80, 70);
 display.print(FIRST);
 display.println(); 
 display.setCursor(80, 100);
 display.print(SECOND);
 display.println();
 */
  // Uncomment below line for full update mode(This will consume more power)
  display.update();
  display.setRotation(2);
 
  display.updateWindow(0, 0, GxEPD_WIDTH, GxEPD_HEIGHT);
  delay(500);
  display.updateWindow(0, 0, GxEPD_WIDTH, GxEPD_HEIGHT);

  // It will go into deep Sleep for 60 sec.
  Serial.println("Going to sleep now");
  esp_deep_sleep_start();

}
