// Pin connected to the button
#define BUTTON_PIN D5

// Pin connected to the LED
#define LED_PIN D6

// Variable to store the button state
int buttonState = HIGH;

// Variable to store the previous button state
int lastButtonState = HIGH;

// Variable to store the LED state
bool ledState = LOW;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin BUTTON_PIN as an input with pull-up resistor
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  // initialize digital pin LED_PIN as an output
  pinMode(LED_PIN, OUTPUT);;
}


void loop() {
  buttonState = digitalRead(BUTTON_PIN);

  // check if the button state has changed
  if (buttonState != lastButtonState) {
    // if it has, toggle the LED state
    if (buttonState == LOW) {
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
    }
  }

  lastButtonState = buttonState;
}
/*
// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, LOW);  // turn the LED on (HIGH is the voltage level)

  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(12, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
}
*/
