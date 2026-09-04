# Lesson 08: Collision Flash

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 8: Collision Flash illustration](../media/29c4641406064a4f1df5d59aefbca480.png)

## Description

Crash sensor, also known as electronic switch, is a digital on-off input module necessary for elementary electronic learning.

By programming, it can realize to control over light, sound device, key choice function of LCD display, etc.

Using 3P sensor cable to connect it to sensor shield, it can be installed to 4WD AL alloy mobile robot platform to realize collision detection function. It is both convenient and efficient.

You can make a collision flasher using collision module and built-in LED on interface 13. Connect the collision sensor to pin 3. When the collision sensor senses a collision signal, the LEDs on both main board and module will light up simultaneously.

## Parameters

1. If collision happens upfront of where collision module is installed, module outputs low level signal; no collision, outputs high level signal.

2. Module reserves M3 mounting hole, convenient for fixation on a car.

3. With switch indicator light, if there is collision, light is on; no collision, light is off.

## Pin definition

1. Positive pin (+): connect to 3v-12v power supply

2. Negative pin (-): connect to GND

3. Signal pin (S): connect to High-low level output

## Connection Diagram

First, you need to prepare the following parts before connection:

- V4.0 Board\*1

- Crash module \*1

- USB Cable\*1

- Jumper Wire\*3

Connect the S pin of module to Digital 3 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/a4ec0b7f8fd95fb2d6bb5c06ca0776f0.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
const uint8_t ledPin = 13;
const uint8_t collisionPin = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(collisionPin, INPUT);
}

void loop() {
  const int state = digitalRead(collisionPin);
  digitalWrite(ledPin, state == HIGH ? LOW : HIGH);
}
```

## Example Result

Wire it up well and then upload the code to the board.

When the object crashes the switch of sensor, both the led on the sensor and led 13 on the board are turned on.

---
