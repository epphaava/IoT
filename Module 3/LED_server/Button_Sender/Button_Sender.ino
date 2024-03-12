#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>

#ifndef STASSID
#define STASSID "iotempire-KEP"
#define STAPSK "iotempireKEP"
// Pin connected to the LED
#define LED_PIN D6

#endif
// Pin connected to the button
#define BUTTON_PIN D2

// Pin connected to the LED
#define LED_PIN D6

// Variable to store the button state
int buttonState = HIGH;

// Variable to store the previous button state
int lastButtonState = HIGH;

const char* ssid = STASSID;
const char* password = STAPSK;

const int led = LED_BUILTIN;

// Variable to store the LED state
bool ledState = LOW;



void setup(void) {

  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

}
  
void loop(void) {
  buttonState = digitalRead(BUTTON_PIN);

  // check if the button state has changed
  if (buttonState != lastButtonState) {
    // if it has, toggle the LED state
    if (buttonState == LOW) {
      HTTPClient http;
      WiFiClient client;
      Serial.print("[HTTP] begin...\n");
      String address = "http://10.42.0.247:80/toggle";
      Serial.println(address);

    if (http.begin(client, address)) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();
      Serial.printf("code: %d\n",  httpCode);

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();
       } else {
      Serial.println("[HTTP] Unable to connect");
    }
    }
  }

  lastButtonState = buttonState;

}
