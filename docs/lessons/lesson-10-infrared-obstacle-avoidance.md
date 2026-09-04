# Lesson 10: Infrared Obstacle Avoidance

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 10: Infrared Obstacle Avoidance illustration](../media/54ab9db703340471fd9c3151934b85e7.png)

## Description

Infrared obstacle detector sensor is equipped with distance adjustment function and is especially designed for wheeled robots.

This sensor has strong adaptability to ambient light and is of high precision.

It has a pair of infrared transmitting and receiving tube. When infrared ray launched by the transmitter tube encounters an obstacle (its reflector), the infrared ray will be reflected to the receiver tube, thus the indicator will light up, and signal output interface outputs digital signal.

In addition, you can rotate the potentiometer knob to adjust detection distance (effective distance: 2～40cm, working Voltage: 3.3V-5V ).

Thanks to a wide voltage range, this sensor can work steadily even under fluctuating power supply voltage, and is suitable for various micro-controllers, Arduino controllers and BS2 controllers.

A robot mounted with this sensor can sense obstacle in the environment.

## Specification

- Working voltage: DC 3.3V-5V

- Working current: ≥20mA

- Working temperature: －10℃ to＋50℃

- Detection distance: 2-40cm

- IO Interface: 4 wire interfaces (-/+/S/EN)

- Output signal: TTL voltage

- Accommodation mode: Multi-circle resistance regulation

- Effective Angle: 35°

## Connection Diagram

First, you need to prepare the following parts before connection:

- V4.0 Board\*1

- Obstacle detector module \*1

- USB Cable\*1

- Jumper Wire\*3

Connect the Out pin of module to Digital 2 of V4.0 board, connect the V+ pin to 5V port, GND pin to GND port.

![Connection Diagram illustration](../media/48f60a482d777df19bc43a3203479b0c.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
const uint8_t sensorPin = 2;
const uint8_t ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  const int sensorState = digitalRead(sensorPin);
  digitalWrite(ledPin, sensorState == HIGH ? HIGH : LOW);
}
```

## Example Result

Done uploading the code to board, you can see the led on both V4.0 board and obstacle detector sensor is turned on.

![Example Result illustration](../media/44d035dfe09b4c803becd84c95b05956.png)

If we put a foam block in front of the sensor, this time when sensor detects the obstacle, sled on the sensor will be turned on.

![Example Result illustration](../media/da4468fead816d42b2ac43b29716b91f.png)

---
