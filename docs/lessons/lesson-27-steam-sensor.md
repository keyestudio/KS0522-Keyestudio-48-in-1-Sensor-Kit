# Lesson 27: Steam Sensor

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

| [← Previous lesson](lesson-26-analog-alcohol.md) | [Course index](../README.md) | [Next lesson →](lesson-28-analog-ceramic-vibration.md) |
| --- | --- | --- |

![Project 27: Steam Sensor illustration](../media/d19ac9430f793cdbedde891ee92671e7.jpeg)

## Description

Steam sensor is an analog sensor and can be made as a simple rainwater detector and liquid level switch. When humidity on the face of this sensor rises, output voltage will increase.

Caution: connection parts is non-waterproof, so please don’t put them into water.

## Parameters

- Working Voltage: 3.3V or 5V

- Working Current: \<20mA

- Range of Working Temperature: －10℃～＋70℃

- Interface Type: Analog Signal Output

## Pin Definition

- S pin: for Signal Output

- Positive pin (+): for Power Supply (VCC)

- Negative pin (-): for Ground (GND)

## Connection Diagram

First, you need to prepare the following parts before connection:

- V4.0 board*1

- Steam sensor*1

- USB Cable*1

- Jumper wire*3

Connect the S pin of module to Analog A0 of V4.0 board, connect the negative pin to GND port, positive pin to 5V port.

![Connection Diagram illustration](../media/8fa51466dbc9650dcaa740bce4dd654e.jpeg)

## Sample Code

Copy and paste the below code to Arduino software.

```c
////////////////////////////////////////////////////////////////////
void setup()
{
Serial.begin(9600); //open serial port, and set baud rate at 9600bps
}
void loop()
{
int val;
val=analogRead(0); //plug vapor sensor into analog port 0
Serial.print("Moisture is ");
Serial.println(val,DEC); //read analog value through serial port printed
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Example Result

![Example Result illustration](../media/c4633c5911c042224d187645db4d0588.png)

When detecting different degrees of humidity, the sensor will get the feedback of different current value. Shown as the following picture.

Due to the limited condition, you can put a drop of water on the sensor, the moisture value will be changed on serial monitor of Arduino software.

![Example Result illustration](../media/80e9b3e19db4bec337f3254545a58e9e.jpeg)

---

| [← Previous lesson](lesson-26-analog-alcohol.md) | [Course index](../README.md) | [Next lesson →](lesson-28-analog-ceramic-vibration.md) |
| --- | --- | --- |
