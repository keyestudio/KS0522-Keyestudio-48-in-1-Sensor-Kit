# Lesson 30: Pressure Detection

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-29-voltage-detection.md) | [Course index](../README.md) | [Next lesson →](lesson-31-ambient-light.md) |
| --- | --- | --- |

![Project 30: Pressure Detection illustration](../media/313f11bf4a7f52ac903c78976fe1e633.jpeg)

## Description

This sensor adopts the new flexible nano pressure sensitive material with ultra thin film pad. It has the functions of water-proof and pressure detection.

When the sensor detects the outside pressure, the resistance of sensor will make a change.

So using the circuit, it can convert the pressure signal that senses pressure change into the corresponding electric signal output.

In this way, we can get the conditions of pressure changes by detecting the signal changes.

## Parameters

- Working Voltage：DC 3.3V—5V

- Range：0-10KG

- Thickness：＜0.25mm

- Response Point：＜20g

- Repeatability：＜±5.8%（50% load）

- Accuracy：±2.5%（85% range interval）

- Durability：＞100 thousand times

- Initial Resistance：＞100MΩ(no load)

- Response Time：＜1ms

- Recovery Time：＜15ms

- Working Temperature：﹣20℃—60℃

## Connection Diagram

Firstly you need to prepare the following parts before connection.

- V4.0 Board\*1

- Pressure sensor\*1

- USB Cable\*1

- Jumper Wire\*3

Connect the S pin of module to Analog A0 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.
![Connection Diagram illustration](../media/3325303180f71db75d9e13acc5036d8f.jpeg)

## Sample Code

Copy and paste the code below to Arduino software.

```c
///////////////////////////////////////////////////////////////
int s_pin = A0;
void setup()
{
  Serial.begin(9600);
  pinMode(s_pin,INPUT);

}

void loop()
{
  Serial.println(analogRead(s_pin));
  delay(500);
}
///////////////////////////////////////////////////////////////
```

## Example Result

Wiring well and uploading the code, open the serial monitor on Arduino software.

Then, press the sensor with your hand tightly, the value shown on the monitor is increasing.

![Example Result illustration](../media/a6c4be8596a0048cb5f3b2f1612241bd.png)

![Example Result illustration](../media/e055d2749b14c62b92c22496a3d1f96a.jpeg)

---

| [← Previous lesson](lesson-29-voltage-detection.md) | [Course index](../README.md) | [Next lesson →](lesson-31-ambient-light.md) |
| --- | --- | --- |
