# IR Sensor with Faded Light Project

## Project Overview
This project uses an IR sensor to detect objects and responds by smoothly fading an LED on and off while activating a buzzer. It is implemented on an Arduino-compatible board using simple components.

---

## Pin Configuration

| Component    | Pin Number | Pin Type | Description                  |
|--------------|------------|----------|------------------------------|
| IR Sensor    | 2          | Input    | Detects presence of objects  |
| LED          | 3          | PWM Output | Smooth fading effect         |
| Buzzer       | 4          | Output   | Sound alert when object detected |

---

## Components Used and Requirements

- **IR Sensor**
  - Used to detect objects by sensing infrared light reflection.
  - Connect the sensor output to digital pin 2.
  - Requires power supply as per sensor specifications (usually 5V and GND).

- **LED**
  - Connected to PWM-capable pin 3 to allow smooth brightness control.
  - Use a current-limiting resistor (e.g., 220Ω) in series with the LED.
  - Connect LED anode to pin 3 and cathode to GND through resistor.

- **Buzzer**
  - Connected to digital pin 4.
  - Can be an active buzzer (with built-in oscillator) or passive buzzer.
  - Connect buzzer positive terminal to pin 4 and negative to GND.

- **Arduino Board**
  - Any Arduino board with at least 3 digital pins and PWM support on pin 3.
  - Power supply as per board requirements.

---

## Setup Instructions

### Hardware Setup
1. Connect the IR sensor output to digital pin 2 on the Arduino.
2. Connect the LED anode to digital pin 3 through a 220Ω resistor; connect the cathode to GND.
3. Connect the buzzer positive terminal to digital pin 4 and the negative terminal to GND.
4. Connect the Arduino board to your computer via USB.

### Software Setup
1. Open the Arduino IDE.
2. Load the `IR_SENCER_with_Faded_light.ino` file.
3. Select the correct board and port from the Tools menu.
4. Upload the sketch to the Arduino board.
5. Open the Serial Monitor at 9600 baud to view sensor state debugging output.

---

## Example Code File

The main project code is in the file: `IR_SENCER_with_Faded_light.ino`

```cpp
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
    // Smooth LED fade-out
    for (int brightness = 255; brightness >= 0; brightness -= 5) {
      analogWrite(ledPin, brightness);
      delay(10);
    }

    // Buzzer stays off
    digitalWrite(buzzerPin, LOW);
  }

  delay(100); // Buffer before next read
}
```

---

This documentation should help you set up and understand the IR Sensor with Faded Light project.
