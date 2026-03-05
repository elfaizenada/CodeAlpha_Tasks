#define TRIG_PIN 9
#define ECHO_PIN 10
#define LED_PIN 8

void setup() {
  Serial.begin(9600); // Pour suivi si besoin
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  long duration;
  float distance;

  // Envoi du signal ultrason
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Lecture de l'écho
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calcul distance en cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // LED si objet proche (<20cm)
  if(distance < 20) digitalWrite(LED_PIN, HIGH);
  else digitalWrite(LED_PIN, LOW);

  delay(500);
}