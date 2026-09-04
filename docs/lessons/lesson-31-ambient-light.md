# Lesson 31: Ambient Light

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Project 31: Ambient Light illustration](../media/3eda1bbb84995dc2195a0406f1b0c196.jpeg)

## Description

At some point you are going to sense ambient brightness with better precision than your trusty photoresistor without adding complexity to your project. When that day comes, go get yourself a TEMT6000 ambient light sensor.

The TEMT6000 is supposed to be adapted to the sensitivity of the human eye, but found it preformed sub-par in low light conditions. It does however work very well reacting to very small changes in a large range of brightness. Because it is meant to mimic the human eye, it does not react well to IR or UV light, so just make sure to note that when using it in your project.

## Specification

- Supply Voltage: +5VDC 50mA

- Size: 36.5\*16mm

- Weight: 4g

## Connection Diagram

Firstly you need to prepare the following parts before connection.

- V4.0 Board\*1

- TEMT6000 ambient light sensor\*1

- USB Cable\*1

- Jumper Wire\*3

This is an incredibly simple part, just connect power and ground, and the signal pin to analog input port, if done connecting, the sensor will output analog voltage, that ramps up when it gets brighter. You can power it with 3.3V as you like, the output value will just be much lower.

![Connection Diagram illustration](../media/dae046a9efbeea661b9b6a2ab632fcbc.jpeg)

## Sample Code

You can not get more simpler than this – This just reports the reading value from the sensor to the serial terminal: 0-1023 with 1023 being very bright, and 0 being very dark.

```c
///////////////////////////////////////////////////////////////
int temt6000Pin = 0;
void setup() {
 Serial.begin(9600);
}
void loop() {
 int value = analogRead(temt6000Pin);
 Serial.println(value);
 delay(100); //only here to slow down the output so it is easier to read
}
///////////////////////////////////////////////////////////////
```

## Example Result

Wiring well and uploading the code above, open the serial monitor of Arduino software.

![Example Result illustration](../media/ea9ab82076983cc965fe016297b6ad76.png)

Then cover the sensor with your hand or a paper, the light becomes weak, finally you will see the value showed on monitor decreasing.

![Example Result illustration](../media/846828c9af69a9823ca7218157cc181e.jpeg)

---
