# Lesson 01: White LED

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 1: White LED illustration](../media/6819f1c2047a7bb2b58e9cf0d7d3a617.jpeg)

## Description

This white LED light module is ideal for Arduino starters. It can be easily connected to IO/Sensor shield. It enables interaction with light-related works.

Note: You can choose other LED modules to emit different color like yellow, red, green and blue.

## Specification

- White LED module

- Type: Digital

- PH2.54 socket

- Size: 30\*20mm

- Weight: 3g

## Connection Diagram

First, you need to prepare the following parts before connection:

- V4.0 board\*1

- White LED module \*1

- USB Cable\*1

- Jumper wire\*3

Connect the S pin of module to Digital 3 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/cb67155c3b3cf25025edea5ae31d6c5f.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
const uint8_t ledPin = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
```

## Example Result

Done wiring and powered up, upload well the code, you will see the LED module emit the white light.

![Example Result illustration](../media/40448f38601a6312bfb1e3764be22158.png)

---

