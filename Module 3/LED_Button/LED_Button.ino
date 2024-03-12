// Pin connected to the button
#define BUTTON_PIN D2



// Variable to store the button state
int buttonState = HIGH;

// Variable to store the previous button state
int lastButtonState = HIGH;


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
