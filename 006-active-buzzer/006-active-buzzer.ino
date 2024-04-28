#define pin_buzzer 12

void setup() {
  pinMode(pin_buzzer, OUTPUT);
}

void loop() {
  digitalWrite(pin_buzzer, HIGH);
  delay(3000);

  digitalWrite(pin_buzzer, LOW);
  delay(3000);
}
