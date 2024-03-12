Team network infrastructure
  * We set the old laptop up as a gateway. The network SSID is iotempire-KEP.

Button to LED directly on microcontroller. PULLUP/PULLDOWN resistors.
  * Code in folder LED_Button.
  * Pull-up and pull-down resistors offer the same functionality and which one is used mostly doesn't matter. The difference lies in whether the voltage at the output (e.g. LED) is high or low while the circuit is not complete.
  * INPUT_PULLUP means that  the default value for the input is HIGH, unless it is pulled LOW by the action of pressing the button.

Computer to Microcontroller via Webrequest.
 * Computer to microcontroller onboard LED via Web request: code in folder LED_Server/LED_Server
 * Button to Webhook, Webhook to curl to Led in folders LED_Server/LED_Server and LED_Server/Button_Sender

Dashboard display with command "dashboard"
* URL hardcoded into alias, can be changed.
