const int PIN_TILT_BALL_SWITCH = 2;

void setup() {
  pinMode(PIN_TILT_BALL_SWITCH, INPUT);
  pinMode(LED_BUILTIN, OUTPUT)
}

void loop() {
  if (digitalRead(PIN_TILT_BALL_SWITCH) == HIGH) {
    // if rotated - turn on led
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    // if still vertical position - turn off led
    digitalWrite(LED_BUILTIN, LOW);
  }
}
