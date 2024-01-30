const int buzzerPin = 2;
const int potentiometerPIN = 0;
const int buttonPin = 3;
const int ledPin = 4;

int buttonState = 0;  // variable for reading the pushbutton status
int value = 0;

void setup(){ 
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  value = analogRead(potentiometerPIN);
  tone(buzzerPin, value, 500);
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  Serial.print(value);
  Serial.print(" ");
  Serial.print(buttonState);
  delay(100);
}
