#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>

#ifndef STASSID
#define STASSID "iotempire-KEP"
#define STAPSK "iotempireKEP"

#endif
// Pin connected to the button
#define BUTTON_PIN D2



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
  Serial.println("started");

}
  
void loop(void) {
  buttonState = digitalRead(BUTTON_PIN);

  // check if the button state has changed
  if (buttonState != lastButtonState) {
    // if it has, toggle the LED state
    if (buttonState == LOW) {
      ledState = !ledState;
      digitalWrite(led, ledState);
    }
  }

  lastButtonState = buttonState;

}
