# Lesson 21: Photocell

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-20-analog-rotation.md) | [Course index](../README.md) | [Next lesson →](lesson-22-analog-sound.md) |
| --- | --- | --- |

![Project 21: Photocell illustration](../media/8eed60793fd64a7c0b9a9b2a2fc1ef67.png)

## Description

Photocell is commonly seen in our daily life and is mainly used in intelligent
switch, also in common electronic design. To make it easier and more effective,
we supply the corresponding modules.

Photocell is a semiconductor. It has features of high sensitivity, quick
response, spectral characteristic and R-value consistence, maintaining high
stability and reliability in environment extremely such as high temperature and
high humidity.

It’s widely used in automatic control switch fields like cameras, garden solar
lights, lawn lamps, money detectors, quartz clocks, music cups, gift boxes, mini
night lights, sound and light control switches, etc.

## Specification

- Interface type: analog

- Working voltage: 5V

- Size: 30*20mm

- Weight: 3g

## Connection Diagram

Connect the S pin of module to Analog A0 of V4.0 board, connect the negative pin
to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/28a1990cd088d6f0301f02d217cef301.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
////////////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}
void loop()
{
int val;
val=analogRead(0);//Read rotation sensor value from analog 0
Serial.println(val,DEC);//Print the value to serial port
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Example Result

![Example Result illustration](../media/78268e9cb1dbc127e7ae3299d3a35a45.png)

Done wiring and powered up, upload well the code, then open the serial monitor, if cover the photocell on the sensor with your hand, you will see the analog value decrease.

![Example Result illustration](../media/85621deb4c66d6e53697cd0ef90cb6e2.jpeg)

---

| [← Previous lesson](lesson-20-analog-rotation.md) | [Course index](../README.md) | [Next lesson →](lesson-22-analog-sound.md) |
| --- | --- | --- |
