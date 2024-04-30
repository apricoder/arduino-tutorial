#define led_pin 7
#define button_on_pin 4
#define button_off_pin 5

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(button_on_pin, INPUT_PULLUP);
  pinMode(button_off_pin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(button_on_pin) == LOW) {
    digitalWrite(led_pin, HIGH);  // if button on is pressed - led on
  } else if (digitalRead(button_off_pin) == LOW) {
    digitalWrite(led_pin, LOW);  // if button off is pressed - led off
  }
}
