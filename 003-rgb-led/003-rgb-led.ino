#define pin_red 6
#define pin_green 5
#define pin_blue 3

#define delay_time 10

int red = 255;
int green = 0;
int blue = 0;

void writeColors() {
  analogWrite(pin_red, red);
  analogWrite(pin_green, green);
  analogWrite(pin_blue, blue);
}

void setup() {
  pinMode(pin_red, OUTPUT);
  pinMode(pin_green, OUTPUT);
  pinMode(pin_blue, OUTPUT);

  Serial.begin(9600);
  while (!Serial)
    ;  // Wait untilSerial is ready - Leonardo

  writeColors();
}

void loop() {
  for (int i=0; i < 255; i++) {
    red -=1;
    green += 1;

    writeColors();
    delay(delay_time);
  }

  for (int i=0; i < 255; i++) {
    green -=1;
    blue += 1;

    writeColors();
    delay(delay_time);
  }

  for (int i=0; i < 255; i++) {
    blue -=1;
    red += 1;

    writeColors();
    delay(delay_time);
  }

}