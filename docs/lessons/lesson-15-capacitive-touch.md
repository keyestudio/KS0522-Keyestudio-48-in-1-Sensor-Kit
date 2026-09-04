# Lesson 15: Capacitive Touch

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 15: Capacitive Touch illustration](../media/bceabc7d4302bd41ae380e179a281314.png)

## Description

Are you tired of clicking mechanic buttons? Well, try our capacitive touch sensor. You can find touch sensors mostly used on electronic device. So upgrade your Arduino project with this touch sensor to make it more cool.

This little sensor can sense the touch of body and metal with feedback of a high/low voltage level. Even isolated by some cloth and papers, it can still feel the touch. But its sensitivity will decrease as isolation layer gets thicker.

We will make further improvement on those sensor modules to give you better experience.

## Specification

- Supply Voltage: 3.3V to 5V

- Interface: Digital

- Size: 30*20mm

- Weight: 3g

## Connection Diagram

First, you need to prepare the following parts before connection:

- V4.0 Board*1

- Capacitive touch sensor*1

- USB Cable*1

- Jumper Wire*3

Connect the S pin of module to Digital 2 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/18193a53377b60f43fb583c29337f3aa.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
const uint8_t ledPin = 13;  // On-board LED.
const uint8_t touchPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(touchPin, INPUT);
}

void loop() {
  const int touched = digitalRead(touchPin);
  digitalWrite(ledPin, touched == HIGH ? HIGH : LOW);
}
```

## Example Result

Done wiring and powered up, upload well the code, then touch the sensor with your finger, both D2 led on the sensor and D13 indicator on V4.0 board are on. Otherwise, those two indicators are turned off.

![Example Result illustration](../media/31a751feed0f21236458b93eed14af9f.png)

---
