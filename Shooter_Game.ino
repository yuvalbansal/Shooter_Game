const int buzzerPin = 2;
const int potentiometerPIN = A0;
const int buttonPin = 5;
const int ledPin = 4;
const int debounceDelay = 50;  // Adjust this value based on your button behavior

int buttonState = LOW;
int lastButtonState = LOW;
int lastDebounceTime = 0;
int value = 0;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(potentiometerPIN);
  Serial.print("Potentiometer Value: ");
  Serial.print(value);
  tone(buzzerPin, value, 500);

  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      Serial.print("; Button State: ");
      Serial.print(buttonState);

      if (buttonState == HIGH) {
        digitalWrite(ledPin, HIGH);
      } else {
        digitalWrite(ledPin, LOW);
      }
    }
  }

  lastButtonState = reading;

  delay(1000);
}
