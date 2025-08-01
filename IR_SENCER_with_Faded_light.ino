const int irSensorPin = 2;
const int ledPin = 3;       // Must be a PWM pin
const int buzzerPin = 4;

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorState = digitalRead(irSensorPin);
  Serial.println(sensorState); // For debugging

  if (sensorState == LOW) { // Object detected
    // Smooth LED fade-in
    for (int brightness = 0; brightness <= 255; brightness += 5) {
      analogWrite(ledPin, brightness);
      delay(10);
    }

    //  Buzzer on for 500ms, then off
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
  } else {
    // 🔅 Smooth LED fade-out
    for (int brightness = 255; brightness >= 0; brightness -= 5) {
      analogWrite(ledPin, brightness);
      delay(10);
    }

    // Buzzer stays off
    digitalWrite(buzzerPin, LOW);
  }

  delay(100); // Buffer before next read
}
