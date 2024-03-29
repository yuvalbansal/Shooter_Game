const int buzzerPin = 2;
const int potentiometerPIN = 0;
const int buttonPin = 3;
const int ledPin = 4;

int buttonState = 0;
int value = 0;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  value = analogRead(potentiometerPIN);
  tone(buzzerPin, value, 500);
  buttonState = digitalRead(buttonPin);
  if (buttonState == 1)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  Serial.print(value);
  Serial.print(" ");
  Serial.println(buttonState);
  delay(10);
}
