# Lesson 13: Knock Sensor

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-12-hall-magnetic-sensor.md) | [Course index](../README.md) | [Next lesson →](lesson-14-digital-tilt-switch.md) |
| --- | --- | --- |

![Project 13: Knock Sensor illustration](../media/cef729e5b57059bc14518b0e2fdd2817.png)

## Description

This module is a knock sensor. When you knock it, it can send a momentary signal.

You can combine it with Arduino to make some interesting experiments, e.g. electronic drum

## Specification

- Working voltage: 5V

- Size: 30\*20mm

- Weight: 3g

## Connection Diagram

First, you need to prepare the following parts before connection:

- V4.0 Board\*1

- Knock sensor \*1

- USB Cable\*1

- Jumper Wire\*3

Connect the S pin of module to Digital 3 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/1b9c27f145275e7a38d06763114f1847.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
////////////////////////////////////////////////////////////////////
int Led=13;//define LED interface
int Shock=3;//define knock sensor interface
int val;//define digital variable val
void setup()
{
pinMode(Led,OUTPUT);//define LED to be output interface
pinMode(Shock,INPUT);//define knock sensor to be output interface
}
void loop()
{
val=digitalRead(Shock);//read the value of interface3 and evaluate it to val
if(val==HIGH)//when the knock sensor detect a signal, LED will be flashing
{
digitalWrite(Led,LOW);
}
else
{
digitalWrite(Led,HIGH);
}
}
////////////////////////////////////////////////////////////////////
```

![Sample Code illustration](../media/c3fc14de7267b517a739268ed5b88674.png)

## Example Result

Done wiring and powered up as above, upload well the code, then knock at the sensor, you will see both D13 led on the V4.0 board and D1 led on the sensor are turned on.

---

| [← Previous lesson](lesson-12-hall-magnetic-sensor.md) | [Course index](../README.md) | [Next lesson →](lesson-14-digital-tilt-switch.md) |
| --- | --- | --- |
