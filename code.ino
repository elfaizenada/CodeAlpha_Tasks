int sensorPin = A0;
int ledPin = 8;

float temperature;
int sensorValue;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  sensorValue = analogRead(sensorPin);

  // Conversion TMP36
  temperature = (sensorValue * (5.0 / 1023.0) - 0.5) * 100;

  Serial.print("Temperature = ");
  Serial.println(temperature);

  // Clignotement si température > 30°C
  if(temperature > 30) {

    digitalWrite(ledPin, HIGH);
    delay(300);

    digitalWrite(ledPin, LOW);
    delay(300);

  } else {
    digitalWrite(ledPin, LOW);
  }
}