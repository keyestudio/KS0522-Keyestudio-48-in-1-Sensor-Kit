# Lesson 09: Line -tracking Sensor

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 9: Line -tracking Sensor illustration](../media/c476ef922ab6a8d31cb68f3ab3fa2ced.png)

## Description

This Line Tracking Sensor can detect white line in black or black line in white.

The single line-tracking signal provides a stable output signal TTL for a more accurate and more stable line. Multi-channel option can be easily achieved by installing required line-tracking robot sensors.

## Specification

1. Power supply: +5V

2. Operating current: \<10mA

3. Operating temperature range: 0°C \~ + 50°C

4. Output interface: 3-wire interface (1 - signal, 2 - power, 3 - power supply negative)

5. Output Level: TTL level

## Connection Diagram

First, you need to prepare the following parts before connection:

- V4.0 Board\*1

- Line tracking module \*1

- USB Cable\*1

- Jumper Wire\*3

Connect the S pin of module to Digital 3 of V4.0 board, connect the GND pin to GND port, V+ pin to 5V port.

![Connection Diagram illustration](../media/6727a1d7d92c3878fc51b8db0502fd14.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
////////////////////////////////////////////////////////////////////
//Arduino Sample Code
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  Serial.println(digitalRead(3)); // print the data from the sensor
  delay(500);
}
////////////////////////////////////////////////////////////////////
```

## Example Result

![Example Result illustration](../media/af115c59987fee06447790f1740e3203.jpeg)

Done uploading the code to board, open the serial monitor and set the baud rate as 9600, then you can see the data from the sensor.

---
