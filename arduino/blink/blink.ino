
void setup() {

  pinMode(D3, INPUT_PULLUP); //Reset button on the board
  pinMode(LED_BUILTIN, OUTPUT); // D4
  pinMode(D5, OUTPUT); //USB 4
  pinMode(D6, OUTPUT); //USB 3
  pinMode(D7, OUTPUT); //USB 2
  pinMode(D8, OUTPUT); //USB 1

  digitalWrite(LED_BUILTIN, HIGH); //Turn off
  digitalWrite(D5, HIGH); //Turn off
  digitalWrite(D6, HIGH); //Turn off
  digitalWrite(D7, HIGH); //Turn off
  digitalWrite(D8, HIGH); //Turn off

}

// the loop function runs over and over again forever
void loop() {
  
  digitalWrite(LED_BUILTIN, LOW); // Set LED_BUILTIN to LOW to turn on
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH); // Set LED BUTILIN to HIGH to turn off
  digitalWrite(D5, LOW);
  delay(1000);
  digitalWrite(D5, HIGH);
  digitalWrite(D6, LOW);
  delay(1000);
  digitalWrite(D6, HIGH);
  digitalWrite(D7, LOW);
  delay(1000);
  digitalWrite(D7, HIGH);
  digitalWrite(D8, LOW);
  delay(1000);
  digitalWrite(D8, HIGH);
  delay(1000);
                                       
}
