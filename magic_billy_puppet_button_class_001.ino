class Button {
  private:
    const byte pin;
    const char* name;

    byte state;
    uint32_t debounceMs;
    static const uint32_t DEBOUNCE_ms = 50;

  public:
    Button(const char *name, const byte pin) : pin(pin), name(name) {}

    void setup() {
      pinMode(pin, INPUT_PULLUP);
      Serial.print("Button ");
      Serial.print(name);
      Serial.println(" set up.");

      state = digitalRead(pin);
      debounceMs = millis();
    }

    void loop() {
      if (millis() - debounceMs < DEBOUNCE_ms) return;
      byte prevState = state;
      state = digitalRead(pin);
      if (state != prevState) {
        debounceMs = millis();
      }

      if (state == HIGH && prevState == LOW) {
        Serial.print("Button ");
        Serial.print(name);
        Serial.println(" released.");
      }
      else if (state == LOW && prevState == HIGH) {
        Serial.print("Button ");
        Serial.print(name);
        //drive motor(pin) forward via motorcontroller code
        Serial.println(" pressed.");
      }
      else if (state == LOW && prevState == LOW) {
        Serial.print("Button ");
        Serial.print(name);
        //drive motor(pin) backward via motorcontroller code
        Serial.println(" held.");
      }


    }

};


Button button[] = {
  Button("Mouth", 2),
  Button("Head", 3),
  Button("Tail", 4)
};

const int BUTTONS = sizeof(button) / sizeof(*button);

void setup() {
  Serial.begin(9600);
  while (!Serial) ;

  Serial.print("beginning sketch in 5");
  for (int i = 4; i >= 0; i--) {
    delay(500);
    Serial.print(' ');
    Serial.print(i);
  }
  Serial.println(" GO!");

  for (int i = 0; i < BUTTONS; i++) button[i].setup();
}

void loop() {
  for (int i = 0; i < BUTTONS; i++) button[i].loop();
}
