# Lesson 35: Pulse Rate Monitor

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-34-digital-ir-transmitter.md) | [Course index](../README.md) | [Next lesson →](lesson-36-joystick.md) |
| --- | --- | --- |

![Project 35: Pulse Rate Monitor illustration](../media/0ec440cd93e00e956357ece654ce2a9c.png)

## Description

This module makes use of a ultra-clear infrared LED and a phototransistor to detect the pulse in your finger. The red LED will flash in time with your pulse.

Working principle

Shine the bright LED onto one side of your finger while the phototransistor on the other side of your finger picks up the amount of transmitted light. The resistance of the phototransistor will vary slightly as the blood pulses through your finger.

## Connection Diagram

Firstly you need to prepare the following parts before making a test.

- V4.0 Board\*1

- Pulse module\*1

- USB Cable\*1

- Jumper Wire\*3

Connect the Signal pin of module to Analog A0 of V4.0 board, the positive pin to 5V port, the negative pin to GND port.

![Connection Diagram illustration](../media/fa86e3930b83753af7ad87d0418cd350.jpeg)

## Sample Code

Copy and paste the code below to Arduino software.

```c
///////////////////////////////////////////////////////////////
int ledPin = 13;
int sensorPin = 0;
double alpha = 0.75;
int period = 20;
double change = 0.0;
void setup()
{
pinMode(ledPin, OUTPUT);
Serial.begin(115200);
}
void loop()
{
static double oldValue = 0;
static double oldChange = 0;
int rawValue = analogRead(sensorPin);
double value = alpha * oldValue + (1 - alpha) * rawValue;
Serial.print(rawValue);
Serial.print(",");
Serial.println(value);
oldValue = value;
delay(period);
}
///////////////////////////////////////////////////////////////
```

## Example Result

Wire it up well as the above diagram, then upload well the code to the board and click the icon of serial monitor on the upper right corner of Arduino software. Set the baud rate as 115200, you will see the data is displayed on the monitor.

You can copy and paste the data to the excel, finally it will generate the corresponding picture shown below.

![Example Result illustration](../media/3c3a1a0d120f1c68c95095a0fd98fa47.png)

![Example Result illustration](../media/215ab9a6174f9798a291bacb907eaf89.jpeg)

---

| [← Previous lesson](lesson-34-digital-ir-transmitter.md) | [Course index](../README.md) | [Next lesson →](lesson-36-joystick.md) |
| --- | --- | --- |
