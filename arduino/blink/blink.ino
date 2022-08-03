
void setup() {

  pinMode(D3, INPUT_PULLUP); //Reset button on the board
  pinMode(LED_BUILTIN, OUTPUT); // D4
  pinMode(D5, OUTPUT); //USB 4
  pinMode(D6, OUTPUT); //USB 3
  pinMode(D7, OUTPUT); //USB 2
  pinMode(D8, OUTPUT); //USB 1

  // note: D5 (USB 4) turns off when state = HIGH
  digitalWrite(LED_BUILTIN, HIGH); //Turn off
  digitalWrite(D5, HIGH); //Turn off, this pin is backwards from the rest
  digitalWrite(D6, LOW); //Turn off
  digitalWrite(D7, LOW); //Turn off
  digitalWrite(D8, LOW); //Turn off

}

// the loop function runs over and over again forever
void loop() {

  // Turn on D4 (Built IN LED)
  digitalWrite(LED_BUILTIN, LOW); // Set LED_BUILTIN to LOW to turn on
  delay(1000);

  // Turn off Builtin LED
  // Turn on LED 1
  digitalWrite(LED_BUILTIN, HIGH); // Set LED BUTILIN to HIGH to turn off
  digitalWrite(D8, HIGH);
  delay(1000);

  // Turn off LED 1
  // Turn on LED 2
  digitalWrite(D8, LOW);
  digitalWrite(D7, HIGH);
  delay(1000);

  // Turn off LED 2
  // Turn on LED 3
  digitalWrite(D7, LOW);
  digitalWrite(D6, HIGH);
  delay(1000);

  // Turn off LED 3
  // Turn on LED 4
  digitalWrite(D6, LOW);
  digitalWrite(D5, LOW); //This pin is backwards from the rest
  delay(1000);

  // Turn off
  digitalWrite(D5, HIGH); //This pin is backwards from the rest
  delay(1000);
                                       
}
