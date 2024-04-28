#define PIN_BUZZER 8
#define PIN_BUTTON 10

#define C_FREQ 261.63   // Frequency of C note
#define Cs_FREQ 277.18  // Frequency of C# or Db note
#define D_FREQ 293.66   // Frequency of D note
#define Ds_FREQ 311.13  // Frequency of D# or Eb note
#define E_FREQ 329.63   // Frequency of E note
#define F_FREQ 349.23   // Frequency of F note
#define Fs_FREQ 369.99  // Frequency of F# or Gb note
#define G_FREQ 392.00   // Frequency of G note
#define Gs_FREQ 415.30  // Frequency of G# or Ab note
#define A_FREQ 440.00   // Frequency of A note
#define As_FREQ 466.16  // Frequency of A# or Bb note
#define B_FREQ 493.88   // Frequency of B note

int full_note_duration = 2000;  // 4/4 note is 2sec
float speed = 1.5;              // to speed up / slow down entire melody. 1 is normal speed
float speed_multiplier = (1.0 / speed);

void setup() {
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_BUTTON, INPUT_PULLUP);

  Serial.begin(9600);
  while (!Serial)
    ;  // Wait until Serial is ready
  Serial.println("================================================");
  Serial.println("Serial initialized");
}

void loop() {
  if (digitalRead(PIN_BUTTON) == LOW) {  // if button pressed
    Serial.println("Button pressed");
    play_ode_to_joy();
  }
}

void play_ode_to_joy() {
  playTone(E_FREQ, .25);

  playTone(E_FREQ, .25);

  playTone(F_FREQ, .25);

  playTone(G_FREQ, .25);

  playTone(G_FREQ, .25);

  playTone(F_FREQ, .25);

  playTone(E_FREQ, .25);

  playTone(D_FREQ, .25);

  playTone(C_FREQ, .25);

  playTone(C_FREQ, .25);

  playTone(D_FREQ, .25);

  playTone(E_FREQ, .25);

  playTone(E_FREQ, .5);

  playTone(D_FREQ, .125);

  playTone(D_FREQ, .375);
}

void st_delay() {  // standard delay between notes
  delay(speed_multiplier * 100);
}

void playTone(float frequency, float note_duration) {
  int duration = speed_multiplier * full_note_duration * note_duration;
  int period = 1000000 / frequency;  // Calculate the period in microseconds
  int half_period = period / 2;      // Calculate half the period

  unsigned long duration_in_mcs = static_cast<unsigned long>(duration) * 1000;

  // Serial.println("------------------------------------------------");
  // Serial.println("speed_multiplier: " + String(speed_multiplier));
  // Serial.println("frequency: " + String(frequency));
  // Serial.println("duration: " + String(duration));
  // Serial.println("period: " + String(period));
  // Serial.println("half_period: " + String(half_period));
  // Serial.println("duration_in_mcs: " + String(duration_in_mcs));

  // int iterations = 0;
  for (unsigned long i = 0; i < duration_in_mcs; i += period) {
    digitalWrite(PIN_BUZZER, HIGH);  // Turn buzzer ON
    delayMicroseconds(half_period);  // Wait for half the period
    digitalWrite(PIN_BUZZER, LOW);   // Turn buzzer OFF
    delayMicroseconds(half_period);  // Wait for half the period

    // iterations++;
  }

  // Serial.println("iterations: " + String(iterations));

  st_delay();
}
